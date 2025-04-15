#pragma once
/* standalone */

#include <stdint.h>

//-2^-31 (-2,147,483,648) to 2^31-1 (2,147,483,647) %d
typedef long i32;
//0 to 2^32-1 (4,294,967,295) %lu
typedef unsigned long u32;
//-2^63 (9.223372e+18) to 2^63-1 (9.223372e+18) %lld
typedef long long i64;
//0 to 2^63-1 (1.8446744e+19) %llu
typedef unsigned long long u64;
//-1.175494e-38 (abt 2^127) to 3.402823e+38 (abt 2^128) %f or %e
typedef float f32;
//-2.225074e-308 (abt 2^1024) to 2.225074e-308 (abt 2^1024) %lf or %E
typedef double f64;
