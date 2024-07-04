#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

struct Node{
    set<int> connected;
};

double result = 0;

void dfs(Node nodes[], int starting_node, int visited[]){
    int none = 1;
    for (auto iter = nodes[starting_node].connected.begin(); iter != nodes[starting_node].connected.end(); iter++){
        if (visited[*iter] == 0){
            visited[*iter] = 1;
            none = 0;
            dfs(nodes, *iter, visited);
        }
    }
    if (none == 1){
        result += 1;
    }
}

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, w;
    cin >> n >> w;

    Node nodes[n+1];
    for (int i = 0; i < n+1; i++){
        Node a;
        nodes[i] = a;
    }

    for (int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        nodes[u].connected.insert(v);
        nodes[v].connected.insert(u);
    }

    int visited[n+1];
    for (int i = 0; i < n+1; i++){
        visited[i] = 0;
    }
    visited[1] = 1;
    dfs(nodes, 1, visited);
    
    cout.precision(4);
    cout << fixed << w / result;
    return 0;
}
