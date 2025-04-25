#pragma once
/* standalone */

#include <stdint.h>

//Specifier: %hhd
//Range: -128 to 127
typedef int8_t i8;

//Specifier: %hhu
//Range: 0 to 255
typedef uint8_t u8;

//Specifier: %hd
//Range: -32768 to 32767
typedef int16_t i16;

//Specifier: %hu
//Range: 0 to 65535
typedef uint16_t u16;

//Specifier: %d
//Range: -2147483648 to 2147483647
typedef int32_t i32;

//Specifier: %u
//Range: 0 to 4294967295
typedef uint32_t u32;

//Specifier: %ld
//Range: -9223372036854775808 to 9223372036854775807
typedef int64_t i64;

//Specifier: %lu
//Range: 0 to 18446744073709551615
typedef uint64_t u64;


//Specifier: %f or %e
//Range: 1.2e-38 to 3.4e38
typedef float f32;

//Specifier: %lf or %e
//Range: 2.2e-308 to 1.8e308
typedef double f64;

//Specifier: %lf or %e
//Range: 1.2e-38 to 3.4e38
typedef float f32;
