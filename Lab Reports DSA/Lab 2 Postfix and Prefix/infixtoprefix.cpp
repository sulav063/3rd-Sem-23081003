/*WAP to demonstrate infix to prefix expression.*/
#include <iostream>
#include <stack>
#include <string>
#include <algorithm> // to reverse a given string;
using namespace std;

int prec(char c) {
    if (c == '^') {
        return 3;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {  // Fix: Corrected the condition for '+' and '-'
        return 1;
    } else {
        return -1;
    }
}

string infixtoprefix(string s) {
    reverse(s.begin(), s.end());
    stack<char> st;
    string res;
    for (int i = 0; i < s.length(); i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            res += s[i];
        } else if (s[i] == ')') {
            st.push(s[i]);
        } else if (s[i] == '(') {
            while (!st.empty() && st.top() != ')') {
                res += st.top();
                st.pop();
            }
            if (!st.empty()) {
                st.pop();
            }
        } else {
            while (!st.empty() && prec(st.top()) >= prec(s[i])) {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    cout << infixtoprefix("a+(b*c-(d/e^f)*g)*h") << endl;
    return 0;
}