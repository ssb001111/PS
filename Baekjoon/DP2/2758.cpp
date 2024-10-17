#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    long long result[t];

    for (int w = 0; w < t; w++){

        result[w] = 0;

        int n,m;
        cin >> n >> m;

        long long arr[m+1][n+1];
        for (int i = 0; i < m+1; i++){
            for (int j = 0; j < n+1; j++){
                arr[i][j] = 0;
            }
        }

        for (int i = 1; i <= m; i++){
            arr[i][1] = 1;
            for (int k = 2; k <= n; k++){
                for (int j = 1; j <= i / 2; j++){
                    arr[i][k] += arr[j][k-1];
                }
            }
            
        }

        for (int i = 1; i <= m; i++){
            result[w] += arr[i][n];
        }
    }

    for (int w = 0; w < t; w++){
        cout << result[w] << " ";
    }

    return 0;
}
