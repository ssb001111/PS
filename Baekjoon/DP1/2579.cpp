#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
vector<int> answers;

int func(int index){
    if (index == 0){
        answers[0] = v[0];
        return v[0];
    }
    else if (index == 1){
        answers[1] = v[0] + v[1];
        return (v[0] + v[1]);
    }
    else if (index == 2){
        int first = v[0] + v[2];
        int second = v[1] + v[2];
        if (first > second){
            answers[2] = first;
            return first;
        }
        else{
            answers[2] = second;
            return second;
        }
    }
    else{
        int first = 0;
        if (answers[index-3] != -1){
            first = answers[index-3] + v[index-1] + v[index];
        }
        else{
            first = func(index-3) + v[index-1] + v[index];
        }

        int second = 0;
        if (answers[index-2] != -1){
            second = answers[index-2] + v[index];
        }
        else{
            second = func(index-2) + v[index];
        }

        if (first > second){
            answers[index] = first;
            return first;
        }
        else{
            answers[index] = second;
            return second;
        }
    }
}

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    v = vector<int>(n);
    answers = vector<int>(n);

    for (int i = 0; i < n; i++){
        cin >> v[i];
        answers[i] = -1;
    }

    cout << func(n-1);

    return 0;
}
