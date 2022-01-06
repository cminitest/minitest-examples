#include "minitest/minitest.h"

describe("context construct", test_context_construct)
  context("definition")
    it("is defined")
      expect(CONTEXT_TYPE) to equal(0x03)
    end
  end
end

int main(void) {
  minitest.run();
  minitest.clear(&minitest);
  return 0;
}