#include <iostream>
#include <string>
#include <stdexcept>
#include "expression.h"
#include "variable.h"
using namespace std;

// ctor
Variable::Variable(int num, string var, bool fixed): num{num}, var{var}, fixed{fixed} {}

Variable::~Variable() {} // dtor

void Variable::set(string c, int n) { 
    if (c == var) {  // set if c == var
        num = n;
        fixed = true;  // var is now a number
    }   
}

void Variable::unset(string c) {
    if (c == var) {
        fixed = false; // var is now an unset variable
    }
}

std::string Variable::prettyprint() {
    if (fixed) {
        return to_string(num); // return num if fixed true
    } else {
        return var; // return var otherwise
    }
}

int Variable::evaluate() {
    if (fixed) {  
        return num; // return number if true
    } else {
        string errorMsg = var + " has no value."; // create error message
        throw errorMsg;  // throw exception
    }
}
