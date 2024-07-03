#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;

    long long pr_arr[n];

    for (int i = 0; i < n; i++){
        long long first, second;
        cin >> first >> second;

        if (first < second){

            long long found_no = first;
            int end = 0;
            while ((found_no != 1) and (end == 0)){
                if ((first % found_no == 0) and (second % found_no == 0)){
                    end = 1;
                }
                else{
                    found_no--;
                }
            }

            if (found_no != 1){
                long long f = first / found_no;
                long long s = second / found_no;
                pr_arr[i] = found_no * f * s;
            }
            else{
                pr_arr[i] = first * second;
            }
        }
        else if (first > second){

            long long found_no = second;
            int end = 0;
            while ((found_no != 1) and (end == 0)){
                if ((first % found_no == 0) and (second % found_no == 0)){
                    end = 1;
                }
                else{
                    found_no--;
                }
            }

            if (found_no != 1){
                long long f = first / found_no;
                long long s = second / found_no;
                pr_arr[i] = found_no * f * s;
            }
            else{
                pr_arr[i] = first * second;
            }
        }
        else{
            pr_arr[i] = first;
        }
    }

    for (int i = 0; i < n; i++){
        cout << pr_arr[i] << "\n";
    }

    return 0;
}
