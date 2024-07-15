#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

__uint128_t func(int n, int m){
    __uint128_t result = 1;
    __uint128_t mid = 1;
    for (int i = 0; i < n-m; i++){
        mid = mid * (m+i)/(i+1);
        result += mid;
    }
    return result;
}

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,m;
    cin >> n >> m;

    __uint128_t result = func(n, m);

    // 최대 10^29이므로 그 반 정도 되는 10^15로 나누어주기
    string r = "";
    string f = to_string((long long)(result / (__uint128_t) pow(10, 15)));
    string s = to_string((long long)(result % (__uint128_t) pow(10, 15)));
    if (f == "0"){
        r = s;
    }
    else{
        r = f + s;
    }

    cout << r;

    return 0;
}
