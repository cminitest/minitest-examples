#include "testsuite.h"

// define the error formating function, returning a value appropriate for printf("%i")
int __format_extstruct(ExpectExt* extstruct) {
  return extstruct->value;
}

// define the __expect_extstruct function, comparing the value properties in the struct
mt_expect_ext(extstruct, ExpectExt*, (actual->value == expected->value), "%i");