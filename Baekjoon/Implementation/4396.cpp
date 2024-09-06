#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    string comp[n][n];
    string real[n][n];

    vector< pair<int, int> > v;

    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        for (int j = 0; j < n; j++){
            comp[i][j] = s[j];
            if (s[j] == '*'){
                v.push_back(make_pair(i, j));
            }
        }
    }

    int open = 0;

    for (int i = 0; i < n; i++){
        string st;
        cin >> st;
        for (int j = 0; j < n; j++){
            string s = "";
            s += st[j];
            int num = 0;
            if (s == "x"){
                if (comp[i][j] != "*"){
                    if (i > 0){
                        if (comp[i-1][j] == "*"){
                            num++;
                        }
                    }
                    if (i < n-1){
                        if (comp[i+1][j] == "*"){
                            num++;
                        }
                    }
                    if (j > 0){
                        if (comp[i][j-1] == "*"){
                            num++;
                        }
                    }
                    if (j < n-1){
                        if (comp[i][j+1] == "*"){
                            num++;
                        }
                    }

                    if (i > 0 and j > 0){
                        if (comp[i-1][j-1] == "*"){
                            num++;
                        }
                    }
                    if (i > 0 and j < n-1){
                        if (comp[i-1][j+1] == "*"){
                            num++;
                        }
                    }
                    if (i < n-1 and j > 0){
                        if (comp[i+1][j-1] == "*"){
                            num++;
                        }
                    }
                    if (i < n-1 and j < n-1){
                        if (comp[i+1][j+1] == "*"){
                            num++;
                        }
                    }
                    real[i][j] = to_string(num);
                }
                else{
                    open = 1;
                }
            }
            else{
                real[i][j] = ".";
            }    
        }
    }

    if (open){
        for (int i = 0; i < v.size(); i++){
            int x = v[i].first;
            int y = v[i].second;
            real[x][y] = "*";
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << real[i][j];
        }
        cout << "\n";
    }

    return 0;
}
