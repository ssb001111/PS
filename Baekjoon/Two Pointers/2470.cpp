#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int positive = 0;
    int negative = 0;

    int arr[n];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (arr[i] > 0){
            positive += 1;
        }
        else{
            negative += 1;
        }
    }

    stable_sort(arr, arr+n);

    if (positive == 0){
        cout << arr[n-2] << " " << arr[n-1];
    }
    else if (negative == 0){
        cout << arr[0] << " " << arr[1];
    }
    else{
        int minimum_abs = 2000000000;
        int first = 0;
        int second = n-1;

        int real_first = 0;
        int real_second = 0;

        while (first < second){
            int sum = arr[first] + arr[second];

            if (minimum_abs > abs(sum)){
                minimum_abs = abs(sum);
                real_first = first;
                real_second = second;
            }
            if (sum == 0){
                break;
            }

            if (sum < 0){
                first++;
            }
            else{
                second--;
            }
        }

        cout << arr[real_first] << " " << arr[real_second];
    }

    return 0;
}
