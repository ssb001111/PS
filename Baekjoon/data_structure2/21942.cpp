#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

map<int, int> calendar;
map<string, long long> penalty;
map<string, int> find_lend;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    for (int i = 1; i < 13; i++){
        if (i == 1 or i == 3 or i == 5 or i == 7 or i == 8 or i == 10 or i == 12){
            calendar[i] = 31;
        }
        else if (i == 2){
            calendar[i] = 28;
        }
        else{
            calendar[i] = 30;
        }
    }

    int N;
    double F;
    string L;
    cin >> N >> L >> F;

    int date = stoi(L.substr(0,3));
    int hour = stoi(L.substr(4, 2));
    int minute = stoi(L.substr(7));

    int allowed_minute = minute + hour * 60 + date * 24 * 60;

    for (int i = 0; i < N; i++){
        string date_, time, eq, name;
        cin >> date_ >> time >> eq >> name;

        int num = 0;

        int month = stoi(date_.substr(5,2));
        int day = stoi(date_.substr(8));
        int hour_ = stoi(time.substr(0,2));
        int minute_ = stoi(time.substr(3,2));

        if (month == 1){
            num = day * 24 * 60 + hour_ * 60 + minute_;
        }
        else{
            for (int j = 1; j < month; j++){
                num += calendar[j];
            }
            num += day;
            num = num * 24 * 60;
            num += hour_ * 60 + minute_;
        }

        string s = name + " " + eq;

        if (find_lend.find(s) != find_lend.end()){
            int no = find_lend[s];
            find_lend.erase(s);
            int taken_minute = num - no;
            if (taken_minute <= allowed_minute){
                continue;
            }
            else{
                int over_minute = taken_minute - allowed_minute;
                if (penalty.find(name) != penalty.end()){
                    penalty[name] += over_minute * F;
                }
                else{
                    penalty[name] = over_minute * F;
                }
            }
        }
        else{
            find_lend[s] = num;
        }
        
    }

    if (!penalty.empty()){
        for (auto iter = penalty.begin(); iter != penalty.end(); iter++ ){
            cout << iter->first << " " << iter->second << "\n";
        }
    }
    else{
        cout << -1;
    }

    return 0;
}
