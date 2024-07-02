#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

stack<char> s;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    // 일단 input 받기

    string input;
    cin >> input;

    for (int i = 0; i < input.length(); i++){
        if (input[i] == '+' or input[i] == '-'){
            while(!s.empty() and s.top() != '('){ // 잎의 +-*/ 모두 출력 가능
                cout << s.top();
                s.pop();
            }
            s.push(input[i]);
        }
        else if (input[i] == '*' or input[i] == '/'){
            if (!s.empty() and (s.top() == '*' or s.top() == '/')){ // 앞의 */민 츨력
                cout << s.top();
                s.pop();
            }
            s.push(input[i]);
        }
        else if (input[i] == '('){
            s.push(input[i]);
        }
        else if (input[i] == ')'){
            while(!s.empty() and s.top() != '('){
                cout << s.top();
                s.pop();
            }
            s.pop();
        }
        else{
            cout << input[i];
        }
    }

    while (!s.empty()){
        cout << s.top();
        s.pop();
    }

    return 0;
}
