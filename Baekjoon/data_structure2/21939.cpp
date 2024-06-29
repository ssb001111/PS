#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

priority_queue< pair<int, int> > greatest;
priority_queue< pair<int, int> , vector< pair<int, int> >, greater< pair<int, int> > > lowest;
map<int, int> m;

vector<int> pr_arr;

void seeMinimum(){
    if (!lowest.empty()){
        int l = lowest.top().second;
        pr_arr.push_back(l);
    }
}

void seeMaximum(){
    if (!greatest.empty()){
        int g = greatest.top().second;
        pr_arr.push_back(g);
    }
}

void func_for_both_queues(){

    int end = 0;

    while (!lowest.empty() and end == 0){
        int x = lowest.top().second;
        if (m.find(x) != m.end()){
            if (lowest.top().first == m[x]){
                end = 1;
            }
            else{
                lowest.pop();
            }
        }
        else{
            lowest.pop();
        }
    }

    end = 0;

    while (!greatest.empty() and end == 0){
        int x = greatest.top().second;
        if (m.find(x) != m.end()){
            if (greatest.top().first == m[x]){
                end = 1;
            }
            else{
                greatest.pop();
            }
        }
        else{
            greatest.pop();
        }
    }
}

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int no_of_initial_problems;
    cin >> no_of_initial_problems;

    for (int i = 0; i < no_of_initial_problems; i++){
        int hardness, no;
        cin >> no >> hardness;
        m[no] = hardness;
        greatest.push(make_pair(hardness, no));
        lowest.push(make_pair(hardness, no));
    }

    int no_of_cmd;
    cin >> no_of_cmd;

    for (int i = 0; i < no_of_cmd; i++){

        string cmd;
        int num_of_p;
        cin >> cmd >> num_of_p;

        if (cmd == "add"){
            int how_hard;
            cin >> how_hard;
            greatest.push(make_pair(how_hard, num_of_p));
            lowest.push(make_pair(how_hard, num_of_p));
            m[num_of_p] = how_hard;
        }
        else if (cmd == "recommend"){
            if (num_of_p == 1){
                seeMaximum();
            }
            else{
                seeMinimum();
            }
        }
        else if (cmd == "solved"){
            m.erase(num_of_p);
            func_for_both_queues();
        }
    }

    int size = pr_arr.size();
    for (int i = 0; i < size; i++){
        cout << pr_arr[i] << "\n";
    }

    return 0;
}
