/*
 * Working docs
 *
 * Ideal usecase:
 *
 * Test(groupname, testname) {
 *	check a thing
 *	return TEST_SUCCESS;
 * }
 */

#include <vector>
#include <string>

class TestInterface {
	virtual void Run() = 0;
	virtual std::string GetName() const = 0;
};

class TestsHolder {
	public:
		static TestsHolder& Instance() {
			static TestsHolder o{};
			return o;
		}

		void AddTest(Test& test) {
			tests.push_back(&test);
		}

		void AddFail(std::string fail) {
			fails.emplace_back(fail);
		}

		void RunAllTests() {
			for(auto t : tests)
				t->Run();
		}

		std::vector<std::string const> const& GetFails() {
			return fails;
		}

	private:
		std::vector<Test*> tests {};
		std::vector<std::string> fails {};
};

#define Tee_Test(name)                                 \
	class Test_#name : public TestInterface {            \
		public:                                            \
			Test_#name() {                                   \
				TestsHolder.Instance().AddTest(*this);         \
			}                                                \
			std::string GetName() override { return #name; } \
			void Run() override;                             \
	}                                                    \
	void Test_#name::Run()

#define assert(condition)           \
	if(condition != true) {           \
		TestsHolder.Instance().AddFail( \
				__FILE__ "(" __LINE__ "): " \
				+ GetName + "-" condition); \
	}                                 \
