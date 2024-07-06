#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int num_of_five = n / 5;
    int left = n % 5;
    int num_of_two = 0;

    int result = 0;

    int found = 0;
    while (num_of_five != -1 and !found){
        if (left % 2 == 0){
            num_of_two = left / 2;
            found = 1;
        }
        else{
            num_of_five--;
            left += 5;
        }
    }
    if (found == 1){
        result += num_of_five;
        result += num_of_two;
    }
    else{
        result = -1;
    }

    cout << result;
    
    return 0;
}
