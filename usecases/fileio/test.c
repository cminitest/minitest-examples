#include "test.h"

define_fixture(before, before_all) {
  FixtureState* state = malloc(sizeof(FixtureState));
  state->mock_file = malloc(1);
  state->employee = NULL;
  *subject = state;

  mock(open_employee_record) and_return(state->mock_file)
  mock(get_employee_row) and_return(7)
  spy(get_employee_row) through(spy_on_get_employee_row)
}

define_fixture(after, after_all) {
  FixtureState* state = *subject;
  free(state->mock_file);

  if(state->employee != NULL) {
    free(state->employee->name);
    free(state->employee);
    state->employee = NULL;
  }

  free(state);
  *subject = NULL;

  reset(open_employee_record)
  reset(get_employee_row)
}

define_fixture(before, load_employee_record) {
  FixtureState* state = *subject;
  state->employee = load_employee_record("test.txt");
}

describe("Employee Records", test_employees)

  before(before_all)
  after(after_all)

  context("open_employee_record")
    it("initializes a new FILE pointer")
      expect((void*)__wrap_open_employee_record("test.txt", "r")) to equal(
        ((FixtureState*)subject())->mock_file
      )
    end
  end

  context("get_employee_row")
    it("loads the employee information into the buffer")
      char* buffer = NULL;
      size_t len = 0;
      expect(
        __wrap_get_employee_row(&buffer, &len, ((FixtureState*)subject())->mock_file)
      ) to equal(7)
      expect(buffer) to equal("Bender")
      expect(len) to equal(7)
    end
  end

  context("load_employee_record")
    when("data is read from the file")
      before(load_employee_record)

      it("opens the employee record file")
        expect(mock(open_employee_record)->request) to have been called_with("test.txt", "r")
      end

      it("reads the employee information from the file")
        expect(mock(get_employee_row)->request) to have been_called
      end

      it("creates the employee record")
        expect(
          ((FixtureState*)subject())->employee->name
        ) to equal("Bender")
      end
    end
  end
end

int main(void) {
  //minitest.log_level = MT_LOG_DEBUG;
  minitest.run();
  minitest.clear(&minitest);
  minitestmocks.clear(&minitestmocks, mt_free_mocks);
  return 0;
}