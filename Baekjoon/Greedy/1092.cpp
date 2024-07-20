#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

vector<int> cranes;
vector<int> boxes;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    set<int> s;

    int n;
    cin >> n;
    cranes = vector<int>(n);
    for (int i = 0; i < n; i++){
        cin >> cranes[i];
    }
    int m;
    cin >> m;
    boxes = vector<int>(m);
    for (int i = 0; i < m; i++){
        cin >> boxes[i];
    }
    
    stable_sort(cranes.begin(), cranes.end(), greater<int>());
    stable_sort(boxes.begin(), boxes.end(), greater<int>());

    if (boxes[0] > cranes[0]){
        cout << -1;
    }
    else{
        int result = 0;
        int the_first = 0;
        while (s.size() != m){
            int curr = the_first;
            int the_first_ind = 0;

            int scan = 0;
            while (scan != n){
                if (curr == m){
                    break;
                }
                else if (s.find(curr) == s.end()){
                    int e = boxes[curr];
                    int f = cranes[scan];
                    if (e <= f){
                        s.insert(curr);
                        curr++;
                        scan++;
                    }
                    else{
                        if (the_first_ind == 0){
                            the_first = curr;
                            the_first_ind = 1;
                        }
                        curr++;
                    }
                }
                else{
                    curr++;
                }
                
            }
            result++;
        }

        cout << result;
    }

    return 0;
}
