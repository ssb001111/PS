#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    long long arr[t];

    for (int i = 0; i < t; i++){

        int n;
        cin >> n;

        priority_queue< long long, vector<long long>, greater<long long> > q;

        for (int i = 0; i < n; i++){
            long long a;
            cin >> a;
            q.push(a);
        }

        long long num = 0;

        while (q.size() != 1){
            long long a = q.top();
            q.pop();
            long long b = q.top();
            q.pop();
            num += a+b;
            q.push(a+b);
        }

        arr[i] = num;
    }

    for (int i = 0; i < t; i++){
        cout << arr[i] << "\n";
    }

    return 0;
}
