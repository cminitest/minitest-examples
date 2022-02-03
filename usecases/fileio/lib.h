#ifndef __LIB_H
#define __LIB_H 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct EmployeeStruct {
  char* name;
} Employee;

FILE* open_employee_record(char* file_name, char* mode);
ssize_t get_employee_row(char** line_buffer, size_t* len, FILE* employee_file);

FILE* __wrap_open_employee_record(char* file_name, char* mode);
ssize_t __wrap_get_employee_row(char** line_buffer, size_t* len, FILE* employee_file);

Employee* load_employee_record(char* file_name);

#endif