#ifndef __BINARY_H__
#define __BINARY_H__
#include <iostream>
#include <string>
#include <stdexcept>
#include "expression.h"

class Binary: public Expression {
    Expression *exp;
    Expression *exp2;  // holds 2 Expressions for exp bOp exp2 (e.g. 1 + 2 or (1 + 2) * (3 + 2))
    std::string bOp;   // holds the binary operation (i.e. "+", "-", "*", or"/")
    public:
    Binary(Expression *exp, Expression *exp2, std::string bOp);
    ~Binary();
    void set(std::string c, int n) override;
    void unset(std::string c) override;
    std::string prettyprint() override;
    int evaluate() override;
};

#endif