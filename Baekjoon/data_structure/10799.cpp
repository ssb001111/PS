#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int main(){

    cin.tie(NULL);
	  ios_base::sync_with_stdio(false);

    string input_str;
    cin >> input_str;

    stack<char> stack;
    char prev_str;
    char curr_str;

    stack.push(input_str[0]);

    int no_sticks = 0;

    for (int i = 1; i < input_str.length(); i++){
        prev_str = input_str[i-1];
        curr_str = input_str[i];

        if (curr_str == ')'){
            if (prev_str == '('){
                stack.pop();
                no_sticks += stack.size();
            }
            else{
                stack.pop();
                no_sticks += 1;
            }
        }
        else{ // curr_str == '('
            stack.push('(');
        }

    }

    cout << no_sticks;

    return 0;
}
