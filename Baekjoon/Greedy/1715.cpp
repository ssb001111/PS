#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    priority_queue< int, vector<int>, greater<int> > q;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        q.push(a);
    }

    int num = 0;

    while (q.size() != 1){
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        num += a+b;
        q.push(a+b);
    }

    cout << num;

    return 0;
}
