#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string str = "";
vector<int> preorder;
vector<int> inorder;
 
void func(int root, int s, int e){

    for(int i = s ; i < e; i++){

        if(inorder[i] == preorder[root]){

            func(root + 1, s, i); // left

            func(root + 1 + i - s, i + 1, e); // right

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

        preorder = vector<int>(n);
        inorder = vector<int>(n);

        for(int k=0; k<n; k++){
            cin >> preorder[k];
        }

        for(int k=0; k<n; k++){
            cin >> inorder[k];
        }

        func(0, 0, n);
        st_arr[i] = str;
    }

    for (int i = 0; i < test_case; i++){
        cout << st_arr[i] << "\n";
    }
        
    return 0;
}
