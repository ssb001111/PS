#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long num = 1;
    set<int> s;

    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++){
        int no;
        cin >> no;
        arr[i] = no;
    }

    for (int i = 0; i < n; i++){
        if (arr[i] == 2 or arr[i] == 3 or arr[i] == 5 or arr[i] == 7){
            if (s.find(arr[i]) != s.end()){ // 이미 앞에 있었다는 뜻
                continue;
            }
            else{
                s.insert(arr[i]);
                num *= arr[i];
            }
        }
        else{
            int number = sqrt(arr[i]);
            int end = 0;
            while ((number != 1) and (end == 0)){
                if ((arr[i] % number == 0)){
                    end = 1;
                }
                else{
                    number--;
                }
            }
            if (end == 0){
                if (s.find(arr[i]) != s.end()){ // 이미 앞에 있었다는 뜻
                    continue;
                }
                else{
                    s.insert(arr[i]);
                    num *= arr[i];
                }
            }
            else{
                continue;
            }
        }
    }

    if (num == 1){
        cout << -1;
    }
    else{
        cout << num;
    }
    
}
