#ifndef __TEST_H
#define __TEST_H 1

#include "lib.h"
#include "minitest/setup.h"

mt_setup_expect_forwards()

#define MT_EXPECT_EXTENSIONS mt_setup_expect_extensions()

mt_setup_mocks(
  mt_param_extensions(),
  mt_setup_mock_forwards(
    mt_mock_forward(mt_returns, FILE*, open_employee_record, char*, char*)
    mt_mock_forward(mt_returns, ssize_t, get_employee_row, char**, size_t*, FILE*)
  )
)

void spy_on_get_employee_row(char***, size_t**, FILE**);

typedef struct FixtureStateStruct {
  void* mock_file;
  Employee* employee;
} FixtureState;

#include "minitest/minitest.h"

#endif