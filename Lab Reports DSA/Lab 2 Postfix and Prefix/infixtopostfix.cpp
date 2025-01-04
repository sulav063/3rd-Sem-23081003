/*WAP to demonstrate infix to postfix expression.*/
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class InfixToPrefixConverter {
private:
    stack<char> st;

    bool isOperator(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/' || c == '$');
    }

    bool isAlphanumeric(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }

    int getPrecedence(char op) {
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
    string prefixExpr;

    string toPrefix(const string &infix) {
        string prefix = "";
        string reversedInfix = infix;
        reverse(reversedInfix.begin(), reversedInfix.end());

        for (char c : reversedInfix) {
            if (isAlphanumeric(c)) {
                prefix += c;
            } else if (c == ')') {
                st.push(c);
            } else if (c == '(') {
                while (st.size() > 0 && st.top() != ')') {
                    prefix += st.top();
                    st.pop();
                }
                if (st.size() > 0) {
                    st.pop(); // Discard the ')'
                }
            } else if (isOperator(c)) {
                while (st.size() > 0 && getPrecedence(st.top()) > getPrecedence(c)) {
                    prefix += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }

        while (st.size() > 0) {
            prefix += st.top();
            st.pop();
        }

        reverse(prefix.begin(), prefix.end());
        prefixExpr = prefix;
        return prefix;
    }
};

int main() {
    InfixToPrefixConverter conv;
    string infixExpr;

    cout << "Enter an infix expression: ";
    getline(cin, infixExpr);

    string prefixExpr = conv.toPrefix(infixExpr);
    cout << "Prefix expression: " << prefixExpr << endl;

    return 0;
}
