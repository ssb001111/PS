#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int main(){

    cin.tie(NULL);
		ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    queue<int> queue;
    vector<int> print;

    for (int i = 0; i < n; i++){
        string input;
        cin >> input;
        if (input.substr(0, 4) == "push"){
            int num;
            cin >> num;
            queue.push(num);
        }
        else if (input == "pop"){
            if (queue.empty()){
                print.push_back(-1);
            }
            else{
                print.push_back(queue.front());
                queue.pop();
            }
        }
        else if (input == "size"){
            print.push_back(queue.size());
        }
        else if (input  == "empty"){
            if (queue.empty()){
                print.push_back(1);
            }
            else{
                print.push_back(0);
            }
        }
        else if (input == "front"){
            if (queue.empty()){
                print.push_back(-1);
            }
            else{
                print.push_back(queue.front());
            }
        }
        else if (input == "back"){
            if (queue.empty()){
                print.push_back(-1);
            }
            else{
                print.push_back(queue.back());
            }
        }
    }

    for (int i = 0; i < print.size(); i++){
        cout << print[i] << "\n";
    }

    return 0;
}
