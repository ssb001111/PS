#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct Node{
    map<int, int> children;
    vector<int> length;
};

vector<Node> node_list;

int find_routes_sub(int node_){
    if (node_list[node_].children.size() == 0){
        return 0;
    }
    else{
        int length = 0;
        for (auto iter = node_list[node_].children.begin(); iter != node_list[node_].children.end(); iter++){
            int mid = find_routes_sub(iter->first) + iter->second;
            if (mid > length){
                length = mid;
            }
        }
        return length;
    }
}

void find_routes_of_children(int node){
    for (auto iter = node_list[node].children.begin(); iter != node_list[node].children.end(); iter++){
        int r = find_routes_sub(iter->first) + iter->second;
        node_list[node].length.push_back(r);
    }
}

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    node_list = vector<Node>(n+1);

    for (int i = 1; i < n+1; i++){
        Node a;
        node_list[i] = a;
    }

    for (int i = 0; i < (n-1); i++){
        int a, b, d;
        cin >> a >> b >> d;
        node_list[a].children.insert(make_pair(b, d));
    }

    int result = 0;

    if (node_list[1].children.size() == 1){
        find_routes_of_children(1);
        result = node_list[1].length[0];
        for (int i = 2; i < n+1; i++){
            if (node_list[i].children.size() >= 2){
                find_routes_of_children(i);
                stable_sort(node_list[i].length.begin(), node_list[i].length.end(), greater<int>());
                int mid_ = node_list[i].length[0] + node_list[i].length[1];
                if (mid_ > result){
                    result = mid_;
                }
            }
        }
    }
    else{
        for (int i = 1; i < n+1; i++){
            if (node_list[i].children.size() >= 2){
                find_routes_of_children(i);
                stable_sort(node_list[i].length.begin(), node_list[i].length.end(), greater<int>());
                int mid_ = node_list[i].length[0] + node_list[i].length[1];
                if (mid_ > result){
                    result = mid_;
                }
            }
        }
    }

    cout << result;
    
    return 0;
}
