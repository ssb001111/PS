#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
vector< vector<int> > vec;
vector<int> dfs_visited;

vector<int> dfs_print;
vector<int> bfs_print;

void dfs(int index){
    dfs_visited[index] = 1;
    dfs_print.push_back(index+1);
    for (int i = 0; i < vec[index].size(); i++){
        if (dfs_visited[vec[index][i]] == 0){
            dfs(vec[index][i]);
        }
    }
}

void bfs(int index, int n){

    int visited[n];
    for (int i = 0; i < n; i++){
        visited[i] = 0;
    }
    visited[index] = 1;
    bfs_print.push_back(index+1);

    queue<int> q;
    for (int i = 0; i < vec[index].size(); i++){
        q.push(vec[index][i]);
    }

    while (!q.empty()){

        int curr = q.front();
        q.pop();

        if (visited[curr] == 0){
            visited[curr] = 1;
            bfs_print.push_back(curr+1);

            for (int i = 0; i < vec[curr].size(); i++){
                if (visited[vec[curr][i]] == 0){
                    q.push(vec[curr][i]);
                }
            }
        }
    }
}

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m, v;
    cin >> n >> m >> v;

    for (int i = 0; i < n; i++){
        vector<int> mid;
        vec.push_back(mid);
        dfs_visited.push_back(0);
    }

    for (int i = 0; i < m; i++){
        int f,s;
        cin >> f >> s;
        vec[f-1].push_back(s-1);
        vec[s-1].push_back(f-1);
    }

    for (int i = 0; i < n; i++){
        stable_sort(vec[i].begin(), vec[i].end());
    }

    dfs(v-1);
    bfs(v-1, n);

    for (int i = 0; i < dfs_print.size(); i++){
        cout << dfs_print[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < bfs_print.size(); i++){
        cout << bfs_print[i] << " ";
    }

    return 0;
}
