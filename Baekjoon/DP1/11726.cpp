#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;

int func(int i){
    if (v[i] == -1){
        int a = func(i-1) + func(i-2);
        v[i] = a % 10007;
        return v[i];
    }
    else{
        return v[i];
    }
}

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    if (n == 1){
        cout << 1;
    }
    else if (n == 2){
        cout << 2;
    }
    else{
        v = vector<int>(n);
        for (int i = 0; i < n; i++){
            v[i] = -1;
        }
        v[1] = 1;
        v[2] = 2;

        int ans = func(n-1) + func(n-2);
        int s = 10007;

        cout << ans % s;
    }

    return 0;
}
