#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    int arr[n][m];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (j == 0){
                cin >> arr[i][j];
            }
            else{
                int a;
                cin >> a;
                arr[i][j] = arr[i][j-1] + a;
            }
        }
    }

    int k;
    cin >> k;

    int result[k];

    for (int i = 0; i < k; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int res = 0;

        for (int j = x1-1; j < x2; j++){
            res += arr[j][y2-1];
            if (y1 != 1){
                res -= arr[j][y1-2];
            }
        }

        result[i] = res;
    }

    for (int i = 0; i < k; i++){
        cout << result[i] << "\n";
    }

    return 0;
}
