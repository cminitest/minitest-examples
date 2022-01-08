#include "minitest/minitest.h"

describe("greater than assertion", test_ge_assertion)
  it("can check if greater than")
    expect(1) to be greater_than(0)
  end

  it("can check if not greater than")
    expect(0) to not be greater_than(1)
  end
end

int main(void) {
  minitest.run();
  minitest.clear(&minitest);
  return 0;
}