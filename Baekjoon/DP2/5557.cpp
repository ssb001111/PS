#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int inputs[n-1];
    long long arr[n-1][21];
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < 21; j++){
            arr[i][j] = 0;
        }
    }

    for (int i = 0; i < n-1; i++){
        cin >> inputs[i];
    }

    int total;
    cin >> total;

    arr[0][inputs[0]] = 1;

    for (int i = 1; i < n-1; i++){
        for (int j = 0; j < 21; j++){
            if (arr[i-1][j] != 0){

                if (j + inputs[i] <= 20){
                    arr[i][j+inputs[i]] += arr[i-1][j];
                }

                if (j - inputs[i] >= 0){
                    arr[i][j-inputs[i]] += arr[i-1][j];
                }
            }
        }
    }

    cout << arr[n-2][total];

    return 0;
}
