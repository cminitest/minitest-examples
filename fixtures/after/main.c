#include <stdio.h>
#include "minitest/minitest.h"

int global_counter = 0;

define_fixture(after, after_all) {
  puts("This fixture will run last. \n");
  global_counter = 1;
}

define_fixture(after, after_nested) {
  puts("This fixture will run first. \n");
  global_counter++;
}

describe("after fixture", test_after_fixture)
  set_fixture(after, after_all)

  it("does not update the counter")
    expect(global_counter) to equal(0)
  end

  when("testing the fixture execution chain")
    set_fixture(after, after_nested)

    it("sets the proper counter")
      expect(global_counter) to equal(1)
    end
  end
end

int main(void) {
  minitest.run();
  minitest.clear(&minitest);
  return 0;
}