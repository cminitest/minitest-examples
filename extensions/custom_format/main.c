#include "testsuite.h"

describe("MiniTest", minitest_extensions)
  context("Extensions")
    ExpectExt subject = { .value = 1 };
    it("creates the expectation for the extension")
      ExpectExt comp = { .value = 1 };
      expect(&subject) to equal(&comp)
      comp.value = 2;
      expect(&subject) to not equal(&comp)
    end
  end
end

int main(void) {
  minitest.run();
  minitest.clear(&minitest);
  return 0;
}