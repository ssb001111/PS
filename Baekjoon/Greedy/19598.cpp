#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector< pair<int, int> > v;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    v = vector< pair<int, int> >(n);
    for (int i = 0; i < n; i++){
        int start, end;
        cin >> start >> end;
        v[i] = make_pair(end, start);
    }
    
    stable_sort(v.begin(), v.end(), greater< pair<int, int> >());

    priority_queue<int> q;;

    q.push(v[0].second);

    for (int i = 1; i < n; i++){
        if (v[i].first <= q.top()){
            q.pop();
        }
        q.push(v[i].second);
    }

    cout << q.size();

    return 0;
}
