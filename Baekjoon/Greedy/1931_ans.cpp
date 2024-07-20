// 완료 시간을 기준으로 정렬
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

    vector< pair<int, int> > v;

    for (int i = 0; i < n; i++){
        int s,e;
        cin >> s >> e;
        v.push_back(make_pair(e,s));
    }

    stable_sort(v.begin(), v.end());

    int ans = 0;
    int s = v.front().second; // 가장 처음으로 끝나는 회의의 시작 시간

    for (int i = 0; i < n; i++){
        if (v[i].second >= s){ // 회의들의 시작 시간이 s보다 크거나 같은지 확인
            ans++;
            s = v[i].first; // 그 회의의 완료 시간으로 새 s를 설정
        }
    }

    cout << ans;

    return 0;
}
