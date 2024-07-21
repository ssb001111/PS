#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector< pair<int, int> > vl;
vector< pair<int, int> > vr;
priority_queue<int> vl_sub;
priority_queue<int> vr_sub;

priority_queue<int> largest;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vl = vector< pair<int, int> >(n-1);
    vr = vector< pair<int, int> >(n-1);

    int arr[n];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (i != 0 and i != n-1){
            largest.push(arr[i]);
        }
    }

    int left_max = 0;
    for (int i = 0; i < n-1; i++){
        if (i == 0){
            vl[0].first = arr[0];
            vl[0].second = arr[1];
        }
        else{
            vl[i].first = vl[i-1].first + vl[i-1].second;
            vl[i].second = arr[i+1];
        }
        if (i != n-2){
            vl_sub.push(vl[i].first - vl[i].second);
        }
    }
    left_max = vl[n-2].first + vl_sub.top();

    int right_max = 0;
    for (int i = n-2; i > -1; i--){
        if (i == n-2){
            vr[n-2].first = arr[n-1];
            vr[n-2].second = arr[n-2];
        }
        else{
            vr[i].first = vr[i+1].first + vr[i+1].second;
            vr[i].second = arr[i];
        }
        if (i != 0){
            vr_sub.push(vr[i].first - vr[i].second);
        }
    }
    right_max = vr[0].first + vr_sub.top();

    int mid_result = max(left_max, right_max);

    // 벌집이 가운데 있는 경우도 해야함
    int m = vr[0].first - vr[n-2].first;
    m += largest.top();

    cout << max(mid_result, m);

    return 0;
}
