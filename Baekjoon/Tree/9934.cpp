#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

void tree(vector<int> final_arr[], int k, int start, int arr[], int space) {
    final_arr[k].push_back(arr[start]);
    k++;
    if (start % 2 != 1) {
        int first = start - space;
        int second = start + space;
        tree(final_arr, k, first, arr, space/2);
        tree(final_arr, k, second, arr, space/2);
    }
}

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int k;
    cin >> k;

    vector<int> final_arr[k]; // output을 넣어놓는 array

    int s = pow(2, k);
    int arr[s]; // input을 넣어놓는 array ( 1 ~ 2^k )

    for (int i = 1; i < s; i++) {
        int a;
        cin >> a;
        arr[i] = a;
    }

    int start = s / 2;

    tree(final_arr, 0, start, arr, start/2);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < final_arr[i].size()-1; j++) {
            cout << final_arr[i][j] << " ";
        }
        cout << final_arr[i][final_arr[i].size() - 1] << "\n";
    }

    return 0;
}
