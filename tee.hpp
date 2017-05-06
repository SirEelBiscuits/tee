#include <vector>
#include <string>
#include <tuple>

class Tee {
public:
	class TestInterface {
		public:
			virtual void Run() = 0;
			virtual std::string GetName() const = 0;
	};

	class TestsHolder {
		public:
			static TestsHolder& Instance() {
				static TestsHolder o{};
				return o;
			}

			void AddTest(TestInterface& test) {
				tests.push_back(&test);
			}

			void AddFail(std::string fail) {
				fails.emplace_back(fail);
			}

			void AddSuccess() {
				++successCount;
			}

			void RunAllTests() {
				for(auto t : tests)
					t->Run();
			}

			std::vector<std::string> const& GetFails() const {
				return fails;
			}

			int GetSuccesses() const {
				return successCount;
			}

		private:
			std::vector<TestInterface*> tests {};
			std::vector<std::string> fails {};
			int successCount{};
	};

	static std::pair<int, std::vector<std::string>> RunAllTests() {
		TestsHolder::Instance().RunAllTests();
		return std::make_pair(
			TestsHolder::Instance().GetSuccesses(),
			TestsHolder::Instance().GetFails()
		);
	}
};

#define Tee_Test(name) \
	class Test_##name : public Tee::TestInterface { \
		public: \
			Test_##name() { \
				Tee::TestsHolder::Instance().AddTest(*this); \
			} \
			std::string GetName() const override { return #name; } \
			void Run() override; \
	}; \
	static Test_##name Instance_##name; \
	void Test_##name::Run()

#define S(x) #x
#define S_(x) S(x)
#define S__LINE__ S_(__LINE__)

#define assert(condition) \
	if(condition != true) { \
		Tee::TestsHolder::Instance().AddFail( \
				__FILE__ "(" S__LINE__ "): " \
				+ GetName() + " - " + #condition + "\n"); \
	} else Tee::TestsHolder::Instance().AddSuccess();

