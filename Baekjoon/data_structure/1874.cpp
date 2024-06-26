#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int main(){

    cin.tie(NULL);
	  ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    // stack
    stack<int> st;
    // 지금까지 넣은 숫자들 중 가장 큰 숫자
    int curr_no = 0;

    // +,- 를 위한 queue
    queue<string> printing_stack;

    for (int i = 0; i < n; i++){

        // 찾아야 하는 숫자
        int curr_needed;
        cin >> curr_needed;

        if (!st.empty()){

            // 첫 번째 경우 : stack의 맨 위에 있는 숫자가 찾아야 하는 숫자보다 작음
            if (st.top() < curr_needed){

                // 이미 너가 찾는 숫자는 아까 전에 pop되었음! 끝났다
                if (curr_no >= curr_needed){
                    cout << "NO";
                    return 0;
                }
                // 아직 너가 찾는 숫자가 stack에 들어오기도 전임. 그 숫자까지 push하고 마지막에 pop해 줘야 함
                else{

                    for (int j = curr_no + 1; j < curr_needed; j++){
                        st.push(j);
                        curr_no += 1;
                        printing_stack.push("+");
                    }
                    printing_stack.push("+");
                    printing_stack.push("-");
                    curr_no += 1;
                }
                
            }
            // 두 번째 경우 : stack의 맨 위에 있는 숫자가 찾아야 하는 숫자와 같거나 큼
            else{
                while(true){
                    int pro_num = st.top();
                    st.pop();
                    printing_stack.push("-");
                    if (pro_num == curr_needed){
                        break;
                    }
                }
            }
        }
        else{

            // 맨 첫 숫자
            if (curr_no == 0){
                for (int i = 1; i < curr_needed; i++){
                    st.push(i);
                    curr_no += 1;
                    printing_stack.push("+");
                }
                printing_stack.push("+");
                printing_stack.push("-");
                curr_no += 1;
            }
            // 맨 첫 숫자는 아님
            else{

                // 지금까지 넣었던 숫자들 중 가장 큰 수가 지금 찾아야 하는 숫자보다 같거나 큼 : 이미 넣어놨고 턴 지나감
                if (curr_no >= curr_needed){
                    cout << "NO";
                    return 0;
                }
                // 아직 안 넣었음
                else{
                    for (int j = curr_no + 1; j < curr_needed; j++){
                        st.push(j);
                        curr_no += 1;
                        printing_stack.push("+");
                    }
                    printing_stack.push("+");
                    printing_stack.push("-");
                    curr_no += 1;

                }
            }
        }
        
    }

    int size = printing_stack.size();

    for (int i = 0; i < size; i++){
        cout << printing_stack.front() << "\n";
        printing_stack.pop();
    }

    return 0;
}
