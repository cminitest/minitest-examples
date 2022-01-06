#include "minitest/minitest.h"

describe("when construct", test_when_construct)
  when("a when construct is called")
    it("is defined")
      expect(WHEN_TYPE) to equal(0x06)
    end
  end
end

int main(void) {
  minitest.run();
  minitest.clear(&minitest);
  return 0;
}