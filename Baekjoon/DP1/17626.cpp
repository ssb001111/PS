#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

vector<int> v;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    v = vector<int>(n+1);
    v[0] = 0;

    for (int i = 1; i < n+1; i++){
        v[i] = v[i-1] + 1;
        for (int j = 1; pow(j,2) <= i; j++){
            v[i] = min(v[i], v[i-pow(j,2)]+1);
        }
    }

    cout << v[n];

    return 0;
}
