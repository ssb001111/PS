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
    int index = 0;

    for (int i = 0; i < n; i++){
        if (i == 0){
            arr[0] = v[0].second;
        }
        else{
            arr[i] = arr[i-1] + v[i].second;
        }
        
        long long b = total_people - arr[i];
        if (b <= arr[i]){
            index = i;
            break;
        }
    }

    cout << v[index].first;

    return 0;
}
