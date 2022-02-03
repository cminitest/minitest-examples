#ifndef __MINITEST_TESTSUITE_H__
#define __MINITEST_TESTSUITE_H__ 1

#include "minitest/setup.h"

// define any structures and MT_EXPECT_EXT before loading minitest.h

typedef struct ExpectExtStruct {
  int value;
} ExpectExt;

mt_setup_expect_forwards(
  mt_expect_forward(extstruct, ExpectExt*)
)

#define MT_EXPECT_EXTENSIONS mt_setup_expect_extensions( \
  mt_expect_extension(extstruct, ExpectExt*)             \
)

#include "minitest/minitest.h"

#endif