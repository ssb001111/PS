#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    int result[t];

    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        int arr[n];
        for (int k = 0; k < n; k++){
            cin >> arr[k];
        }
        int m;
        cin >> m;
        int mid[m+1];
        for (int k = 0; k < m+1; k++){
            mid[k] = 0;
        }
        mid[0] = 1;
        for (int k = 0; k < n; k++){
            int current = arr[k];
            for (int a = 1; a < m+1; a++){
                if (a-current >= 0){
                    mid[a] += mid[a-current];
                }
            }
        }
        result[i] = mid[m];
    }

    for (int i = 0; i < t; i++){
        cout << result[i] << "\n";
    }

    return 0;
}
