#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    map<string, pair<int, int> > m;

    m["q"] = make_pair(0, 0);
    m["w"] = make_pair(0, 1);
    m["e"] = make_pair(0, 2);
    m["r"] = make_pair(0, 3);
    m["t"] = make_pair(0, 4);
    m["y"] = make_pair(0, 5);
    m["u"] = make_pair(0, 6);
    m["i"] = make_pair(0, 7);
    m["o"] = make_pair(0, 8);
    m["p"] = make_pair(0, 9);

    m["a"] = make_pair(1, 0);
    m["s"] = make_pair(1, 1);
    m["d"] = make_pair(1, 2);
    m["f"] = make_pair(1, 3);
    m["g"] = make_pair(1, 4);
    m["h"] = make_pair(1, 5);
    m["j"] = make_pair(1, 6);
    m["k"] = make_pair(1, 7);
    m["l"] = make_pair(1, 8);

    m["z"] = make_pair(2, 0);
    m["x"] = make_pair(2, 1);
    m["c"] = make_pair(2, 2);
    m["v"] = make_pair(2, 3);
    m["b"] = make_pair(2, 4);
    m["n"] = make_pair(2, 5);
    m["m"] = make_pair(2, 6);

    string a,b;
    cin >> a >> b;

    pair<int, int> left = m[a];
    int left_x = left.first;
    int left_y = left.second;

    pair<int, int> right = m[b];
    int right_x = right.first;
    int right_y = right.second;

    string real;
    cin >> real;

    int length = real.length();

    long long time = 0;

    for (int i = 0; i < length; i++){
        string c = "";
        c += real[i];
        pair<int, int> p = m[c];
        int x = p.first;
        int y = p.second;

        if (x == 0){
            if (y <= 4){ // left
                int x_diff = abs(left_x - x);
                int y_diff = abs(left_y - y);

                time += x_diff;
                time += y_diff;
                time += 1;

                left_x = x;
                left_y = y;
            }
            else{ // right
                int x_diff = abs(right_x - x);
                int y_diff = abs(right_y - y);

                time += x_diff;
                time += y_diff;
                time += 1;

                right_x = x;
                right_y = y;
            }
        }
        else if (x == 1){
            if (y <= 4){ // left
                int x_diff = abs(left_x - x);
                int y_diff = abs(left_y - y);

                time += x_diff;
                time += y_diff;
                time += 1;

                left_x = x;
                left_y = y;
            }
            else{ // right
                int x_diff = abs(right_x - x);
                int y_diff = abs(right_y - y);

                time += x_diff;
                time += y_diff;
                time += 1;

                right_x = x;
                right_y = y;
            }
        }
        else{
            if (y <= 3){ // left
                int x_diff = abs(left_x - x);
                int y_diff = abs(left_y - y);

                time += x_diff;
                time += y_diff;
                time += 1;

                left_x = x;
                left_y = y;
            }
            else{ // right
                int x_diff = abs(right_x - x);
                int y_diff = abs(right_y - y);

                time += x_diff;
                time += y_diff;
                time += 1;

                right_x = x;
                right_y = y;
            }
        }
    }

    cout << time;

    return 0;
}
