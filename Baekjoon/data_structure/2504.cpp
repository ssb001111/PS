#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string input_str;
    cin >> input_str;

    stack<string> real_stack;
    stack<string> secret_stack;

    for (int i = 0; i < input_str.length(); i++) {

        if (input_str[i] == '(') {
            real_stack.push("(");
            secret_stack.push("(");
        }
        else if (input_str[i] == ')') {
            if (!secret_stack.empty() and secret_stack.top() == "(") {
                secret_stack.pop();
                if (real_stack.top() == "(") { //( -> ()
                    real_stack.pop();
                    if (real_stack.empty() or real_stack.top() == "(" or real_stack.top() == "[") { // () -> nothing OR (() -> ( OR [() -> [
                        real_stack.push("2");
                    }
                    else { // X() -> X+2
                        int x = stoi(real_stack.top());
                        real_stack.pop();
                        real_stack.push(to_string(x + 2));
                    }
                }
                else { // (X -> (X)
                    int x = stoi(real_stack.top()); // X를 no라는 변수 안에 int로 가지고 있음
                    real_stack.pop();
                    if (real_stack.top() == "(") { // (X -> (X)
                        real_stack.pop();
                        if (real_stack.empty() or real_stack.top() == "(" or real_stack.top() == "[") {
                            real_stack.push(to_string(2 * x));
                        }
                        else {
                            int y = stoi(real_stack.top());
                            real_stack.pop();
                            real_stack.push(to_string(y + 2 * x));
                        }
                    }
                }
            }
            else {
                cout << 0;
                return 0;
            }
        }
        else if (input_str[i] == '[') {
            real_stack.push("[");
            secret_stack.push("[");
        }
        else if (input_str[i] == ']') {
            if (!secret_stack.empty() and secret_stack.top() == "[") {
                secret_stack.pop();
                if (real_stack.top() == "[") {
                    real_stack.pop();
                    if (real_stack.empty() or real_stack.top() == "(" or real_stack.top() == "[") { // [] -> nothing OR ([] -> ( OR [[] -> [
                        real_stack.push("3");
                    }
                    else { // X[] -> X+3
                        int x = stoi(real_stack.top());
                        real_stack.pop();
                        real_stack.push(to_string(x + 3));
                    }
                }
                else {
                    int x = stoi(real_stack.top()); // X를 no라는 변수 안에 int로 가지고 있음
                    real_stack.pop();
                    if (real_stack.top() == "[") { // (X -> (X)
                        real_stack.pop();
                        if (real_stack.empty() or real_stack.top() == "(" or real_stack.top() == "["){
                            real_stack.push(to_string(3 * x));
                        }
                        else {
                            int y = stoi(real_stack.top());
                            real_stack.pop();
                            real_stack.push(to_string(y + 3 * x));
                        }
                    }
                }
            }
            else {
                cout << 0;
                return 0;
            }
        }
    }

    if (secret_stack.size() == 0) {
        cout << real_stack.top();
    }
    else {
        cout << 0;
    }
    
    return 0;
}
