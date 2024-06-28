#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int main(){

    cin.tie(NULL);
	  ios_base::sync_with_stdio(false);

    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > q;
    queue<int> printing_queue;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        int input;
        cin >> input;
        if (input == 0){
            if (!q.empty()){
                int pr = q.top().second;
                printing_queue.push(pr);
                q.pop();
            }
            else{
                printing_queue.push(0);
            }
        }
        else{
            q.push(make_pair(abs(input), input));
        }
    }

    int size = printing_queue.size();
    for (int i = 0; i < size; i++){
        int top = printing_queue.front();
        cout << top << "\n";
        printing_queue.pop();
    }

    return 0;
}
