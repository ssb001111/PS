#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> sums;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int arr[n];

    int sum = 0;

    for (int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
        sums.push_back(sum);
    }

    int result = 0;

    // 1. 벌 - 벌 - 꿀통
    for (int i = 1; i < n-1; i++){
        result = max(result, sums[n-1]-sums[0]-arr[i] + sums[n-1]-sums[i]);
    }

    // 2. 벌 - 꿀통 - 벌
    for (int i = 1; i < n-1; i++){
        result = max(result, sums[i]-sums[0] + sums[n-2]-sums[i-1]);
    }

    // 3. 꿀통 - 벌 - 벌
    for (int i = 1; i < n-1; i++){
        result = max(result, sums[n-2]-arr[i] + sums[i-1]);
    }

    cout << result;

    return 0;
}
