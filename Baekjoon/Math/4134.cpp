#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {

    int n;
    cin >> n;

    long long pr_arr[n];

    for (int i = 0; i < n; i++){
        long long input;
        cin >> input;

        long long starting_no;

        if (input % 2 == 0 and input != 2){
            starting_no = input + 1;
        }
        else{
            starting_no = input;
        }

        int end = 0;
        int found = 0;

        if (input == 0 or input == 1 or input == 2){
            found = 1;
            pr_arr[i] = 2;
        }

        while (!found){
            while (!end){
                for (long long j = 3; j <= sqrt(starting_no); j += 2){ // starting_no가 소수인지 판별
                    if (starting_no % j == 0){
                        end = 1; // 약수 찾음
                    }
                }
                break;
            }
            if (end == 0){ // starting_no가 소수이다
                pr_arr[i] = starting_no;
                found = 1;
            }
            else{ // starting_no가 소수가 아니다
                starting_no += 2;
                if (starting_no % 5 == 0 and starting_no != 5){
                    starting_no += 2;
                }
                end = 0;
            }
        }
    }

    for (int i = 0; i < n; i++){
        cout << pr_arr[i] << "\n";
    }

    return 0;
}
