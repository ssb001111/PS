#include <iostream>
#include <queue>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,k;
    cin >> n >> k;

    vector<int> arr[n+1];

    for (int i = 0; i < k; i++){
        int f,s;
        cin >> f >> s;
        arr[f].push_back(s);
        arr[s].push_back(f);
    }

    queue<int> q;
    bool visited[n+1];
    visited[0] = true;
    visited[1] = true;
    for (int i = 2; i < n+1; i++){
        visited[i] = false;
    }

    for (int i = 0; i < arr[1].size(); i++){
        q.push(arr[1][i]);
    }

    int result = 0;

    while (!q.empty()){
        int a = q.front();
        q.pop();
        if (visited[a] == false){
            visited[a] = true;
            result++;

            for (int i = 0; i < arr[a].size(); i++){
                if (visited[arr[a][i]] == false){
                    q.push(arr[a][i]);
                }
            }
        }
    }

    cout << result;

    return 0;
}
