#include <iostream>
#include <string>
#include <stdexcept>
#include "expression.h"
#include "binary.h"
using namespace std;

// ctor
Binary::Binary(Expression *exp, Expression *exp2, string bOp): exp{exp}, exp2{exp2}, bOp{bOp} {}

Binary::~Binary() {  // dtor: delete both exp
    delete exp;
    delete exp2;
}

void Binary::set(string c, int n) { // go into exp and exp2 and search for c to set to n
    exp->set(c, n);
    exp2->set(c, n);
}

void Binary::unset(string c) { // go into exp and exp2 and search for c to unset 
    exp->unset(c);
    exp2->unset(c);
}


std::string Binary::prettyprint() {  // prints in brackets
    return "(" + exp->prettyprint() + " " + bOp + " " + exp2->prettyprint() + ")";
}

int Binary::evaluate() {
    int x = exp->evaluate();
    int y = exp2->evaluate();
    if (bOp == "-") {
        return x - y;
    } else if (bOp == "+") {
        return x + y;
    } else if (bOp == "*") {
        return x * y;
    } else if (bOp == "/") {
        if (y == 0) {
            throw "Floating point exception"; // mimics error received from C++ when dividing by 0
        }
        return x / y;
    } else {
        throw "Exception: not a valid Binary Operation";  // not one of the 4 binary ops
    }
}
