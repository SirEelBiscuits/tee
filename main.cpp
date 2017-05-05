#include "tee.hpp"
#include <iostream>

Tee_Test(test_one_plus_one_is_two_succeeds) {
	assert(1 + 1 == 2);
}

Tee_Test(test_one_plus_one_is_three_fails) {
	assert(1 + 1 == 3);
}

Tee_Test(failing_one_assert_when_testing_two_produces_one_error) {
	assert(2 + 2 == 4);
	assert(2 + 2 == 5);
};

Tee_Test(failed_test_fails) {
	assert(false);
}

int main() {
	TestsHolder::Instance().RunAllTests();
	auto fails = TestsHolder::Instance().GetFails();
	for(auto f : fails)
		std::cout << f;

	std::cout << TestsHolder::Instance().GetSuccesses() << " successes, "
		<< fails.size() << " failures (3 expected).";
	return fails.size() == 3 ? EXIT_SUCCESS : EXIT_FAILURE;
}
