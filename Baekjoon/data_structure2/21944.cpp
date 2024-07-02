#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <queue>

using namespace std;

set< pair<int, int>, greater< pair<int, int> > >greatest1[101];
set< pair<int, int> >lowest1[101];
set< pair<int, int>, greater< pair<int, int> > > greatest23[101];
set< pair<int, int> > lowest23[101];

map< int, pair<int, int> > problems;

queue<int> pr_arr;

void add() {
    int pr_p, pr_l, pr_g;
    cin >> pr_p >> pr_l >> pr_g;
    greatest1[pr_g].insert(make_pair(pr_l, pr_p));
    lowest1[pr_g].insert(make_pair(pr_l, pr_p));
    greatest23[pr_l].insert(make_pair(pr_p, pr_g));
    lowest23[pr_l].insert(make_pair(pr_p, pr_g));
    problems[pr_p] = make_pair(pr_l, pr_g);
}

void recommend() {
    int G, x;
    cin >> G >> x;
    if (x == 1){
        int pr = greatest1[G].begin()->second;
        pr_arr.push(pr);
    }
    else if (x == -1){
        int pr = lowest1[G].begin()->second;
        pr_arr.push(pr);
    }
}

void recommend2() {
    int x;
    cin >> x;
    if (x == 1){
        for (int i = 1; i < 101; i++){
            if (!greatest23[101-i].empty()){
                int pr = greatest23[101-i].begin()->first;
                pr_arr.push(pr);
                break;
            }
        }
    }
    else if (x == -1){
        for (int i = 1; i < 101; i++){
            if (!lowest23[i].empty()){
                int pr = lowest23[i].begin()->first;
                pr_arr.push(pr);
                break;
            }
        }
    }
}

void recommend3() {
    int x, L;
    cin >> x >> L;
    int exist = 0;
    if (x == 1){
        for (int i = L; i < 101; i++){
            if (!lowest23[i].empty()){
                int pr = lowest23[i].begin()->first;
                pr_arr.push(pr);
                exist = 1;
                break;
            }
        }
        if (!exist){
            pr_arr.push(-1);
        }
    }
    else if (x == -1){
        for (int i = L-1; i >0; i--){
            if (!greatest23[i].empty()){
                int pr = greatest23[i].begin()->first;
                pr_arr.push(pr);
                exist = 1;
                break;
            }
        }
        if (!exist){
            pr_arr.push(-1);
        }
    }
}

void solved() {
    int x;
    cin >> x;
    int l = problems[x].first;
    int g = problems[x].second;
    problems.erase(x);
    greatest1[g].erase(make_pair(l, x));
    lowest1[g].erase(make_pair(l, x));
    greatest23[l].erase(make_pair(x, g));
    lowest23[l].erase(make_pair(x, g));
}

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    // 일단 input 받기

    int no_of_input;
    cin >> no_of_input;

    for (int i = 0; i < no_of_input; i++) {
        add();
    }

    // 추가 명령어

    int no_of_addi;
    cin >> no_of_addi;

    for (int i = 0; i < no_of_addi; i++) {
        string command;
        cin >> command;

        if (command == "add") {
            add();
        }
        else if (command == "recommend") {
            recommend();
        }
        else if (command == "recommend2") {
            recommend2();
        }
        else if (command == "recommend3") {
            recommend3();
        }
        else if (command == "solved") {
            solved();
        }
    }

    int size = pr_arr.size();
    for (int i = 0; i < size; i++) {
        int top = pr_arr.front();
        cout << top << "\n";
        pr_arr.pop();
    }

    return 0;
}
