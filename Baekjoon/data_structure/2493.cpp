#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int main(){

    cin.tie(NULL);
	  ios_base::sync_with_stdio(false);

    stack< pair<int, int> > stack;
    int no_of_towers, heights;

    cin >> no_of_towers;

    int arr_pr[no_of_towers];

    for (int i = 0; i < no_of_towers; i++){
        cin >> heights;
        while (!stack.empty()){
            if (stack.top().first > heights){
                arr_pr[i] = stack.top().second;
                break;
            }
            else{
                stack.pop();
            }
        }
        if (stack.empty()){
            arr_pr[i] = 0;
        }
        stack.push(make_pair(heights, i+1));
    }

    for (int i = 0; i < no_of_towers-1; i++){
        cout << arr_pr[i] << " ";
    }
    cout << arr_pr[no_of_towers-1];

    return 0;
}
