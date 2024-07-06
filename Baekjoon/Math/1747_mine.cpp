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
        if (input < 102){ // 두 자리 수
            cout << 101;
            return 0;
        }
        else if (input >= 102 and input < 1000){ // 세 자리 수

            if (input == 999){
                cout << 10301;// 다섯 자리 수 중 가장 작은 소수 팰린드롬
            }
            else{

                string start_string = to_string(input);

                // input보다 큰 가장 작은 팰린드롬 찾기
                string first = "";
                first += start_string[0];
                string second = "";
                second += start_string[1];
                string third = "";
                third += start_string[2];

                if (first != third){
                    if (stoi(first) > stoi(third)){
                        start_string[2] = start_string[0];
                    }
                    else{
                        if (start_string[1] == '9'){
                            start_string[0] = stoi(first) + 1 + '0';
                            start_string[1] = '0';
                            start_string[2] = start_string[0];
                        }
                        else{
                            start_string[1] = stoi(second) + 1 + '0';
                            start_string[2] = start_string[0];
                        }
                    }
                }
                int start_int = stoi(start_string);

                // 그 팰린드롬이 소수인지 판별, 만약 아니라면 새로운 팰린드롬 설정
                int found_answer = 0;
                while (!found_answer){

                    int starting_ = start_int;

                    int check = check_if_prime(starting_);

                    if (check == 1){ 
                        found_answer = 1; // 소수임
                        cout << start_string;
                    }

                    else{ // 결국은 소수가 아니었음. 다음 팰린드롬!
                        string first = "";
                        first += start_string[0];
                        string second = "";
                        second += start_string[1];
                        string third = "";
                        third += start_string[2];

                        if (stoi(second) >= 0 and stoi(second) < 9){
                            char ch = stoi(second) + 1 + '0';
                            start_string[1] = ch;
                        }
                        else{
                            start_string[1] = '0';
                            char ch = stoi(first) + 1 + '0';
                            if (stoi(first) == 9){
                                // 원래 999였던 것
                                // 다섯 자리 수 중 가장 작은 소수 팰린드롬 print
                                found_answer = 1;
                                cout << 10301;
                            }
                            else{
                                start_string[0] = ch;
                                start_string[2] = ch;
                            }
                            
                        }
                        start_int = stoi(start_string);
                    }
                }
            }
        }
        else if (input >= 1000 and input < 10302){ // 네 자리 수
            cout << 10301; // 다섯 자리 수 중 가장 작은 팰린드롬
        }
        else if (input >= 10302 and input < 100000){ // 다섯 자리 수

            if (input == 99999){
                cout << 1003001;// 일곱 자리 수 중 가장 작은 소수 팰린드롬
            }
            else{
                string start_string = to_string(input);

                // input보다 큰 가장 작은 팰린드롬 찾기
                string first = "";
                first += start_string.substr(0,2);
                string second = "";
                second += start_string[2];
                string third = "";
                third += start_string[4];
                third += start_string[3];

                if (first != third){
                    if (stoi(first) > stoi(third)){
                        start_string[3] = start_string[1];
                        start_string[4] = start_string[0];
                    }
                    else{
                        if (second == "9"){
                            string new_ = to_string(stoi(first) + 1);
                            start_string[0] = new_[0];
                            start_string[1] = new_[1];
                            start_string[2] = '0';
                            start_string[3] = new_[1];
                            start_string[4] = new_[0];
                        }
                        else{
                            start_string[2] = stoi(second) + 1 + '0';
                            start_string[3] = start_string[1];
                            start_string[4] = start_string[0];
                        }
                    }
                }
                int start_int = stoi(start_string);

                // 그 팰린드롬이 소수인지 판별, 만약 아니라면 새로운 팰린드롬 설정
                int found_answer = 0;
                while (!found_answer){
                    int found_div = 0; // 약수를 찾았는지
                    // 소수 판별
                    int starting_ = start_int;

                    int check = check_if_prime(start_int);

                    if (check == 1){ 
                        found_answer = 1;
                        cout << start_string;
                    }
                    else{
                        string first = "";
                        first += start_string.substr(0,2);
                        string second = "";
                        second += start_string[2];
                        string third = "";
                        third += start_string.substr(3);
                        
                        if (stoi(second) >= 0 and stoi(second) < 9){
                            char ch = stoi(second) + 1 + '0';
                            start_string[2] = ch;
                        }
                        else{
                            start_string[2] = '0';
                            string ch = to_string(stoi(first) + 1);
                            if (stoi(first) == 99){
                                // 원래 99999였던 것
                                // 일곱 자리 수 중 가장 작은 팰린드롬 필요
                                found_answer = 1;
                                cout << 1003001;
                            }
                            else{
                                start_string[0] = ch[0];
                                start_string[1] = ch[1];
                                start_string[3] = ch[1];
                                start_string[4] = ch[0];
                            }
                        }
                        start_int = stoi(start_string);
                    }
                }
            }
        }
        else if (input >= 100000){ // 여섯 자리 수 + 1000000
            cout << 1003001;
        }
    }

    
    return 0;
}
