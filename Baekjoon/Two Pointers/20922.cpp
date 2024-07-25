#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    int arr[n];
    map<int, int> m;

    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (m.find(arr[i]) == m.end()){
            m[arr[i]] = 0;
        }
    }

    int longest = 0;
    int last_end = -1;
    int prev_length = 0;

    for (int i = 0; i < n; i++){
        if (i != 0){
            m[arr[i-1]]--;
            prev_length--;
        }

        while(true){
            last_end++;
            if (last_end == n){
                longest = max(longest, prev_length);
                cout << longest;
                return 0;
            }
            else{
                if (m[arr[last_end]] == k){
                    longest = max(longest, prev_length);
                    last_end--;
                    break;
                }
                else{
                    prev_length++;
                    m[arr[last_end]]++;
                }
            }
        }
    }

    return 0;
}
