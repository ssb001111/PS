#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

struct Node{
    int parent;
    set<int> children;
};

int result = 0;

void dfs(Node nodes[], int starting_node){
    int size = nodes[starting_node].children.size();
    if (size == 0){
        result += 1;
    }
    else{
        for (auto iter = nodes[starting_node].children.begin(); iter != nodes[starting_node].children.end(); iter++){
            dfs(nodes, *iter);
        }
    }
}

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    Node nodes[n];
    for (int i = 0; i < n; i++){
        Node a;
        nodes[i] = a;
    }

    int root_node = 0;
    for (int i = 0; i < n; i++){
        int parent;
        cin >> parent;
        nodes[i].parent = parent;

        if (parent == -1){
            root_node = i;
        }

        if (parent != -1){
            nodes[parent].children.insert(i);
        }
    }

    int pr;
    cin >> pr;
    if (pr == root_node){
        cout << 0;
        return 0;
    }
    else{
        int pr_parent = nodes[pr].parent;
        nodes[pr_parent].children.erase(pr);
    }

    dfs(nodes, root_node);
    
    cout << result;
    return 0;
}
