#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector< pair<int, int> > v;
vector< pair<int, int> > res;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    v = vector< pair<int, int> >(n-1);
    res = vector< pair<int, int> >(n);

    for (int i = 0; i < n-1; i++){
        int f,s;
        cin >> f >> s;

        v[i].first = f;
        v[i].second = s;
    }

    res[0].first = 0;
    res[0].second = 0;

    if (n >= 2){
        res[1].first = v[0].first;
        res[1].second = 0;
    }
    
    if (n >= 3){
        int k = 0;
        if (v[0].second < res[1].first + v[1].first){
            k = v[0].second;
        }
        else{
            k = res[1].first + v[1].first;
        }
        res[2].first = k;
        res[2].second = 0;
    }

    int k;
    cin >> k;

    for (int i = 3; i < n; i++){
        int first = res[i-1].first + v[i-1].first;
        if (res[i-2].first + v[i-2].second < first){
            first = res[i-2].first + v[i-2].second;
        }

        int second = res[i-3].first + k;
        if (i >= 5){
            if (res[i-2].second + v[i-2].second < second){
                second = res[i-2].second + v[i-2].second;
            }
        }
        if (i >= 4){
            if (res[i-1].second + v[i-1].first < second){
                second = res[i-1].second + v[i-1].first;
            }
        }
        res[i].first = first;
        res[i].second = second;
    }

    int result = 0;
    if (n >= 4){
        result = min(res[n-1].first, res[n-1].second);
    }
    else{
        result = res[n-1].first;
    }

    cout << result;

    return 0;
}
