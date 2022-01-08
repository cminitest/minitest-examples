#include "minitest/minitest.h"

describe("in_range assertion", test_range_assertion)
  it("can check if in range")
    expect(1) to be in_range(0,1)
  end

  it("can check if not in range")
    expect(5) to not be in_range(0,2)
  end
end

int main(void) {
  minitest.run();
  minitest.clear(&minitest);
  return 0;
}