#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

long long find_bridge(int n, int m){
    long long result = 1;
    long long mid = 1;

    for (int i = 0; i < m-n; i++){
        mid = mid * (n+i) / (i+1);
        result += mid;
    }

    return result;
}

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<long long> v;

    int s;
    cin >> s;

    for (int i = 0; i < s; i++){
        int n, m;
        cin >> n >> m;

        long long r = find_bridge(n, m);
        v.push_back(r);
    }

    for (int i = 0; i < v.size(); i++){
        cout << v[i] << "\n";
    }
    
    return 0;
}
