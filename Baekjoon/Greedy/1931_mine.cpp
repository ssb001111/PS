#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

map< int, pair<int, int> > m;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        int s, e;
        cin >> s >> e;
        if (m.find(s) != m.end()){
            if (s == e){
                m[s].first += 1;
            }
            else if (m[s].second != -1 and e < m[s].second){
                m[s].second = e;
            }
            else if (m[s].second == -1){
                m[s].second = e;
            }
        }
        else{
            if (s == e){
                m[s] = make_pair(1, -1);
            }
            else{
                m[s] = make_pair(0, e);
            }
            
        }
    }

    stack< pair<int, int> > st;

    for (auto iter = m.begin(); iter != m.end(); iter++){
        if (st.empty()){
            if (iter->second.first == 0){
                st.push(make_pair(iter->first, iter->second.second));
            }
            else{
                for (int i = 0; i < iter->second.first; i++){
                    st.push(make_pair(iter->first, iter->first));
                }
                if (iter->second.second != -1){
                    st.push(make_pair(iter->first, iter->second.second));
                }
            }
        }
        else{
            int last_start = st.top().first;
            int last_end = st.top().second;
            if (iter->second.second != -1){
                if (iter->first < last_end and iter->second.second < last_end){

                    st.pop();

                    for (int i = 0; i < iter->second.first; i++){
                        st.push(make_pair(iter->first, iter->first));
                    }
                    if (iter->second.second != -1){
                        st.push(make_pair(iter->first, iter->second.second));
                    }
                }
                else if ((iter->first < last_end and iter->second.second >= last_end)){
                    continue;
                }
                else if (iter->first >= last_end){
                    
                    for (int i = 0; i < iter->second.first; i++){
                        st.push(make_pair(iter->first, iter->first));
                    }
                    if (iter->second.second != -1){
                        st.push(make_pair(iter->first, iter->second.second));
                    }
                }
            }
            else{
                if (iter->first < last_end){
                    st.pop();
                }

                for (int i = 0; i < iter->second.first; i++){
                    st.push(make_pair(iter->first, iter->first));
                }
            }
            
        }
    }

    cout << st.size();
    
    return 0;
}
