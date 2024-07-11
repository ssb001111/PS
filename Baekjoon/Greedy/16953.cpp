#include <iostream>
#include <string>
#include <algorithm>

using namespace std; 
 
int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,b;
    cin >> a >> b;

    int count = 0;

    int mid = b;

    while (mid > a){
        if ((mid - 1) % 10 == 0){
            count += 1;
            mid = (mid-1) / 10;
        }
        else if (mid % 2 == 0){
            count += 1;
            mid = mid / 2;
        }
        else{
            cout << -1;
            return 0;
        }
    }

    if (mid == a){
        cout << count + 1;
    }
    else{
        cout << -1;
    }


        
    return 0;
}
