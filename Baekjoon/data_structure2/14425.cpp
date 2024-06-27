#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main(){

    cin.tie(NULL);
	  ios_base::sync_with_stdio(false);

    int no;
    cin >> no;

    int no_of_str_to_test;
    cin >> no_of_str_to_test;

    set<string> set;

    for (int i = 0; i < no; i++){
        string insert;
        cin >> insert;
        set.insert(insert);
    }

    int number = 0;

    for (int i = 0; i < no_of_str_to_test; i++){
        string insert;
        cin >> insert;
        if (set.find(insert) != set.end()){
            number += 1;
        }
    }
    
    cout << number;

    return 0;
}
