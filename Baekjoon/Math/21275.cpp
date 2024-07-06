#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>

using namespace std;

map<int, long long> first_map;

vector< pair<long long, int> > answers;

long long printing = pow(2, 63);

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string first, second;
    cin >> first >> second;

    if (first == "0" and second == "0"){
        cout << "Multiple";
        return 0;
    }

    // 0 0 - 1 1 - 2 2 - 3 3 - 4 4 - 5 5 - 6 6 - 7 7 - 8 8 - 9 9 (42)
    // a 10 - b 11 - c 12 - d 13 - e 14 - f 15 - g 16 - h 17 - i 18 - j 19
    // k 20 - l 21 - m 22 - n 23 - o 24 - p 25 - q 26 - r 27 - s 28 - t 29
    // u 30 - v 31 - w 32 - x 33 - y 34 - z 35 (122)

    // first 쭉 돌면서 가장 큰 digit이라고 해야 되나 0~9까지 있으면 10진법부터 가능 등등 확인 필요
    int highest = 0;
    for (int i = 0; i < first.length(); i++){
        if ((int)first[i] >= 48 and (int)first[i] < 58){
            if ((int)first[i] > highest){
                highest = (int)first[i];
            }
        }
        else{
            if ((int)first[i] > highest){
                highest = (int)first[i];
            }
        }
    }

    int k = 0;
    if (highest >= 48 and highest < 58){
        k = highest - 48;
    }
    else{
        k = highest - 87;
    }

    for (int i = k+1; i < 37; i++){
        int size = first.length();
        long long total_first = 0;
        for (int j = size-1; j >= 0; j--){
            if ((int)first[j] >= 48 and (int)first[j] < 58){
                total_first += (first[j] - '0') * pow(i, size-1-j);
            }
            else{
                total_first += ((int)first[j] - 87) * pow(i, size-1-j);
            }
        }
        if (total_first > 0 and total_first != printing){
            first_map.insert(make_pair(total_first, i));
        }
        
    }

    // second도 쭉 돌면서 제일 큰 digit에 따라서 i 시작점 찾아야됨
    int highest_ = 0;
    for (int i = 0; i < second.length(); i++){
        if ((int)second[i] >= 48 and (int)second[i] < 58){
            if ((int)second[i] > highest_){
                highest_ = (int)second[i];
            }
        }
        else{
            if ((int)second[i] > highest_){
                highest_ = (int)second[i];
            }
        }
    }

    int l = 0;
    if (highest_ >= 48 and highest_ < 58){
        l = highest_ - 48;
    }
    else{
        l = highest_ - 87;
    }

    for (int i = l+1; i < 37; i++){
        int size = second.length();
        long long total_second = 0;
        for (int j = size-1; j >= 0; j--){
            if ((int)second[j] >= 48 and (int)second[j] < 58){
                total_second += (second[j] - '0') * pow(i, size-1-j);
            }
            else{
                total_second += ((int)second[j] - 87) * pow(i, size-1-j);
            }
        }
        if (first_map.find(total_second) != first_map.end()){
            if (first_map[total_second] != i){
                answers.push_back(make_pair(total_second, i));
            }
        }
    }

    if (answers.size() == 0){
        cout << "Impossible";
    }
    else if (answers.size() == 1){
        int n = first_map[answers[0].first];
        cout << answers[0].first << " " << n << " " << answers[0].second;
    }
    else{
        cout << "Multiple";
    }
    
    return 0;
}
