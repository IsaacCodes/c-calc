#!/bin/bash
set -e

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

echo "Generated prototypes"

debug_mode=0
compile_only=0
prototype_only=0

while getopts 'dcp' flag; do
  case $flag in
  d) debug_mode=1;;
  c) compile_only=1;;
  p) prototype_only=1;;
  esac
done

if [[ $debug_mode == 1 ]]; then
  make && gdb ./build/main.out
elif [[ $compile_only == 1 ]]; then
  make
elif [[ $prototype_only == 1 ]]; then
  :
else
  make && echo && ./build/main.out
fi