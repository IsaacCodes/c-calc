for cfile in source/*.c; do
  if [[ "$cfile" == "source/main.c" ]]; then
    continue
  fi

  header_name="include/$(basename "$cfile" .c).h"
  {
    echo "#pragma once"
    cproto -Iinclude "$cfile"
  } > "$header_name"
done

make && echo && ./build/main.out