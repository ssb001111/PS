#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main(){

    cin.tie(NULL);
	  ios_base::sync_with_stdio(false);

    priority_queue< int, vector<int>, greater<int> > q;

    int num;
    cin >> num;

    for (int i = 0; i < num; i++){
        int no;
        cin >> no;
        q.push(no);
    }

    for (int i = 0; i < pow(num, 2)-num; i++){
        int no;
        cin >> no;
        q.push(no);
        q.pop();
    }

    cout << q.top();

    return 0;
}
