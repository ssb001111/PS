#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
    cin.tie(NULL);
		ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int arr[n];

    string prob_str;
    cin >> prob_str;

    stack<double> stack;

    for (int i = 0; i < n; i++){
        string num;
        cin >> num;
        arr[i] = stod(num);
    }

    for (int i = 0; i < prob_str.length(); i++){
        int no = (int)prob_str[i];
        if (no >= 65){
            int new_no_index = no-65;
            stack.push(arr[new_no_index]);
        }
        else if (no == 42){ // *
            double num_one = stack.top();
            stack.pop();
            double num_two = stack.top();
            stack.pop();
            double new_num = num_one * num_two;
            stack.push(new_num);
        }
        else if (no == 43){ // +
            double num_one = stack.top();
            stack.pop();
            double num_two = stack.top();
            stack.pop();
            double new_num = num_one + num_two;
            stack.push(new_num);
        }
        else if (no == 45){ // -
            double num_one = stack.top();
            stack.pop();
            double num_two = stack.top();
            stack.pop();
            double new_num = num_two - num_one;
            stack.push(new_num);
        }
        else if (no == 47){ // /
            double num_one = stack.top();
            stack.pop();
            double num_two = stack.top();
            stack.pop();
            double new_num = num_two / num_one;
            stack.push(new_num);
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << stack.top();

    return 0;
}
