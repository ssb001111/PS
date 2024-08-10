#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    int arr[n+1];
    for (int i = 0; i < n+1; i++){
        arr[i] = 0;
    }
    arr[1] = 1;

    map< int, vector<int> > map_;

    for (int i = 0; i < m; i++){
        int first, second;
        cin >> first >> second;

        if (map_.find(second) == map_.end()){
            vector<int> v;
            v.push_back(first);
            map_[second] = v;
        }
        else{
            map_[second].push_back(first);
        }
    }

    for (int i = 1; i < n+1; i++){
        if (map_.find(i) != map_.end()){
            int maximum = 0;
            for (int j = 0; j < map_[i].size(); j++){
                maximum = max(maximum, arr[map_[i][j]]);
            }
            arr[i] = maximum + 1;
        }
        else{
            arr[i] = 1;
        }
    }

    for (int i = 1; i < n+1; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
