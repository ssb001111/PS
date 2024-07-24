#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int result[n];

    for (int i = 0; i < n; i++){
        int m;
        cin >> m;

        int arr[2][m];
        for (int j = 0; j < 2; j++){
            for (int k = 0; k < m; k++){
                cin >> arr[j][k];
            }
        }

        int res[2][m];
        res[0][0] = arr[0][0];
        res[1][0] = arr[1][0];

        for (int j = 1; j < m; j++){
            res[0][j] = max(res[0][j-1], res[1][j-1] + arr[0][j]);
            res[1][j] = max(res[1][j-1], res[0][j-1] + arr[1][j]);
        }

        result[i] = max(res[0][m-1], res[1][m-1]);
    }

    for (int i = 0; i < n; i++){
        cout << result[i] << "\n";
    }

    return 0;
}
