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

    vector< pair<long long, long long> > v;

    long long total_people = 0;

    for (int i = 0; i < n; i++){
        long long x, a;
        cin >> x >> a;
        v.push_back(make_pair(x,a));
        total_people += a;
    }

    stable_sort(v.begin(), v.end());

    long long arr[n];

    arr[0] = v[0].second;

    int index = 0;

    for (int i = 1; i < n+1; i++){
        long long b = total_people - arr[i-1];
        if (b <= arr[i-1]){
            index = i-1;
            break;
        }
        else{
            arr[i] = arr[i-1] + v[i].second;
        }
    }

    cout << v[index].first;

    return 0;
}
