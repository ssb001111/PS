#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int arr[n];
    map<int, int> m;

    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (m.find(arr[i]) != m.end()){
            m[arr[i]]++;
        }
        else{
            m[arr[i]] = 1;
        }
    }

    stable_sort(arr, arr+n);

    long long result = 0;

    for (int i = 0; i < n-2; i++){
        int first = arr[i];
        m[arr[i]]--;

        int target = -1 * first;

        int second = i+1;
        int third = n-1;
        while(second < third){
            int sum = arr[second] + arr[third];
            if (sum == target){
                if (arr[second] != arr[third]){
                    long long second_how_many = m[arr[second]];
                    long long third_how_many = m[arr[third]];
                    result += second_how_many * third_how_many;
                    second += second_how_many;
                    third -= third_how_many;
                }
                else{
                    long long num = m[arr[second]];
                    result += (num * (num-1)) / 2;
                    break;
                }
            }
            else if (sum < target){
                second++;
            }
            else if (sum > target){
                third--;
            }
        }
    }

    cout << result;

    return 0;
}
