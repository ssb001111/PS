#include <iostream>
#include <string>
#include <algorithm>

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

    int n, pr;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++){
        int input;
        cin >> input;
        arr[i] = input;
    }

    cin >> pr;

    double count = 0;
    double total = 0;

    for (int i = 0; i < n; i++){
        int num = arr[i];

        int ret = 0;

        if (num > pr){
            ret = get_gcd(num, pr);
        }
        else if (num < pr){
            ret = get_gcd(pr, num);
        }
        else{
            continue;
        }

        if (ret == 1){
            count += 1;
            total += arr[i];
        }
    }

    cout.precision(7);
    cout << total / count;

    return 0;
}
