#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

map<int, int> m;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int c, n;
    cin >> c >> n;

    int largest_of_cust = 0;

    for (int i = 0; i < n; i++){
        int money, customer;
        cin >> money >> customer;
        if (m.find(customer) != m.end()){
            m[customer] = min(m[customer], money);
        }
        else{
            m[customer] = money;
        }
        largest_of_cust = max(largest_of_cust, customer);
    }

    int arr[c+largest_of_cust];
    arr[0] = 0;

    int minimum = 110001;

    for (int i = 1; i < c+largest_of_cust; i++){
        int result = 110001;
        for (auto iter = m.begin(); iter != m.end(); iter++){
            if (i - iter->first > -1){
                result = min(result, arr[i - iter->first] + iter->second);
            }
        }
        arr[i] = result;
        if (i >= c){
            minimum = min(minimum, result);
        }
    }

    cout << minimum;

    return 0;
}
