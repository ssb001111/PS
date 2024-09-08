#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int number = 4 * n - 3;
    int start = 0;
    int end = 4 * n - 4;

    string arr[number][number];

    for (int i = 0; i < 4 * n - 3; i++){
        for (int j = 0; j < 4 * n - 3; j++){
            arr[i][j] = " ";
        }
    }

    while (number != -3){
        for (int i = 0; i < number; i++){
            arr[start][start + i] = "*";
            arr[end][start + i] = "*";

            arr[start + i][start] = "*";
            arr[start + i][end] = "*";
        }
        number -= 4;
        start += 2;
        end -= 2;
    }
    
    for (int i = 0; i < 4 * n - 3; i++){
        for (int j = 0; j < 4 * n - 3; j++){
            cout << arr[i][j];
        }
        cout << "\n";
    }

    return 0;
}
