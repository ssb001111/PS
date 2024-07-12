#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    if (n == 0 or n == 1){
        cout << n;
    }
    else{

        long long first = 0;
        long long second = 1;

        for (int i = 2; i < n+1; i++){
            long long new_num = first + second;
            first = second;
            second = new_num;
        }

        cout << second;
    }
    
    return 0;
}
