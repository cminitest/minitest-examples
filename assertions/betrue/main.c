#include "minitest/minitest.h"

describe("be_true assertion", test_be_true_assertion)
  it("can check if truthy")
    expect(1) to be_true
  end

  it("can check if not truthy")
    expect(0) to not be_true
  end
end

int main(void) {
  minitest.run();
  minitest.clear(&minitest);
  return 0;
}