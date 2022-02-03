#include "minitest/setup.h"

int add_two_ints(int n1, int n2);

mt_setup_mocks(
  mt_param_extensions(),
  mt_setup_mock_forwards(
    mt_mock_forward(mt_returns, int, add_two_ints, int, int)
  )
)

#include "minitest/minitest.h"

mt_mocks_initialize(
  mt_mock_parameter_handles(),
  mt_mock_assert_parameters()
)

mt_define_mock(mt_returns, int, add_two_ints, 2,
  mt_mock_arg_signature(int, int),
  mt_mock_arg_names(n1,n2),
  int n1, int n2
)

describe("been_called assertion", test_been_called_assertion)
  mock(add_two_ints) and_return(5)

  it("can check if false")
    #if LD_WRAP
      add_two_ints(2,2);
      expect(mock(add_two_ints)->request) to have been_called
    #else
      __wrap_add_two_ints(2,2);
      expect(mock(add_two_ints)->request) to have been_called
    #endif
  end

  reset(add_two_ints)

  mock(add_two_ints) and_return(6)

  it("can check if not false")
    #if LD_WRAP
      expect(mock(add_two_ints)->request) to not have been_called
    #else
      expect(mock(add_two_ints)->request) to not have been_called
    #endif
  end
end

int main(void) {
  //minitest.log_level = MT_LOG_DEBUG;
  minitest.run();
  minitest.clear(&minitest);
  minitestmocks.clear(&minitestmocks, mt_free_mocks);
  return 0;
}