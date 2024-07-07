#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct Node{
    int parent = 0;
    vector<int> children;
};

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<int> pr_arr;

    while (true){
        int n, k;
        cin >> n >> k;
        if (n == 0 and k == 0){
            break;
        }
        else{

            vector< vector<int> > consecutive;
            map<int, Node> m;

            int last_node;

            for (int i = 0; i < n; i++){
                int node;
                cin >> node;
                if (i == 0 or i == 1){
                    vector<int> s;
                    s.push_back(node);
                    consecutive.push_back(s);
                    last_node = node;
                }
                else{
                    if (last_node + 1 == node){
                        consecutive[consecutive.size()-1].push_back(node);
                    }
                    else{
                        vector<int> s;
                        s.push_back(node);
                        consecutive.push_back(s);
                    }
                    last_node = node;
                }
            }

            queue<int> q;
            q.push(consecutive[0][0]);
            Node a;
            a.parent = 0;
            m.insert(make_pair(consecutive[0][0], a));

            for (int i = 1; i < consecutive.size(); i++){
                int node = q.front();
                for (int j = 0; j < consecutive[i].size(); j++){
                    q.push(consecutive[i][j]);
                    Node a;
                    a.parent = node;
                    m.insert(make_pair(consecutive[i][j], a));
                    m[node].children.push_back(consecutive[i][j]);
                }
                q.pop();
            }
            
            int par = m[m[k].parent].parent;
            int not_ = m[k].parent;
            int result = 0;
            for (int i = 0; i < m[par].children.size(); i++){
                if (m[par].children[i] != not_){
                    result += m[m[par].children[i]].children.size();
                }
            }
            pr_arr.push_back(result);
        }
    }

    for (int i = 0; i < pr_arr.size(); i++){
        cout << pr_arr[i] << "\n";
    }
    
    return 0;
}
