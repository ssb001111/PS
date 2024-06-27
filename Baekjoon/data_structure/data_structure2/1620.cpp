#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main(){

    cin.tie(NULL);
		ios_base::sync_with_stdio(false);

    int no_of_pocketmon;
    cin >> no_of_pocketmon;

    int no_of_questions;
    cin >> no_of_questions;

    map<string, string> map;
    string arr[no_of_questions];

    for (int i = 0; i < no_of_pocketmon; i++){
        string insert;
        cin >> insert;
        map.insert(make_pair(insert, to_string(i+1)));
        map.insert(make_pair(to_string(i+1), insert));
    }

    for (int i = 0; i < no_of_questions; i++){
        string insert;
        cin >> insert;
        arr[i] = map.find(insert)->second;
    }

    for (int i = 0; i < no_of_questions; i++){
        cout << arr[i] << "\n";
    }
    
    return 0;
}
