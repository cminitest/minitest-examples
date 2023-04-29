#include "testsuite.h"

// define the error formating function, returning a value appropriate for printf("%i")
int __format_extstruct(ExpectExt* extstruct) {
  return extstruct->value;
}

int __assert_array_extstructarr(ExpectExt* arr_1[], ExpectExt* arr_2[], size_t s1, size_t s2) {
  if (s1/sizeof(ExpectExt*) != s2/sizeof(ExpectExt*)) { return 0; }
  return 1;
}

// define the __expect_extstruct function, comparing the value properties in the struct
mt_expect_ext(extstruct, ExpectExt*, (actual->value == expected->value), "%i");

// using ext_default for a NOOP printf format statement
mt_expect_array_ext_default(extstructarr, ExpectExt*, __assert_array_extstructarr(expected, actual, actual_size, expected_size), NULL);