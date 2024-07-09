#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std; 

struct Node{
    int self = 0;
    int parent = 0;
    int level = 0;
    int left;
    int right;
    int index = 0;
};

map<int, vector<int> > m;

vector<Node> arr;

void level_func(int node){
    if (arr[node].left != -1){
        arr[arr[node].left].level = arr[node].level + 1;
        m[arr[node].level + 1].push_back(arr[node].left);
        level_func(arr[node].left);
    }
    if (arr[node].right != -1){
        arr[arr[node].right].level = arr[node].level + 1;
        m[arr[node].level + 1].push_back(arr[node].right);
        level_func(arr[node].right);
    }
}

vector<int> inorder_vec;

void inorder(int node){
    if (arr[node].left != -1){
        inorder(arr[node].left);
    }
    arr[node].index = inorder_vec.size();
    inorder_vec.push_back(node);
    if (arr[node].right != -1){
        inorder(arr[node].right);
    }
}
 
int main() {

	cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;

    arr = vector<Node>(n+1);

    for (int i = 0; i < n; i++){
        int node, left, right;
        cin >> node >> left >> right;
        arr[node].self = node;
        arr[node].left = left;
        arr[node].right = right;
        if (left != -1){
            arr[left].parent = node;
        }
        if (right != -1){
            arr[right].parent = node;
        } 
    }

    int root_node = 0;
    for (int i = 1; i < n+1; i++){
        if (arr[i].parent == 0){
            root_node = i;
            m[1].push_back(root_node);
            break;
        }
    }

    arr[root_node].level = 1;
    level_func(root_node);
    inorder(root_node);

    int result = 1;
    int level = 1;

    for (auto iter = m.begin(); iter != m.end(); iter++){
        if (iter->first > 1){
            vector<int> v;
            for (int i = 0; i < iter->second.size(); i++){
                v.push_back(arr[iter->second[i]].index);
            }
            stable_sort(v.begin(), v.end());
            int a = v[v.size()-1] - v[0] + 1;
            if (a > result){
                result = a;
                level = iter->first;
            }
        }
    }

    cout << level << " " << result;
        
    return 0;
}
