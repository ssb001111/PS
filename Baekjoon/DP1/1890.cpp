#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector< vector<long long> > res;
vector< vector<int> > arr;

vector<long long> v;
vector<int> a;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        v = vector<long long>(n);
        res.push_back(v);
        a = vector<int>(n);
        arr.push_back(a);
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> arr[i][j];
            res[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int curr_y = i-1;
            int curr_x = j-1;
            long long result = 0;
            int diff = 0;
            while (curr_y > -1){
                diff = i - curr_y;
                if (diff == arr[curr_y][j]){
                    result += res[curr_y][j];
                }
                curr_y--;
            }
            while (curr_x > -1){
                diff = j - curr_x;
                if (diff == arr[i][curr_x]){
                    result += res[i][curr_x];
                }
                curr_x--;
            }
            res[i][j] = result;
            if (i == 0 and j == 0){
                res[i][j] = 1;
            }
        }
    }

    cout << res[n-1][n-1];

    return 0;
}
