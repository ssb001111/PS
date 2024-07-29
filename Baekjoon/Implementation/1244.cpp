#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int s;
    cin >> s;

    for (int i = 0; i < s; i++){
        int gender;
        int switch_num;

        cin >> gender >> switch_num;

        if (gender == 1){
            int start = switch_num-1;

            while (start < n){
                arr[start] = !arr[start];
                start += switch_num;
            }
        }
        else{
            arr[switch_num-1] = !arr[switch_num-1];

            int k = 1;
            while ((switch_num - k > 0) && (switch_num - 1 + k < n)){
                if (arr[switch_num-1-k] == arr[switch_num-1+k]){
                    arr[switch_num-1-k] = !arr[switch_num-1-k];
                    arr[switch_num-1+k] = !arr[switch_num-1+k];
                    k++;
                }
                else{
                    break;
                }
            }
        }
    }

    int div = n / 20;
    int left = n % 20;
    for (int i = 0; i < div; i++){
        for (int j = 0; j < 20; j++){
            cout << arr[20*i + j] << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < left; i++){
        cout << arr[20 * div + i] << " ";
    }

    return 0;
}
