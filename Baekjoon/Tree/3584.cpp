#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct Node{
    int parent = 0;
    vector<int> children;
};

int found = 0;

void dfs(int starting_node, int checking_node, Node arr[], int visited[]){
    visited[starting_node] = 1;
    for (int i = 0; i < arr[starting_node].children.size(); i++){
        if (arr[starting_node].children[i] == checking_node){
            found = 1;
        }
    }
    if (found == 0){
        for (int i = 0; i < arr[starting_node].children.size(); i++){
            if (visited[arr[starting_node].children[i]] == 0){
                dfs(arr[starting_node].children[i], checking_node, arr, visited);
            }
        }
    }
}

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int testcase;
    cin >> testcase;

    vector<int> pr_arr;

    for (int i = 0; i < testcase; i++){

        found = 0;
        
        int no_of_nodes;
        cin >> no_of_nodes;

        Node arr[no_of_nodes+1];

        for (int j = 0; j < no_of_nodes - 1; j++){
            int f, s;
            cin >> f >> s;
            arr[f].children.push_back(s);
            arr[s].parent = f;
        }

        int node_first, node_second;
        cin >> node_first >> node_second;

        // 각자 시작으로 dfs 해서 서로가 서로의 부모/자식이 아님을 확인
        // 만약 맞다면 더 높은 노드가 공통 조상

        int visited[no_of_nodes+1];

        for (int j = 0; j < no_of_nodes + 1; j++){
            visited[j] = 0;
        }
        dfs(node_first, node_second, arr, visited);

        if (found == 1){
            pr_arr.push_back(node_first);
        }
        else{
            for (int j = 0; j < no_of_nodes + 1; j++){
                visited[j] = 0;
            }
            dfs(node_second, node_first, arr, visited);

            if (found == 1){
                pr_arr.push_back(node_second);
            }
            else{
                // node_first를 시작으로 parent 거슬러 올라가면서 dfs, node_second를 (먼 자식이라도) 자식으로 가지는 첫 노드 찾기 
                for (int j = 0; j < no_of_nodes + 1; j++){
                    visited[j] = 0;
                }
                int node = node_first;
                while (arr[node].parent != 0){
                    node = arr[node].parent;
                    dfs(node, node_second, arr, visited);

                    if (found == 1){
                        pr_arr.push_back(node);
                        break;
                    }
                }
            }
        }
    }

    for (int j = 0; j < pr_arr.size(); j++){
        cout << pr_arr[j] << "\n";
    }
    
    return 0;
}
