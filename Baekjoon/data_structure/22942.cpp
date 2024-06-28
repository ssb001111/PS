#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

pair<int, string> arr[2020001]; // 0 : index 1010000

int main(){

    cin.tie(NULL);
	  ios_base::sync_with_stdio(false);

    int no_of_circles;
    cin >> no_of_circles;

    for (int i = 0; i < 2020001; i++){
        arr[i] = make_pair(-1, "");
    }

    int end = 0;

    for (int i = 0; i < no_of_circles; i++){
        int mid_circle, rad_circle;
        cin >> mid_circle >> rad_circle;
        int min = 1010000 + mid_circle - rad_circle;
        int max = 1010000 + mid_circle + rad_circle;

        if (arr[min].first != -1){
            end = 1;
        }
        else{
            arr[min] = make_pair(max, "(");
        }

        if (arr[max].first != -1){
            end = 1;
        }
        else{
            arr[max] = make_pair(min, ")");
        }
    }

    if (end == 1){
        cout << "NO";
        return 0;
    }

    stack< pair<int, string> > s;

    for (int i = 0; i < 2020001; i++){
        if (arr[i].first != -1){
            if (arr[i].second == "("){
                s.push(arr[i]);
            }
            else{
                if (!s.empty()){
                    if (s.top().first != i){ // 다른 원과 교차
                        cout << "NO";
                        return 0;
                    }
                    else{ // 원 안에 아무런 원도 들어가 있지 않음
                        s.pop();
                    }
                }
                else{
                    cout << "NO";
                    return 0;
                }
            }
        }
    }
    if (s.empty()){
        cout << "YES";
        return 0;
    }
    else{
        cout << "NO";
        return 0;
    }

    return 0;
}
