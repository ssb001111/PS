#include <iostream>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

int main(){

    cin.tie(NULL);
	  ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int pr_arr[n];
    deque< pair<int, int> > deque;

    for (int i = 0; i < n; i++){
        int number;
        cin >> number;
        deque.push_back(make_pair(number, i+1));
    }

    int pr_arr_index = 0;

    while (deque.size() != 1){
        int init = deque.front().first;
        int index = deque.front().second;
        pr_arr[pr_arr_index] = index;
        pr_arr_index += 1;
        deque.pop_front();
        if (init > 0){
            for (int i = 0;  i < init-1; i++){
                int pop_and_push_num = deque.front().first;
                int pop_and_push_index = deque.front().second;
                deque.pop_front();
                deque.push_back(make_pair(pop_and_push_num, pop_and_push_index));
            }
        }
        else{
            for (int i = 0;  i < abs(init); i++){
                int pop_and_push_num = deque.back().first;
                int pop_and_push_index = deque.back().second;
                deque.pop_back();
                deque.push_front(make_pair(pop_and_push_num, pop_and_push_index));
            }
        }
    }

    pr_arr[n-1] = deque.front().second;

    for (int i = 0; i < n-1; i++){
        cout << pr_arr[i] << " ";
    }
    cout << pr_arr[n-1];

    return 0;
}
