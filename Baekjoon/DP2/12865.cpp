#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

vector< pair<set<int>, int> > real;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector< pair<int, int> > vec;
    real = vector< pair<set<int>, int> >(k+1); // set = maximum까지 사용된 vec의 index들, int = maximum
    for (int i = 0; i < k+1; i++){
        set<int> s;
        real[i] = make_pair(s, 0);
    }

    for (int i = 0; i < n; i++){
        int w,v;
        cin >> w >> v;
        vec.push_back(make_pair(w,v));
    }

    stable_sort(vec.begin(), vec.end());

    int real_max_value = 0;

    for (int i = 1; i < k+1; i++){ // 1~k까지
        int maximum = -1;
        int max_index = -1;
        int max_prev_index = -1;
        for (int j = 0; j < n; j++){ // 모든 물건들 iterate
            int weight = vec[j].first;
            if (i - weight >= 0){ // 시도해볼 수라도 있는지
                if (real[i-weight].second != -1){ // i가 이전 + 현재의 물건의 weight를 더해 도달 가능한 숫자인지
                    set<int> already_used = real[i-weight].first;
                    if (already_used.find(j) == already_used.end()){ // 현재 물건이 이미 앞에서 사용되지 않았다면
                        int value = vec[j].second;
                        int prev_value = real[i-weight].second;
                        if (maximum < value + prev_value){
                            maximum = value + prev_value;
                            max_index = j;
                            max_prev_index = i-weight;
                        }
                    }
                }
            }
        }
        if (maximum == -1 and max_index == -1 and max_prev_index == -1){
            real[i].second = -1;
        }
        else{
            real[i].first = real[max_prev_index].first;
            real[i].first.insert(max_index);
            real[i].second = maximum;
            real_max_value = max(real_max_value, maximum);
        }
    }

    cout << real_max_value;

    return 0;
}
