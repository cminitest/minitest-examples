#include "minitest/minitest.h"

describe("given construct", test_given_construct)
  given("when a given construct is called")
    and("and another scenario is described")
      it("is defined")
        expect(GIVEN_TYPE) to equal(0x04)
      end
    end
  end
end

int main(void) {
  minitest.run();
  minitest.clear(&minitest);
  return 0;
}