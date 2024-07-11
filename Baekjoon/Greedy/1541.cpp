#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std; 

vector<string> giho;
vector<int> nums;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string input;
    cin >> input;

    int size = input.length();

    string str = "";

    int minus = 0;

    for (int i = 0; i < size; i++){
        if (input[i] == '-'){
            minus = 1;
            nums.push_back(stoi(str));
            str = "";
            string s = "";
            s += input[i];
            giho.push_back(s);
        }
        else if (input[i] == '+'){
            nums.push_back(stoi(str));
            str = "";
            string s = "";
            if (minus == 0){
                s += '+';
            }
            else{
                s += '-';
            }
            giho.push_back(s);
        }
        else{
            str += input[i];
        }
    }

    nums.push_back(stoi(str));

    int result = nums[0];

    size = giho.size();

    for (int i = 0; i < size; i++){
        if (giho[i] == "+"){
            result += nums[i+1];
        }
        else{
            result -= nums[i+1];
        }
    }

    cout << result;
    
    return 0;
}
