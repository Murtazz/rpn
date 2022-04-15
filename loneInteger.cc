#include <vector>
#include <iostream>
#include <string>
#include <stdexcept>
#include "expression.h"
#include "loneInteger.h"
using namespace std;

LoneInteger::LoneInteger(int n): n{n} {}  // ctor

LoneInteger::~LoneInteger() {}  // dtor

void LoneInteger::set(string c, int n) {} // does nothing

void LoneInteger::unset(string c) {} // does nothing

std::string LoneInteger::prettyprint() { // prints num to stdout
    return to_string(n);  
}

int LoneInteger::evaluate() {return n;} // returns the num
