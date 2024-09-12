#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,k;
    cin >> n >> k;

    int last_arr[n];
    for (int i = 0; i < n; i++){
        cin >> last_arr[i];
    }

    int mid_arr[n];

    for (int i = 0; i < n; i++){
        cin >> mid_arr[i];
    }

    int ans[n];
    for (int i = 0; i < k; i++){
        for (int j = 0; j < n; j++){
            int l = mid_arr[j];
            ans[l-1] = last_arr[j];
        }
        for (int j = 0; j < n; j++){
            last_arr[j] = ans[j];
        }
    }

    for (int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }

    return 0;
}
