#include "minitest/minitest.h"

typedef struct PersonStruct {
  int age;
} Person;

describe("be_null assertion", test_be_null_assertion)
  Person fry = { .age = 3000 };

  it("can check if null")
    expect(NULL) to be_null
  end

  it("can check if not null")
    expect((void*)(&fry)) to not be_null
  end
end

int main(void) {
  minitest.run();
  minitest.clear(&minitest);
  return 0;
}