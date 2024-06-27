#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int main(){

    cin.tie(NULL);
		ios_base::sync_with_stdio(false);

    priority_queue<int> p;
    queue<int> queue;

    int no;
    cin >> no;

    for (int i = 0; i < no; i++){
        int curr;
        cin >> curr;
        if (curr == 0){
            if (p.empty()){
                queue.push(0);
            }
            else{
                queue.push(p.top());
                p.pop();
            }
        }
        else{
            p.push(curr);
        }
    }
    
    int size = queue.size();
    for (int i = 0; i < size; i++){
        cout << queue.front() << "\n";
        queue.pop();
    }

    return 0;
}
