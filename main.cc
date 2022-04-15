#include <iostream>
#include <utility>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "expression.h"
#include "loneInteger.h"
#include "variable.h"
#include "binary.h"
#include "unary.h"

using namespace std;

istream &operator>>(istream &in, Expression *&exp) {
    vector <Expression *> vex;
    
    string s;
    while(in >> s) {
        int n;
        istringstream iss{s};
        if (s == "done") {
            exp = vex.back();
            vex.pop_back();
            cout << exp->prettyprint() << endl;
            break; 
        } else if (iss >> n) {
            LoneInteger *p = new LoneInteger{n};
            vex.emplace_back(p);
        } else if (s == "NEG" || s == "ABS") {
            Expression *prev = vex.back();
            vex.pop_back();
            Unary *p = new Unary{prev, s};
            vex.emplace_back(p);
        } else if (s == "-" || s == "*" || s == "+" || s == "/") {
            Expression *prev = vex.back();
            vex.pop_back();
            Expression *prev2 = vex.back();
            vex.pop_back();
            Binary *p = new Binary{prev2, prev, s}; 
            vex.emplace_back(p);
        } else {
            Variable *p = new Variable{0, s, false};
            vex.emplace_back(p);
        }
    }
    return in;
}

int main() {
    string eStr;
    Expression *calc;
    cin >> calc;
    while (cin >> eStr) {
        if (eStr == "set") {
            string st;
            int n;
            cin >> st;
            cin >> n;
            calc->set(st, n);
        } else if (eStr == "eval") {
            try {
                int total = calc->evaluate();
                cout << total << endl;
            } catch (string s) {
                cout << s << endl;
            }
        } else if (eStr == "unset") {
            string ust;
            cin >> ust;
            calc->unset(ust);
        } else if (eStr == "print") {
            cout << calc->prettyprint() << endl;
        }
    }
    delete calc;
}