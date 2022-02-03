#include "lib.h"

FILE* open_employee_record(char* file_name, char* mode) {
  return fopen(file_name, mode);
}

ssize_t get_employee_row(char** line_buffer, size_t* len, FILE* employee_file) {
  return getline(line_buffer, len, employee_file);
}

Employee* load_employee_record(char* file_name) {
  FILE* fp = __wrap_open_employee_record(file_name, "r");
  char* buffer = NULL;
  size_t len = 0;

  if (fp == NULL) {
    return NULL;
  }

  if(__wrap_get_employee_row(&buffer, &len, fp) != -1) {
    Employee* record = malloc(sizeof(Employee));
    record->name = buffer;
    // create a function to close the employee file / mock it out
    return record;
  }

  // create a function to close the employee file / mock it out

  return NULL;
}