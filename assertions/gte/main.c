#include "minitest/minitest.h"

describe("greater than or equal to assertion", test_gte_assertion)
  it("can check if greater than")
    expect(1) to be greater_than_or_equal_to(0)
  end

  it("can check if equal to")
    expect(1) to be greater_than_or_equal_to(1)
  end

  it("can check if not greater than or equal to")
    expect(0) to not be greater_than_or_equal_to(1)
  end
end

int main(void) {
  minitest.run();
  minitest.clear(&minitest);
  return 0;
}