#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int main(){

    cin.tie(NULL);
		ios_base::sync_with_stdio(false);

    // 총 테스트케이스 개수
    int n;
    cin >> n;

    // 프린트 할 것들 모아놓은 array
    int print_arr[n];


    for (int i = 0; i < n; i++){

        // priority_queue
        priority_queue<int> arr;

        // queue
        queue< pair<int, int> > queue;

        // 일단 매 테스트 케이스마다 문서의 개수가 주어진다.
        int no_of_docs;
        cin >> no_of_docs;

        // 현재 주어질 것 중 몇 번째 index에 target이 있는지
        int index_of_target;
        cin >> index_of_target;

        // 문서의 개수 만큼 입력 받는다.
        for (int j = 0; j < no_of_docs; j++){

            // 일단 중요도를 받음
            int doc;
            cin >> doc;

            // 우선순위 큐는 중요도만 넣기
            arr.push(doc);
            // 큐는 중요도 & 원래의 index 같이 넣어주기
            queue.push(make_pair(doc, j));
        }

        int th = 0;

        while (!queue.empty()){
            if (queue.front().first == arr.top()){
                th += 1;
                if (queue.front().second == index_of_target){
                    print_arr[i] = th;
                    break;
                }
                else{
                    queue.pop();
                    arr.pop();
                }
            }
            else{
                int imp = queue.front().first;
                int index = queue.front().second;
                queue.pop();
                queue.push(make_pair(imp, index));
            }
        }
    }

    for (int i = 0; i < n; i++){
        cout << print_arr[i] << "\n";
    }

    return 0;
}
