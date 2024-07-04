#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

struct Node{
    int left_child = 0;
    int right_child = 0;
};

Node node_list[1000001];

void func(int node){
    if (node_list[node].left_child != 0){
        func(node_list[node].left_child);
    }
    if (node_list[node].right_child != 0){
        func(node_list[node].right_child);
    }
    cout << node << "\n";
}

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<int> nodes;

    string n;
    while (getline(cin, n)){
        nodes.push_back(stoi(n));
    }

    int size = nodes.size();
    int root_node = nodes[0];
    
    stack<int> s;
    s.push(root_node);

    for (int i = 1; i < size; i++){
        if (s.top() > nodes[i]){
            node_list[s.top()].left_child = nodes[i];
            s.push(nodes[i]);
        }
        else{
            int found = 0;
            int top = s.top();
            s.pop();
            while (!s.empty() and !found){
                if (s.top() > nodes[i]){
                    s.push(nodes[i]);
                    node_list[top].right_child = nodes[i];
                    found = 1;
                }
                else{
                    top = s.top();
                    s.pop();
                }
            }
            if (s.empty()){
                s.push(nodes[i]);
                node_list[top].right_child = nodes[i];
            }
        }
    }

    func(root_node);
    
    return 0;
}
