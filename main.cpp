#include "tee.hpp"
#include <iostream>

Tee_Test(test_one_plus_one_is_two_succeeds) {
	std::cout << GetName() << " running" << std::endl;
	assert(1 + 1 == 2);
}

Tee_Test(test_one_plus_one_is_three_fails) {
	std::cout << GetName() << " running" << std::endl;
	assert(1 + 1 == 3);
}

Tee_Test(failing_one_assert_when_testing_two_produces_one_error) {
	std::cout << GetName() << " running" << std::endl;
	assert(2 + 2 == 4);
	assert(2 + 2 == 5);
}

Tee_Test(failed_test_fails) {
	std::cout << GetName() << " running" << std::endl;
	assert(false);
}

Tee_Test(test_sub_tests) {
	std::cout << GetName() << " running" << std::endl;

	Tee_SubTest(sub_test_one_success) {
		std::cout << GetName() << " running" << std::endl;
		assert(true);
	}

	Tee_SubTest(sub_test_two_success) {
		std::cout << GetName() << " running" << std::endl;
		assert(3 + 3 == 6);
	}

	Tee_SubTest(sub_test_three_fails) {
		std::cout << GetName() << " running" << std::endl;
		assert(false && "what");
	}
}

int main() {
	int successes;
	std::vector<std::string> fails;
	std::tie(successes, fails) = Tee::RunAllTests();
	for(auto f : fails)
		std::cout << f;

	std::cout << successes << " successes, "
		<< fails.size() << " failures (4 expected)." << std::endl;
	return fails.size() == 4 ? EXIT_SUCCESS : EXIT_FAILURE;
}
