Tee
===

TDD++

A simple testing framework for C++

Author
------

J Thatcher - @SirEelBiscuits - jameson@bluescreenofdoom.com

Prerequisites
-------------

- A C++11 compatible compiler.

Otherwise Tee only depends on the standard library.
Tee has been tested with g++ 5.4 and 6.3. 

Usage
-----

### Defining a test

```cpp
Tee_Test(name_of_test_here) {
  //do stuff
  assert(someCondition());
}
```

The name of the test given must be unique. You may have any number of
assertions per test.

### Testing the defined tests

```cpp
#include <vector>
#include <string>
#include <tuple>
#include "tee.hpp"

int main() {
	int successes;
	vector<string> fails;
	tie(successes, fails) = Tee::RunAllTests();
	for(auto f : fails)
		cout << f;
	cout << successes << " successes, " << fails.size() << " failures." << endl;
	return fails.size() == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}

```

See the [code](main.cpp) for a version with testable tests!

### Integrating with a project

Just include the header file wherever you want to write tests. Nothing else
is needed.

Building Tests
--------------

The included tests can be run simply by compiling main.cpp.
It has been tested with g++ version 5.4.
You might build it with the command `g++ main.cpp -std=c++14 -o tee`.

Future Work
-----------

- Have `Tee_Test` disableable with a `#define`
- Add test groups

Known Issues
------------

none
