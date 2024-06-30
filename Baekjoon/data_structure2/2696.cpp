#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

priority_queue< int, vector<int>, greater<int> > q;
stack<int> s;
queue<int> pr;
queue<int> real_pr;

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int no_of_testcases;
    cin >> no_of_testcases;

    for (int i = 0; i < no_of_testcases; i++){
        int no_of_nums;
        cin >> no_of_nums;

        for (int j = 0; j < no_of_nums; j++){

            int number;
            cin >> number;

            q.push(number);
            if (j % 2 == 0){
                if (pr.empty()){
                    // cout << "empty!" << "\n";
                    pr.push(number);
                }
                else{
                    // cout << "j: " << j << "\n";
                    int till = j / 2;
                    for (int k = 0; k < till; k++){
                        int curr = q.top();
                        q.pop();
                        s.push(curr);
                    }
                    pr.push(q.top());
                    for (int k = 0; k < till; k++){
                        int curr = s.top();
                        s.pop();
                        q.push(curr);
                    }
                }
            }
        }

        int size = pr.size();
        real_pr.push(size);
        for (int j = 0; j < size; j++){
            int top = pr.front();
            real_pr.push(top);
            pr.pop();
        }

        for (int j = 0; j < no_of_nums; j++){
            q.pop();
        }
    }

    while (!real_pr.empty()){
        int count = 0;
        int no_of_nums = real_pr.front();
        cout << no_of_nums << "\n";
        real_pr.pop();
        for (int i = 0; i < no_of_nums; i++){
            int num = real_pr.front();
            if (count == 9){
                cout << num << "\n";
                count = 0;
            }
            else{
                cout << num << " ";
                count++;
            }
            real_pr.pop();
        }
        cout << "\n";
    }

    return 0;
}
