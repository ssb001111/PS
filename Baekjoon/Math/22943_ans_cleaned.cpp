#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int K, M, answer;
vector<int> prime_numbers;
vector<bool> sum_of_prime_numbers;
vector<bool> product_of_prime_numbers;

void get_prime_numbers(int length){
    int prime[length];

    for (int i = 2; i < length; i++){
        prime[i] = true;
    }
    for (int i = 2; i*i < length; i++){
        if (prime[i] == true){
            for (int j = i*i; j < length; j+= i){
                prime[j] = false;
            }
        }
    }

    int j = 0;
    for (int i = 2; i < length; i++){
        if (prime[i] == true){
            prime_numbers[j] = i;
            j++;
        }
    }
    prime_numbers.resize(j);
}

void get_sum(int length){
    for (int i = 0; i < prime_numbers.size(); i++){
        for (int j = i+1; j < prime_numbers.size(); j++){
            int val = prime_numbers[i] + prime_numbers[j];
            if (val < length){
                sum_of_prime_numbers[val] = true;
            }
        }
    }
}

void get_product(int length){
    for (int i = 0; i < prime_numbers.size(); i++){
        for (int j = i; j < prime_numbers.size(); j++){
            long long val = (long long)prime_numbers[i] * (long long)prime_numbers[j];
            if (val < (long long)length){
                product_of_prime_numbers[val] = true;
            }
        }
    }
}

bool inBoth(int num){
    if (sum_of_prime_numbers[num] == false){
        return false;
    }
    else{
        while (num % M == 0){
            num = num / M;
        }
        if (product_of_prime_numbers[num] == false){
            return false;
        }
        else{
            return true;
        }
    }
}

bool used[10] = {false,};

void makenumberandcheck(int length_left, int current_num){
    if (length_left == 0){
        if (inBoth(current_num) == true){
            answer++;
        }
        return;
    }
    else{
        if (length_left == K){
            for (int i = 1; i < 10; i++){
                used[i] = true;
                makenumberandcheck(K-1, i);
                used[i] = false;
            }
        }
        else{
            for (int i = 0; i < 10; i++){
                if (used[i] == false){
                    used[i] = true;
                    makenumberandcheck(length_left-1, 10*current_num+i);
                    used[i] = false;
                }
            }
        }
    }
}


int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> K >> M;

    answer = 0;
    int length = pow(10, K);
    prime_numbers = vector<int>(length);
    sum_of_prime_numbers = vector<bool>(length);
    product_of_prime_numbers = vector<bool>(length);
    for (int i = 0; i < length; i++){
        sum_of_prime_numbers[i] = false;
        product_of_prime_numbers[i] = false;
    }
    
    get_prime_numbers(length);
    get_sum(length);
    get_product(length);

    makenumberandcheck(K, 0);

    cout << answer;

    return 0;
}
