#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector< pair<int, int> > v;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        int s;
        cin >> s;
        
        if (v.empty()){
            v.push_back(make_pair(1, s));
        }
        else{
            int size = v.size();
            pair<int, int> p = make_pair(0, s);

            for (int j = 0; j < size; j++){
                if (v[j].second < p.second){
                    if (p.first < v[j].first){
                        p.first = v[j].first;
                    }
                }
            }
            
            p.first++;
            v.push_back(p);
        }
    }

    stable_sort(v.begin(), v.end(), greater< pair<int, int> >());
    cout << v[0].first;

    return 0;
}
