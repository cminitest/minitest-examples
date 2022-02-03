#include "test.h"

mt_mocks_initialize(
  mt_mock_parameter_handles(),
  mt_mock_assert_parameters()
)

mt_define_mock(mt_returns, FILE*, open_employee_record, 2,
  mt_mock_arg_signature(char*, char*),
  mt_mock_arg_names(file_name,mode),
  char* file_name, char* mode
)

mt_define_mock(mt_returns, ssize_t, get_employee_row, 3,
  mt_mock_arg_signature(char**, size_t*, FILE*),
  mt_mock_arg_names(line_buffer,len,employee_file),
  char** line_buffer, size_t* len, FILE* employee_file
)

void spy_on_get_employee_row(char*** buffer, size_t** len, FILE** f) {
  **buffer = malloc(sizeof(char)*7);
  strcpy(**buffer, "Bender\0");
  **len = (unsigned long)(7);
}
