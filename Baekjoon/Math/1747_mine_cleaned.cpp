#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int check_if_prime(int n){
    int found_div = 0; // 약수를 찾았는지
    int starting_ = sqrt(n);
    while (starting_ != 1 and !found_div){
        if (n % starting_ == 0){
            found_div = 1;
        }
        else{
            starting_--;
        }
    }
    if (starting_ == 1){
        return 1;
    }
    else{
        return 0;
    }
}

int check_if_palindrome(int n){
    int length = to_string(n).length();
    if (length == 4){
        return 4;
    }
    else if (length == 6){
        return 6;
    }
    else{
        int mid = length / 2;
        string str = to_string(n);
        for (int i = 0; i < mid; i++){
            if (str[i] != str[length-1-i]){
                return 0;
            }
        }
        return 1;
    }
}

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int input;
    cin >> input;

    if (input == 1 or input == 2){
        cout << 2;
    }
    else if (input == 3){
        cout << 3;
    }
    else if (input == 4 or input == 5){
        cout << 5;
    }
    else if (input == 6 or input == 7){
        cout << 7;
    }
    else if (input >= 8 and input <= 11){
        cout << 11;
    }
    else if (input > 11){ // 세 자리 수 혹은 다섯 자리 수 팰린드롬
        if (input < 100){ // 두 자리 수
            input = 100;
        }
        else if (input >= 1000 and input < 10000){ // 네 자리 수
            input = 10000;
        }
        else if (input >= 100000){ // 여섯 자리 수 + 1000000
            input = 1000000;
        }

        int end = 0;
        while (!end){
            if (check_if_palindrome(input) == 0){
                input++;
            }
            else if (check_if_palindrome(input) == 1){
                if (check_if_prime(input) == 1){
                    end = 1;
                    cout << input;
                }
                else{
                    input++;
                }
            }
            else if (check_if_palindrome(input) == 4){
                input = 10000;
            }
            else if (check_if_palindrome(input) == 6){
                input = 1000000;
            }
        }
    }

    
    return 0;
}
