#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,x;
    cin >> n >> x;

    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    map<int, int> m;

    int front = 0;
    int back = x-1;

    int previous = 0;
    for (int i = 0; i < x; i++){
        previous += arr[i];
    }

    m[previous] = 1;

    int largest = previous;

    for (int i = 1; i < n-x+1; i++){
        front = i;
        back = front + x-1;

        int new_num = previous - arr[front-1] + arr[back];

        largest = max(new_num, largest);

        if (m.find(new_num) != m.end()){
            m[new_num]++;
        }
        else{
            m[new_num] = 1;
        }

        previous = new_num;
    }

    if (largest == 0){
        cout << "SAD";
    }
    else{
        cout << largest << "\n";
        cout << m[largest];
    }

    return 0;
}
