#include "evaluator.h"
#include <stack>
#include <cmath>

using std::stack;
using std::stod;
using std::abs;

double Evaluate(const string& postfix, bool& error){
    stack<double> digits;
    double result;
    double int1;
    double int2;
    double value;
    int spaceCount = 0;
    string num;

    error = false;
    for(int i = 0; i < postfix.size(); i++) {
        if(postfix.at(i) == ' ') {
            spaceCount++;
            continue;
        }
        else if(isdigit(postfix.at(i))) {
            num = "";
            while(isdigit(postfix.at(i))) {
                num += postfix.at(i);
                i++;
            }
            i--;
            digits.push(stod(num));
        }
        else if(postfix.at(i) == '+' && digits.size() >= 2) {
            int1 = digits.top();
            digits.pop();
            int2 = digits.top();
            digits.pop();
            value = int1 + int2;
            digits.push(value);
        }
        else if(postfix.at(i) == '-' && digits.size() >= 2) {
            int1 = digits.top();
            digits.pop();
            int2 = digits.top();
            digits.pop();
            value = abs(int1 - int2);
            digits.push(value);
        }
        else if(postfix.at(i) == '*' && digits.size() >= 2) {
            int1 = digits.top();
            digits.pop();
            int2 = digits.top();
            digits.pop();
            value = int1 * int2;
            digits.push(value);
        }
        else if(postfix.at(i) == '/' && digits.size() >= 2) {
            int1 = digits.top();
            digits.pop();
            int2 = digits.top();
            digits.pop();
            value = int2 / int1;
            digits.push(value);
        }
        else if(postfix.at(i) == '^' && digits.size() >= 2) {
            int1 = digits.top();
            digits.pop();
            int2 = digits.top();
            digits.pop();
            value = pow(int2, int1);
            digits.push(value);
        }
        else {
            error = true;
            break;
        }
    }

    if(spaceCount % 2 != 0) {
        error = true;
    }

    if(error) {
        return -1;
    }
    else {
        result = digits.top();
        return result;
    }
}
