#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    int table[n][n];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (j == 0){
                cin >> table[i][j];
            }
            else{
                int a;
                cin >> a;
                table[i][j] =  table[i][j-1] + a;
            }
        }
    }

    int ans[m];

    for (int j = 0; j < m; j++){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int a = 0;

        for (int i = (x1-1); i < x2; i++){
            a += table[i][y2-1];
            if (y1 != 1){
                a -= table[i][y1-2];
            }
        }

        ans[j] = a;
    }

    for (int i = 0; i < m; i++){
        cout << ans[i] << "\n";
    }

    return 0;
}
