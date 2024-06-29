#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int no_of_test;
    cin >> no_of_test;

    string pr_arr[no_of_test];

    for (int i = 0; i < no_of_test; i++){

        multimap <int, int> map;
        priority_queue< pair<int, int> > greatest;
        priority_queue< pair<int, int> , vector< pair<int, int> >, greater< pair<int, int> > > lowest;
        
        int no;
        cin >> no;

        for (int j = 0; j < no; j++){

            char cmd;
            int num;
            cin >> cmd >> num;

            if (cmd ==  'I'){
                greatest.push(make_pair(num, j));
                lowest.push(make_pair(num, j));
                map.insert(make_pair(num, j));
            }

            else if (cmd == 'D'){

                // 최소값
                if (num == -1){

                    // 만약 map이 empty = Q가 비어 있다는 뜻
                    // Q가 비어있지 않을때. 데이터가 있을 때!
                    if (!map.empty()){

                        // 일단 lowest에서 가장 처음으로 나오는 map 안에 있는 element 삭제
                        // 근데 그 바로 뒤에꺼가 map에 있는 element가 아닐 수도 있다는 게 문제
                        // 만약 그런 경우에는 이거 끝나자마자 끝난다면 set에 있지 않은 element가 나올 수도 있다.
                        int end = 0;

                        while (!end){

                            pair<int, int> top = lowest.top();
                            for (auto it = map.lower_bound(top.first); it != map.upper_bound(top.first); it++){
                                if (it->second == top.second){
                                    end = 1;
                                    map.erase(it);
                                    break;
                                }
                            }
                            lowest.pop();
                            
                        }

                        // 그러면 그 다음 최소가 나올때까지 미리 pop해놓기
                        if (!map.empty()){
                            end = 0;

                            while (!end){

                                pair<int, int> top = lowest.top();
                                for (auto it = map.lower_bound(top.first); it != map.upper_bound(top.first); it++){
                                    if (it->second == top.second){
                                        end = 1;
                                        break;
                                    }
                                }
                                if (end == 0){
                                    lowest.pop();
                                }
                                
                            }
                        }

                        // 그리고 또, 위에서 하나 뺀 걸로 인해 greatest에도 변경사항이 생겼을 수 있다.
                        if (!map.empty()){
                            end = 0;

                            while (!end){

                                pair<int, int> top = greatest.top();
                                for (auto it = map.lower_bound(top.first); it != map.upper_bound(top.first); it++){
                                    if (it->second == top.second){
                                        end = 1;
                                        break;
                                    }
                                }
                                if (end == 0){
                                    greatest.pop();
                                }
                                
                            }
                        }
                        // 위에서 빼서 map이 비었다면 Q가 empty -> Q를 비워준다.
                        else{
                            while (!greatest.empty()){
                                greatest.pop();
                            }
                            while (!lowest.empty()){
                                lowest.pop();
                            }
                        }
                    }

                }

                // 최대값
                else{
                    // 만약 set가 empty = Q가 비어 있다는 뜻
                    // Q가 비어있지 않을때. 데이터가 있을 때!

                    if (!map.empty()){

                        // 일단 greatest에서 가장 처음으로 나오는 map 안에 있는 element 삭제
                        // 근데 그 바로 뒤에꺼가 map에 있는 element가 아닐 수도 있다는 게 문제
                        // 만약 그런 경우에는 이거 끝나자마자 끝난다면 set에 있지 않은 element가 나올 수도 있다.
                        int end = 0;

                        while (!end){

                            pair<int, int> top = greatest.top();
                            for (auto it = map.lower_bound(top.first); it != map.upper_bound(top.first); it++){
                                if (it->second == top.second){
                                    end = 1;
                                    map.erase(it);
                                    break;
                                }
                            }
                            greatest.pop();
                            
                        }

                        // 그러면 그 다음 최대가 나올때까지 미리 pop해놓기
                        if (!map.empty()){
                            end = 0;

                            while (!end){

                                pair<int, int> top = greatest.top();
                                for (auto it = map.lower_bound(top.first); it != map.upper_bound(top.first); it++){
                                    if (it->second == top.second){
                                        end = 1;
                                        break;
                                    }
                                }
                                if (end == 0){
                                    greatest.pop();
                                }
                                
                            }
                        }

                        // 위에서 하나 뺀 걸로 인해 lowest에도 변경사항이 생겼을 수 있다.
                        if (!map.empty()){

                            end = 0;

                            while (!end){

                                pair<int, int> top = lowest.top();
                                for (auto it = map.lower_bound(top.first); it != map.upper_bound(top.first); it++){
                                    if (it->second == top.second){
                                        end = 1;
                                        break;
                                    }
                                }
                                if (end == 0){
                                    lowest.pop();
                                }
                                
                            }
                        }
                        // 위에서 빼서 map이 비었다면 Q가 empty -> Q를 비워준다.
                        else{
                            while (!lowest.empty()){
                                lowest.pop();
                            }
                            while (!greatest.empty()){
                                greatest.pop();
                            }
                        }
                    }

                }
            }
        }

        if (map.empty()){
            pr_arr[i] = "EMPTY";
        }
        else{
            string s;
            s += to_string(greatest.top().first);
            s += " ";
            s += to_string(lowest.top().first);
            pr_arr[i] = s;
        }
    }

    for (int i = 0; i < no_of_test; i++){
        cout << pr_arr[i] << "\n";
    }

    return 0;
}
