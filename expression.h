#ifndef __EXPRESSION_H__
#define __EXPRESSION_H__
#include <iostream>
#include <string>
#include <stdexcept>

class Expression {  // pure virtual
  public:
    virtual void set(std::string c, int n) = 0;
    virtual void unset(std::string c) = 0;
    virtual std::string prettyprint() = 0;
    virtual int evaluate() = 0;
    virtual ~Expression() = 0;
};

#endif