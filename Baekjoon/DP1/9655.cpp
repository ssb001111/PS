#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    string arr[3] = {"SK", "CY", "SK"};

    int three = n / 3;
    int left = n % 3;

    if (left != 0){
        string initial = arr[left-1];
        if (three % 2 == 0){
            cout << initial;
        }
        else{
            if (initial == "SK"){
                cout << "CY";
            }
            else{
                cout << "SK";
            }
        }
    }
    else{
        if (three % 2 != 0){
            cout << "SK";
        }
        else{
            cout << "CY";
        }
    }

    return 0;
}
