#include <iostream>
#include <string>
#include <stdexcept>
#include "expression.h"
#include "unary.h"
using namespace std;

//ctor
Unary::Unary(Expression *exp, string uOp): exp{exp}, uOp{uOp} {}

Unary::~Unary() { //dtor: delete exp
    delete exp;
}

void Unary::set(std::string c, int n) { // go into exp and search for c to set to n
    exp->set(c, n);
}

void Unary::unset(std::string c) { // go into exp and search for c to unset
    exp->unset(c);
}

std::string Unary::prettyprint() { // prints exp enveloped in uOp (i.e. Unary Operation)
    if (uOp == "NEG") {
        return "-" + exp->prettyprint();
    } else if (uOp == "ABS") {
        return "|" + exp->prettyprint() + "|";
    } else {
        throw "Unary exception.";
    }
}

int Unary::evaluate() {
    if (uOp == "NEG") {
        return -(exp->evaluate());  
    } else if (uOp == "ABS") {
        return abs(exp->evaluate());  // used abs to get absolute value
    } else {
        throw "Unary Evaluation exception.";
    }
}
