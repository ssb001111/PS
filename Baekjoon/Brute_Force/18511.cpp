#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> v;
int n, k;
int result = 0;

void func(int curr, int left_depth){
    if (left_depth == 0){
        if (curr <= n){
            if (curr > result){
                result = curr;
            }
        }
    }
    else{
        for (int i = 0; i < v.size(); i++){
            func(curr * 10 + v[i], left_depth - 1);
        }
    }
}

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;

    for (int i = 0; i < k; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }

    stable_sort(v.begin(), v.end());

    string s = to_string(n);
    int length = s.length();

    for (int i = 0; i < v.size(); i++){
        func(v[i], length-1);
    }
    if (result == 0){
        for (int i = 0; i < v.size(); i++){
            func(v[i], length-2);
        }
    }

    cout << result;

    return 0;
}
