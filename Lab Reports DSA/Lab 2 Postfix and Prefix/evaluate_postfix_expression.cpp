#include <iostream>
#include <stack>
#include <cctype>
#include <map>
#include <cmath>

using namespace std;

class InfixToPostfixConverter {
private:
    stack<char> st;
    map<char, int> varVals;

    bool isOp(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/' || c == '$');
    }

    int getPrec(char op) {
        if (op == '+' || op == '-') {
            return 1;
        } else if (op == '*' || op == '/') {
            return 2;
        } else if (op == '$') {
            return 3;
        }
        return 0;
    }

public:
    string postfixExpr;

    string toPostfix(const string &infix) {
        string postfix = "";
        for (char c : infix) {
            if (c == '^') {
                postfix += '$';  // Display '^' as '$'
            } else if (isalnum(c)) {
                postfix += c;
            } else if (c == '(') {
                st.push(c);
            } else if (c == ')') {
                while (st.size() > 0 && st.top() != '(') {
                    postfix += st.top();
                    st.pop();
                }
                st.pop(); // Discard the '('
            } else if (isOp(c)) {
                while (st.size() > 0 && getPrec(st.top()) >= getPrec(c)) {
                    postfix += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }

        while (st.size() > 0) {
            postfix += st.top();
            st.pop();
        }

        postfixExpr = postfix;
        return postfix;
    }

    void inputVarVals(const string &infix) {
        for (char c : infix) {
            if (isalpha(c) && varVals.find(c) == varVals.end()) {
                int val;
                cout << "Enter value for variable '" << c << "': ";
                cin >> val;
                varVals[c] = val;
            }
        }
    }

    int evalPostfix() {
        stack<int> operands;
        for (char c : postfixExpr) {
            if (isalnum(c)) {
                operands.push(varVals[c]);
            } else if (isOp(c)) {
                int op2 = operands.top();
                operands.pop();
                int op1 = operands.top();
                operands.pop();

                switch (c) {
                case '+':
                    operands.push(op1 + op2);
                    break;
                case '-':
                    operands.push(op1 - op2);
                    break;
                case '*':
                    operands.push(op1 * op2);
                    break;
                case '/':
                    operands.push(op1 / op2);
                    break;
                case '$':
                    operands.push(pow(op1, op2));
                    break;
                }
            }
        }

        return operands.top();
    }
};

int main() {
    InfixToPostfixConverter conv;
    string infixExpr;

    cout << "Enter an infix expression: ";
    getline(cin, infixExpr);

    string postfixExpr = conv.toPostfix(infixExpr);
    cout << "Postfix expression: " << postfixExpr << endl;

    conv.inputVarVals(infixExpr);

    int result = conv.evalPostfix();
    cout << "Result: " << result << endl;

    return 0;
}
