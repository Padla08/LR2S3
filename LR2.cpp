#include "Stack.h"
#include <iostream>
#include <string>

using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

string infixToPostfix(const string& infix) {
    Stack operators;
    string postfix;

    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            operators.push(string(1, ch));
        }
        else if (ch == ')') {
            while (!operators.isEmpty() && operators.peek()[0] != '(') {
                postfix += operators.pop();
            }
            if (!operators.isEmpty() && operators.peek()[0] == '(') {
                operators.pop();
            }
        }
        else {
            while (!operators.isEmpty() && precedence(operators.peek()[0]) >= precedence(ch)) {
                postfix += operators.pop();
            }
            operators.push(string(1, ch));
        }
    }

    while (!operators.isEmpty()) {
        postfix += operators.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << postfix << endl;
    return 0;
}