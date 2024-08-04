#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    string arr[n];

    string str;
    cin >> str;

    for (int i = 0; i < n; i++){
        arr[i] = str[i];
    }

    stack<string> s;

    s.push(arr[0]);

    string result = "";

    for (int i = 1; i < n; i++){
        if (k == 0){
            for (int j = i; j < n; j++){
                result += arr[j];
            }
            break;
        }
        else{
            while (stoi(arr[i]) > stoi(s.top()) and (k > 0)){
                s.pop();
                k--;
                if (s.empty()){
                    break;
                }
            }
            s.push(arr[i]);
        }
    }

    if (k > 0){
        while (k){
            s.pop();
            k--;
        }
    }

    int size = s.size();

    for (int i = 0; i < size; i++){
        string t = s.top();
        s.pop();
        result = t + result;
    }

    cout << result;

    return 0;
}
