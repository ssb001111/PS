#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int main(){

    cin.tie(NULL);
		ios_base::sync_with_stdio(false);

    int n,k;
    cin >> n >> k;

    queue<int> queue;
    for (int i = 1; i < n+1; i++){
        queue.push(i);
    }
    cout << "<";
    while (queue.size() != 1){
        for (int i = 0; i < k-1; i++){
            int num = queue.front();
            queue.pop();
            queue.push(num);
        }
        int pr_num = queue.front();
        queue.pop();
        string pr_str = to_string(pr_num);
        cout << pr_str << ", ";
    }
    int last_num = queue.front();
    cout << last_num << ">";

    return 0;
}
