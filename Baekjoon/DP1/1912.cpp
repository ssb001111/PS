#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> v;

    for (int i = 0; i < n; i++){
        v.push_back(0);
    }

    for (int i = 0; i < n; i++){
        int s;
        cin >> s;
        
        if (v.empty()){
            v[i] = s;
        }
        else{
            v[i] = max(s, v[i-1] + s);
        }
    }

    stable_sort(v.begin(), v.end(), greater<int>());

    cout << v[0];

    return 0;
}
