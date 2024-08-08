#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int div = 1000000000;

    int n,k;
    cin >> n >> k;

    int arr[n+1][k+1];

    for (int i = 0; i < n+1; i++){
        for (int j = 0; j < k+1; j++){
            if (i == 0){
                arr[i][j] = 1;
            }
            else if (j == 0){
                arr[i][j] = 0;
            }
            else{
                if (j == 1){
                    arr[i][j] = 1;
                }
                else{
                    int e = 0;
                    for (int k = 0; k <= i; k++){
                        e += arr[k][j-1];
                        e = e % div;
                    }
                    arr[i][j] = e;
                }
            }
        }
    }

    cout << arr[n][k];

    return 0;
}
