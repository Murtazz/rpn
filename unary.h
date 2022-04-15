#ifndef __UNARY_H__
#define __UNARY_H__
#include <iostream>
#include <string>
#include <stdexcept>
#include "expression.h"

class Unary: public Expression {
    Expression *exp; // envelops one Expression
    std::string uOp; // holds unary operation (i.e. "ABS" or "NEG")
    public:
    Unary(Expression *exp, std::string uOp);
    ~Unary();
    void set(std::string c, int n) override;
    void unset(std::string c) override;
    std::string prettyprint() override;
    int evaluate() override;
};

#endif