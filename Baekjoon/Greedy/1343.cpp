#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    string input;
    cin >> input;

    for (int i = 0; i < input.length(); i++){
        if (input[i] != '.'){
            if (v.empty()){
                v.push_back(1);
            }
            else{
                if (v[v.size()-1] == 0){
                    v.push_back(1);
                }
                else{
                    v[v.size()-1] += 1;
                }
            }
        }
        else{
            v.push_back(0);
        }
            
    }

    string output = "";
    for (int i = 0; i < v.size(); i++){
        if (v[i] == 0){
            output += ".";
        }
        else{
            int no_of_four = v[i] / 4;
            int left = v[i] % 4;
            int no_of_two = 0;

            int found = 0;
            while (no_of_four != -1 and !found){
                if (left % 2 == 0){
                    no_of_two = left / 2;
                    found = 1;
                }
                else{
                    no_of_four--;
                    left += 4;
                }
            }
            if (found == 1){
                for (int j = 0; j < no_of_four; j++){
                    output += "AAAA";
                }
                for (int j = 0; j < no_of_two; j++){
                    output += "BB";
                }
            }
            else{
                cout << -1;
                return 0;
            }
        }
    }

    cout << output;
    
    return 0;
}
