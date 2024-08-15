#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int result = 0;

    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int delete_until_now = 0;
    int total_length = 0;
    int left = 0;
    int right = 0;

    while (right < n){
        if (arr[right] % 2 == 0){ // 현재 짝수
            total_length++;
            right++;
            result = max(result, total_length - delete_until_now);
        }
        else{ // 현재 홀수
            if (delete_until_now + 1 <= k){ // 현재 홀수를 삭제할 수 있음
                delete_until_now++;
                total_length++;
                right++;
                result = max(result, total_length - delete_until_now);
            }
            else{ // 현재 홀수 삭제 불가. 앞에서 홀수가 하나라도 삭제되어야 삭제 가능
                if (left < right){ // 현재까지 짝수가 한번이라도 있었음
                    if (arr[left] % 2 == 0){ // left가 짝수
                        left++;
                        total_length--;
                    }
                    else{ // left가 홀수
                        left++;
                        delete_until_now--;
                        total_length--;
                    }
                }
                else{ // 현재까지 홀수밖에 없었음
                    left++;
                    right++;
                }
            }
        }
    }

    cout << result;

    return 0;
}
