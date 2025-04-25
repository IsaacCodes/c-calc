# Recursive path names
shopt -s globstar

# Find all my .c files and convert to .h with cproto
for cfile in ./**/*.c; do
  echo "Processing: $cfile"

  if [[ $(basename "$cfile") == "main.c" ]]; then
    continue
  fi

  {
    echo "#pragma once"
    cproto -Iinclude "$cfile"
  } > "include/$(basename "$cfile" .c).h"
done

make && echo && ./build/main.out