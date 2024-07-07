#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
 
int preorder[1001];
int inorder[1001];
string str = "";
 
void solution(int root, int s, int e){

    for(int i = s ; i < e; i++){

        if(inorder[i] == preorder[root]){

            solution(root + 1, s, i); // left sub tree

            solution(root + 1 + i - s, i + 1, e); // right sub tree

            str += to_string(preorder[root]);
            str += " ";
        }

    }
}
 
int main() {

    int test_case; 
    cin >> test_case;

    string st_arr[test_case];

    for (int i = 0; i < test_case; i++){

        str = "";
        
        int n;
        cin >> n;

        for(int i=0; i<n; i++){
            cin >> preorder[i];
        }

        for(int i=0; i<n; i++){
            cin >> inorder[i];
        }

        solution(0, 0, n);
        st_arr[i] = str;
    }

    for (int i = 0; i < test_case; i++){
        cout << st_arr[i] << "\n";
    }
        
    return 0;
}
