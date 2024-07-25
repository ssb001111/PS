#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int f,s;
    cin >> f >> s;

    int first_arr[f];
    int second_arr[s];

    for (int i = 0; i < f; i++){
        cin >> first_arr[i];
    }
    for (int i = 0; i < s; i++){
        cin >> second_arr[i];
    }

    int final[f+s];

    int first = 0;
    int second = 0;

    for (int i = 0; i < f+s; i++){
        if (first < f and second < s){
            if (first_arr[first] > second_arr[second]){
                final[i] = second_arr[second];
                second++;
            }
            else{
                final[i] = first_arr[first];
                first++;
            }
        }
        else{
            if (first == f and second != s){
                final[i] = second_arr[second];
                second++;
            }
            else{
                final[i] = first_arr[first];
                first++;
            }
        }
    }

    for (int i = 0; i < f+s-1; i++){
        cout << final[i] << " ";
    }
    cout << final[f+s-1];

    return 0;
}
