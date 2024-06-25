#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    cin.tie(NULL);
	  ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    queue<int> queue;
    for (int i = 1; i < n+1; i++){
        queue.push(i);
    }

    while (queue.size() != 1){
        queue.pop();
        int num = queue.front();
        queue.pop();
        queue.push(num);
    }

    cout << queue.front();

    return 0;
}
