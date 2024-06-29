#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

priority_queue<int> greatest;
priority_queue< int, vector<int>, greater<int> > lowest;
map<int, int> cnt;

void deleteMinimum(){
    if (!lowest.empty()){
        int l = lowest.top();
        lowest.pop();
        cnt[l] -= 1;
        if (cnt[l] == 0){
            cnt.erase(l);
        }
    }
}

void deleteMaximum(){
    if (!greatest.empty()){
        int g = greatest.top();
        greatest.pop();
        cnt[g] -= 1;
        if (cnt[g] == 0){
            cnt.erase(g);
        }
    }
}

void func_for_both_queues(){
    int end = 0;

    while (!lowest.empty() and end == 0){
        int x = lowest.top();
        if (cnt.find(x) != cnt.end()){
            end = 1;
        }
        else{
            lowest.pop();
        }
    }

    end = 0;

    while (!greatest.empty() and end == 0){
        int x = greatest.top();
        if (cnt.find(x) != cnt.end()){
            end = 1;
        }
        else{
            greatest.pop();
        }
    }
}

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int no_of_test;
    cin >> no_of_test;

    string pr_arr[no_of_test];

    for (int i = 0; i < no_of_test; i++){

        // 매 test case 전 2개의 priority queue와 map에 들어가 있는 모든 element 지워주기
        while (!greatest.empty()){
            greatest.pop();
        }
        while (!lowest.empty()){
            lowest.pop();
        }
        if (!cnt.empty()){
            cnt.clear();
        }

        int no;
        cin >> no;
        
        for (int j = 0; j < no; j++){

            string cmd;
            int num;
            cin >> cmd >> num;

            if (cmd == "I"){ // Insert
                greatest.push(num);
                lowest.push(num);
                if (cnt.find(num) != cnt.end()){
                    cnt[num] += 1;
                }
                else{
                    cnt.insert(make_pair(num, 1));
                }
            }

            else{ // Delete
                if (num == -1) { // D -1
                    deleteMinimum();
                }
                else { // D 1
                    deleteMaximum();
                }
                func_for_both_queues();
            }
        }

        if (cnt.empty()){
            pr_arr[i] = "EMPTY";
        }
        else{
            string s;
            s += to_string(greatest.top());
            s += " ";
            s += to_string(lowest.top());
            pr_arr[i] = s;
        }

    }

    for (int i = 0; i < no_of_test; i++){
        cout << pr_arr[i] << "\n";
    }

    return 0;
}
