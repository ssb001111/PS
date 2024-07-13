#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string str;
    cin >> str;

    stack<string> largest;
    stack<string> smallest;

    string large = "";
    string small = "";

    int size = 0;

    for (int i = 0; i < str.length(); i++){
        if (str[i] == 'M'){
            largest.push("M");
            smallest.push("M");
        }
        else{ // K
            if (!largest.empty()){
                // largest
                size = largest.size();
                large += "5";
                for (int j = 0; j < size; j++){
                    large += "0";
                    largest.pop();
                }

                // smallest
                size = smallest.size();
                small += "1";
                for (int j = 0; j < size-1; j++){
                    small += "0";
                    smallest.pop();
                }
                smallest.pop();
                small += "5";
            }
            else{
                // largest & smallest
                large += "5";
                small += "5";
            }
        }
    }

    if (!largest.empty()){
        // largest
        size = largest.size();
        for (int j = 0; j < size; j++){
            large += "1";
            largest.pop();
        }

        // largest
        size = smallest.size();
        small += "1";
        for (int j = 0; j < size-1; j++){
            small += "0";
            smallest.pop();
        }
        smallest.pop();
    }

    cout << large << "\n";
    cout << small;
    
    return 0;
}
