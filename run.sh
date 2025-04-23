for cfile in source/*.c; do
  if [[ "$cfile" == "source/main.c" ]]; then
    continue
  fi

  {
    echo "#pragma once"
    cproto -Iinclude "$cfile"
  } > "include/$(basename "$cfile" .c).h"
done

make && echo && ./build/main.out