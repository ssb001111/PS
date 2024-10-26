#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
vector< vector<int> > vec;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        vector<int> mid;
        vec.push_back(mid);
    }

    for (int i = 0; i < m; i++){
        int f,s;
        cin >> f >> s;
        vec[s-1].push_back(f-1);
    }

    int largest_num = 0;
    vector<int> comps;

    for (int i = 0; i < n; i++){
        int visited[n];
        for (int j = 0; j < n; j++){
            visited[j] = 0;
        }
        visited[i] = 1;

        queue<int> q;

        vector<int> v = vec[i];
        for (int j = 0; j < v.size(); j++){
            q.push(v[j]);
        }

        int now = 1;

        while (!q.empty()){
            int curr = q.front();
            q.pop();
            if (visited[curr] == 0){
                visited[curr] = 1;
                now++;
                for (int k = 0; k < vec[curr].size(); k++){
                    if (visited[vec[curr][k]] == 0){
                        q.push(vec[curr][k]);
                    }
                }
            }
        }

        if (now > largest_num){
            comps.clear();
            comps.push_back(i+1);
            largest_num = now;
        }
        else if (now == largest_num){
            comps.push_back(i+1);
        }
    }

    for (int i = 0; i < comps.size(); i++){
        cout << comps[i] << " ";
    }

    return 0;
}
