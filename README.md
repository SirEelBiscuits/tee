Tee
===

TDD++

A simple testing framework for C++

Author
------

J Thatcher - @SirEelBiscuits

Usage
-----

### Defining a test

```cpp
Tee_Test(name_of_test_here) {
  //do stuff
  assert(someCondition());
}
```

The name of the test given must be unique. You may have any number of assertions per test.

### Testing the defined tests

See the [code](main.cpp)!

### Integrating with a project

Just include the header file wherever you want to write tests. Nothing else is needed.

Known Issues
------------

none
