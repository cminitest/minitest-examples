#include "minitest/minitest.h"

describe("equal assertion", test_equal_assertion)
  it("can check if equal")
    expect(1) to equal(1)
  end

  it("can check if not equal")
    expect(1) to not equal(0)
  end

  context("arrays")
    int x[] = {1,5,2};

    it("can check if equal")
      int y[] = {2,5,1};
      expect(x) to equal(y)
    end
  
    it("can check if not equal")
      int y[] = {1,5,5};
      expect(x) to not equal(y)
    end
  end
end

int main(void) {
  minitest.run();
  minitest.clear(&minitest);
  return 0;
}