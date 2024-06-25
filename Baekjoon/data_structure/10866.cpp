#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
	  ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    deque<int> deque;
    vector<int> print_nums;

    for (int i = 0; i < n; i++){
        string input_str;
        cin >> input_str;
        if (input_str == "push_front"){
            int num;
            cin >> num;
            deque.push_front(num);
        }
        else if (input_str == "push_back"){
            int num;
            cin >> num;
            deque.push_back(num);
        }
        else if (input_str == "pop_front"){
            if (deque.empty()){
                print_nums.push_back(-1);
            }
            else{
                int num = deque.front();
                print_nums.push_back(num);
                deque.pop_front();
            }
        }
        else if (input_str == "pop_back"){
            if (deque.empty()){
                print_nums.push_back(-1);
            }
            else{
                int num = deque.back();
                print_nums.push_back(num);
                deque.pop_back();
            }
        }
        else if (input_str == "size"){
            print_nums.push_back(deque.size());
        }
        else if (input_str == "empty"){
            if (deque.empty()){
                print_nums.push_back(1);
            }
            else{
                print_nums.push_back(0);
            }
        }
        else if (input_str == "front"){
            if (deque.empty()){
                print_nums.push_back(-1);
            }
            else{
                print_nums.push_back(deque.front());
            }
        }
        else if (input_str == "back"){
            if (deque.empty()){
                print_nums.push_back(-1);
            }
            else{
                print_nums.push_back(deque.back());
            }
        }
    }

    for (int i = 0; i < print_nums.size(); i++){
        cout << print_nums[i] << "\n";
    }

    return 0;
}
