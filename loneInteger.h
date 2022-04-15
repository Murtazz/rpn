#ifndef __LONEINTEGER_H__
#define __LONEINTEGER_H__
#include <iostream>
#include <string>
#include <stdexcept>
#include "expression.h"

class LoneInteger: public Expression {
    int n;  // holds num
    public:
    LoneInteger(int n);
    ~LoneInteger() override;
    void set(std::string c, int n) override;
    void unset(std::string c) override;
    std::string prettyprint() override;
    int evaluate() override;
};

#endif