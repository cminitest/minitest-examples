#include "minitest/minitest.h"

describe("equal assertion", test_equal_assertion)
  it("can check if equal")
    expect(1) to equal(1)
  end

  it("can check if not equal")
    expect(1) to not equal(0)
  end
end

int main(void) {
  minitest.run();
  minitest.clear(&minitest);
  return 0;
}