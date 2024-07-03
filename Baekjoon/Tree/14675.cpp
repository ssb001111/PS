#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    
    set<int> connected[n+1]; // 연결상태
    
    for (int i = 0; i < n - 1; i++) {
        int first, second;
        cin >> first >> second;
        connected[first].insert(second);
        connected[second].insert(first);
    }

    int q;
    cin >> q;

    string arr[q];

    for (int i = 0; i < q; i++){

        int first, second;
        cin >> first >> second;

        if (first == 1){ // 단절점
            if (connected[second].size() > 1){
                arr[i] = "yes";
            }
            else{
                arr[i] = "no";
            }
        }

        else{ // 단절선
            arr[i] = "yes";
        }
    }

    for (int i = 0; i < q; i++){
        cout << arr[i] << "\n";
    }

    return 0;
}
