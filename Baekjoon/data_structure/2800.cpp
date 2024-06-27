#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int main(){

    cin.tie(NULL);
	  ios_base::sync_with_stdio(false);

    // 들어오는 (,) & 각각의 index 넣어놓을 stack
    stack< pair<string, int> > str_stack;

    // ()의 index 쌍들을 모아놓을 queue
    queue< pair<int, int> > index_queue;

    // O, X 모아놓을 queue
    queue<string> print_queue;

    // 프린트할 string들 자체를 모아놓기 위한..
    queue<string> result;

    string input;
    cin >> input;

    // str_stack 사용해 index_queue 만들기.
    for (int i = 0; i < input.length(); i++){
        if (input[i] == '('){
            str_stack.push(make_pair("(", i));
        }
        else if (input[i] == ')'){
            int index = str_stack.top().second;
            str_stack.pop();
            index_queue.push(make_pair(index, i));
        }
    }

    // print_queue 만들기
    int size = index_queue.size();

    string ox;
    for (int i = 0; i < size; i++){
        ox += "o";
    }
    print_queue.push(ox);
    
    for (int i = 0; i < size; i++){
        int size_of_print_queue = print_queue.size();
        for (int j = 0; j < size_of_print_queue; j++){
            string pr = print_queue.front();
            print_queue.pop();
            print_queue.push(pr);
            pr[i] = 'x';
            print_queue.push(pr);
        }
    }

    // index_queue를 array로 옮겨놓기 (index로 접근 위해)
    pair<int, int> index_queue_to_array[size];
    for (int i = 0; i < size; i++){
        int first_el = index_queue.front().first;
        int second_el = index_queue.front().second;
        index_queue.pop();
        index_queue_to_array[i] = make_pair(first_el, second_el);
    }

    // 모든 괄호 있는 건 필요 없음
    print_queue.pop();
    int size_of_print_queue = print_queue.size();

    string print[size_of_print_queue];

    // print_queue 각각 element 보고 빼야 할 index 추출해 priority queue 만들기. 그 priority queue 사용해 string 만들기
    for (int i = 0; i < size_of_print_queue; i++){
        // priority queue 만들기
        string pr = print_queue.front();
        print_queue.pop();
        priority_queue< int, vector<int>, greater<int> > q;
        for (int j = 0; j < pr.length(); j++){
            if (pr[j] == 'x'){
                q.push(index_queue_to_array[j].first);
                q.push(index_queue_to_array[j].second);
            }
        }
        // priority queue 사용해 string 만들기
        int size_of_q = q.size();
        string output;

        for (int j = 0; j < input.length(); j++){
            if (!q.empty()){
                int index = q.top();
                if (j != index){
                    output += input[j];
                }
                else{
                    q.pop();
                }
            }
            else{
                output += input[j];
            }
        }     
        print[i] = output;
    }
    stable_sort(print, print+size_of_print_queue);
    string last_print = "";
    for (int i = 0; i < size_of_print_queue; i++){
        if (last_print != print[i]){
            cout << print[i] << "\n";
            last_print = print[i];
        }
    }
    return 0;
}
