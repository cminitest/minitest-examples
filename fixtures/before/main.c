#include <stdio.h>
#include "minitest/minitest.h"

int global_counter = 0;

define_fixture(before, before_all) {
  puts("This fixture will run first. \n");
  global_counter = 1;
}

define_fixture(before, before_nested) {
  puts("This fixture will run last. \n");
  global_counter++;
}

describe("before fixture", test_before_fixture)
  before(before_all)

  it("initializes the counter")
    expect(global_counter) to equal(1)
  end

  when("testing the fixture execution chain")
    before(before_nested)

    it("sets the proper counter")
      expect(global_counter) to equal(2)
    end
  end
end

int main(void) {
  minitest.run();
  minitest.clear(&minitest);
  return 0;
}