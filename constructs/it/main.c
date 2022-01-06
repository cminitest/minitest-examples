#include "minitest/minitest.h"

describe("it construct", test_it_construct)
  it("can run in the describe context")
    expect(1) to equal(1)
  end

  context("within a context block")
    it("can run")
      expect(1) to equal(1)
    end    
  end

  given("an assertion is in a given block")
    it("can run")
      expect(1) to equal(1)
    end
  end

  when("an it block is defined inside a when construct")
    it("can run")
      expect(1) to equal(1)
    end

    and("an and construct is included")
      it("can run")
        expect(1) to equal(1)
      end
    end
  end
end

int main(void) {
  minitest.run();
  minitest.clear(&minitest);
  return 0;
}