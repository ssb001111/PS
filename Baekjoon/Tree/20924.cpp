#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

struct Node{
    map<int, int> connected;
};

int giga_node = 0;
long long giga_length = 0;
int no_branch = 0;

void finding_giga_length(int st_node, Node node_list[], int visited[]){
    if (node_list[st_node].connected.size() >= 3){
        visited[st_node] = 1;
        giga_node = st_node;
    }
    else if (node_list[st_node].connected.size() == 1){
        giga_node = st_node;
        no_branch = 1;
    }
    else if (node_list[st_node].connected.size() == 2){
        visited[st_node] = 1;
        if (visited[node_list[st_node].connected.begin()->first] == 0){
            giga_length += node_list[st_node].connected.begin()->second;
            finding_giga_length(node_list[st_node].connected.begin()->first, node_list, visited);
        }
        else{
            giga_length += next(node_list[st_node].connected.begin(),1)->second;
            finding_giga_length(next(node_list[st_node].connected.begin(),1)->first, node_list, visited);
        }
    }
}

int finding_longest_branch(int node, Node node_list[], int visited[]){
    visited[node] = 1;
    if (node_list[node].connected.size() == 1){
        visited[node_list[node].connected.begin()->first] = 1;
        return 0;
    }
    else{
        int length = 0;
        for (auto iter = node_list[node].connected.begin(); iter != node_list[node].connected.end(); iter++){
            if (visited[(*iter).first] == 0){
                int mid = finding_longest_branch((*iter).first, node_list, visited) + node_list[node].connected[(*iter).first];
                if (mid > length){
                    length = mid;
                }
            }
        }
        return length;
    }
    
    
}

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, r;
    cin >> n >> r;

    Node node_list[n+1];
    int visited[n+1];

    for (int i = 1; i < n+1; i++){
        Node a;
        node_list[i] = a;
        visited[i] = 0;
    }

    for (int i = 0; i < (n-1); i++){
        int a, b, d;
        cin >> a >> b >> d;
        node_list[a].connected.insert(make_pair(b,d));
        node_list[b].connected.insert(make_pair(a,d));
    }

    // 기가 노드(giga_node), 기둥 길이(giga_length) 찾기 완료
    if (node_list[r].connected.size() == 0){
        giga_node = r;
        no_branch = 1;
    }
    else if (node_list[r].connected.size() > 1){
        giga_node = r;
    }
    else if (node_list[r].connected.size() == 1){
        visited[r] = 1;
        giga_length += node_list[r].connected.begin()->second;
        finding_giga_length(node_list[r].connected.begin()->first, node_list, visited);
    }

    // 가지
    if (no_branch == 1){ // 가지가 없음
        cout << giga_length << " " << 0;
    }
    else{ // 가지가 있긴 있음
        cout << giga_length << " " << finding_longest_branch(giga_node, node_list, visited);
    }
    
    
    return 0;
}
