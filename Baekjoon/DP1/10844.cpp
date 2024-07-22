#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int arr[n][10];

    int div = 1000000000;

    arr[0][0] = 0;
    for (int i = 1; i < 10; i++){
        arr[0][i] = 1;
    }
    for (int i = 1; i < n; i++){
        for (int j = 0; j < 10; j++){
            if (j == 0){
                arr[i][j] = arr[i-1][1] % div;
            }
            else if (j == 9){
                arr[i][j] = arr[i-1][8] % div;
            }
            else{
                arr[i][j] = (arr[i-1][j-1] + arr[i-1][j+1]) % div;
            }
        }
    }

    int result = 0;
    for (int i = 0; i < 10; i++){
        result += arr[n-1][i];
        result = result % div;
    }

    cout << result;

    return 0;
}
