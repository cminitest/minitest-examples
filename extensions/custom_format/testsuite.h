#ifndef __MINITEST_TESTSUITE_H__
#define __MINITEST_TESTSUITE_H__ 1

// define any structures and MT_EXPECT_EXT before loading minitest.h

typedef struct ExpectExtStruct {
  int value;
} ExpectExt;

#define MT_EXPECT_EXT \
  mt_register_expect_extension(extstruct, ExpectExt*)

#include "minitest/minitest.h"

// create the forward expect function, matching the function identifier in MT_EXPECT_EXT
mt_expect_forward(extstruct, ExpectExt*);

#endif