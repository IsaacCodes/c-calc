# Recursive path names
shopt -s globstar

# Find all my .c files and convert to .h with cproto
for src_file in ./**/*.c; do

  base_name=$(basename "$src_file" .c)
  target_dir=$(dirname "$src_file")
  target_dir="${target_dir/source/include}"
  header_file="$target_dir/$base_name.h"

  if [[ $base_name == "main" ]]; then
    continue
  fi

  # Preserve user defined portions of the header
  if [[ -f "$header_file" ]]; then
    user_section=$(awk '/\/\/ Auto Generated/ {exit} {print}' "$header_file")
  else
    user_section="#pragma once\n\n// User Defined\n//..."
  fi

  auto_section="// Auto Generated\n$(cproto -Iutils/include -Iproject/include "$src_file")"

  #Generate full header
  echo -e "$user_section\n\n$auto_section" > "$header_file"
done

#Maybe add some kinda -c flag for when only wanting to compile

make && echo && ./build/main.out