#include "minitest/minitest.h"

int add_two_ints(int n1, int n2);

mt_mock_forwards(add_two_ints, int, int n1, int n2);
mt_define_mock(add_two_ints, mt_mock_args(n1,n2), int, int n1, int n2);

describe("been_called assertion", test_been_called_assertion)
  mock(add_two_ints) and_return(5)

  it("can check if false")
    #if LD_WRAP
      add_two_ints(2,2);
      expect(mock_calls(add_two_ints)) to have been_called
    #else
      __wrap_add_two_ints(2,2);
      expect(mock_calls(add_two_ints)) to have been_called
    #endif
  end

  release_mock(add_two_ints)

  mock(add_two_ints) and_return(6)

  it("can check if not false")
    #if LD_WRAP
      expect(mock_calls(add_two_ints)) to not have been_called
    #else
      expect(mock_calls(add_two_ints)) to not have been_called
    #endif
  end
end

int main(void) {
  minitest.run();
  minitest.clear(&minitest);
  return 0;
}