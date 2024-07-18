#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector< pair<int, int> > v;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,k;
    cin >> n >> k;

    int curr_left = 0;
    int prev = 0;

    for (int i = 0; i < n; i++){
        int s;
        cin >> s;
        
        if (s % 2 == 0){
            if (curr_left == 1){ // 지금 짝수인데, 이전에 홀수였음
                v.push_back(make_pair(prev, curr_left));
                curr_left = 0;
                prev = 1;
            }
            else{ // 첫 숫자이거나, 지금 짝수인데 이전에도 짝수였음
                prev++;
            }
        }
        else{
            if (curr_left == 0){
                if (prev == 0){ // 첫 숫자
                    curr_left = 1;
                    prev = 1;
                }
                else{ // 지금 홀수인데, 이전에 짝수였음
                    v.push_back(make_pair(prev, curr_left));
                    curr_left = 1;
                    prev = 1;
                }
            }
            else{ // 지금 홀수인데, 이전에 홀수였음
                prev++;
            }
        }
    }
    v.push_back(make_pair(prev, curr_left));

    int longest = 0;
    for (int i = 0; i < v.size(); i++){
        if (v[i].second == 0){
            int length = v[i].first;
            int curr = i+1;
            if (curr != v.size()){
                int l = k-v[curr].first;
                while (l >= 0){
                    curr++;
                    if (curr != v.size()){
                        length += v[curr].first;
                        curr++;
                        if (curr != v.size()){
                            l = l-v[curr].first;
                        }
                        else{
                            break;
                        }
                    }
                    else{
                        break;
                    } 
                }
            }
            if (longest < length){
                longest = length;
            }
        }
    }

    cout << longest;

    return 0;
}
