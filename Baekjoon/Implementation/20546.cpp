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

    int j_left = n;
    int s_left = n;

    int bnp = 0;
    int timing = 0;

    int higher = 1;
    int lower = 1;

    for (int i = 0; i < 14; i++){
        cin >> arr[i];

        int to_add_to_bnp = j_left / arr[i];
        bnp += to_add_to_bnp;
        j_left -= to_add_to_bnp * arr[i];

        if (lower == 3){
            int to_add_to_timing = s_left / arr[i];
            timing += to_add_to_timing;
            s_left -= to_add_to_timing * arr[i];
        }
        else if (higher == 3){
            s_left += timing * arr[i];
            timing = 0;
        }

        if (i != 0){
            if (arr[i-1] < arr[i]){
                lower = 1;
                if (higher != 3){
                    higher++;
                }
            }
            else if (arr[i-1] > arr[i]){
                higher = 1;
                if (lower != 3){
                    lower++;
                }
            }
            else{
                higher = 1;
                lower = 1;
            }
        }
    }

    int bnp_final = j_left + arr[13] * bnp;
    int timing_final = s_left + arr[13] * timing;

    if (bnp_final > timing_final){
        cout << "BNP";
    }
    else if (bnp_final < timing_final){
        cout << "TIMING";
    }
    else{
        cout << "SAMESAME";
    }

    return 0;
}
