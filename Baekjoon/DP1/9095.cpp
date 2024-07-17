#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
vector<long long> result;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        int s;
        cin >> s;
        v = vector<int>(s+1);

        if (s == 1 or s == 2){
            result.push_back(s);
        }
        else if (s == 3){
            result.push_back(4);
        }
        else{
            v[1] = 1;
            v[2] = 2;
            v[3] = 4;

            for (int j = 4; j < s+1; j++){
                v[j] = v[j-3] + v[j-2] + v[j-1];
            }

            result.push_back(v[s]);
        }
        
    }

    for (int i = 0; i < n; i++){
        cout << result[i] << "\n";
    }

    return 0;
}
