#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector< vector<int> > graph;

void bfs(int parent[]){
    queue<int> q;
    q.push(1);

    while (!q.empty()){
        int x = q.front();
        q.pop();

        for (int i = 0; i < graph[x].size(); i++){
            if (parent[graph[x][i]] == -1){
                q.push(graph[x][i]);
                parent[graph[x][i]] = x;
            }
        }
    }
}

int main(){

    cin.tie(NULL);
	  ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int parent[n+1];
    parent[1] = 1;
    for (int i = 2; i < n+1; i++){
        parent[i] = -1;
    }

    for (int i = 0; i < n+1; i++){
        vector<int> v;
        graph.push_back(v);
    }

    for (int i = 0; i < n-1; i++){
        int one, two;
        cin >> one >> two;
        graph[one].push_back(two);
        graph[two].push_back(one);
    }

    bfs(parent);

    for (int i = 2; i < n+1; i++){
        cout << parent[i] << "\n";
    }

    return 0;
}
