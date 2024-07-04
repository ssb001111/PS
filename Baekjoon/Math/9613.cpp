#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int get_gcd(int big, int small){
    if (small == 0){
        return big;
    }
    else{
        return get_gcd(small, big % small);
    }
}

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<long long> pr_arr;

    for (int i = 0; i < n; i++){
        int no;
        cin >> no;
        int arr[no];
        vector<long long> gcds;
        for (int j = 0; j < no; j++){
            int input;
            cin >> input;
            arr[j] = input;
        }
        for (int j = 0; j < no; j++){
            for (int k = j+1; k < no; k++){
                if (arr[j] > arr[k]){
                    int result = get_gcd(arr[j], arr[k]);
                    gcds.push_back(result);
                }
                else if (arr[j] < arr[k]){
                    int result = get_gcd(arr[k], arr[j]);
                    gcds.push_back(result);
                }
                else{
                    gcds.push_back(arr[j]);
                }
            }
        }
        long long final = 0;
        for (int j = 0; j < gcds.size(); j++){
            final += gcds[j];
        }
        pr_arr.push_back(final);
    }

    for (int i = 0; i < pr_arr.size(); i++){
        cout << pr_arr[i] << "\n";
    }
    
}
