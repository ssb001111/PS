#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string first, second;
    cin >> first >> second;

    int arr[first.length() + 1][second.length() + 1];
    
    for (int i = 0; i < first.length() + 1; i++){
        for (int j = 0; j < second.length() + 1; j++){
            if (i == 0 or j == 0){
                arr[i][j] = 0;
            }
            else{
                if (first[i-1] == second[j-1]){
                    arr[i][j] = arr[i-1][j-1] + 1;
                }
                else{
                    arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
                }
            }
        }
    }

    cout << arr[first.length()][second.length()];

    return 0;
}
