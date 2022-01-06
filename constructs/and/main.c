#include "minitest/minitest.h"

describe("and construct", test_and_construct)
  when("a when construct is called")
    and("and another scenario is described")
      it("is defined")
        expect(AND_TYPE) to equal(0x05)
      end
    end
  end
end

int main(void) {
  minitest.run();
  minitest.clear(&minitest);
  return 0;
}