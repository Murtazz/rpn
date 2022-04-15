#ifndef __VARIABLE_H__
#define __VARIABLE_H__
#include <iostream>
#include <string>
#include <stdexcept>
#include "expression.h"

class Variable: public Expression {
    int num;  // can hold num
    std::string var; // holds variable denoted as a string
    bool fixed;  // true if holding number and false if holding an unset variable
    public:
    Variable(int num, std::string var, bool fixed);
    ~Variable();
    void set(std::string c, int n) override;
    void unset(std::string c) override;
    std::string  prettyprint() override;
    int evaluate() override;
};

#endif
