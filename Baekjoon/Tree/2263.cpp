#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string str = "";
vector<int> inorder;
vector<int> postorder;
 
void func(int s, int e, int root){

    for(int i = s ; i < e; i++){

        if(inorder[i] == postorder[root]){

            str += to_string(postorder[root]);
            str += " ";

            func(s, i, root - (e-1-i) - 1); // left

            func(i + 1, e, root - 1); // right

        }

    }
}
 
int main() {
    
    int n;
    cin >> n;

    inorder = vector<int>(n);
    postorder = vector<int>(n);

    for(int k=0; k<n; k++){
        cin >> inorder[k];
    }

    for(int k=0; k<n; k++){
        cin >> postorder[k];
    }

    func(0, n, n-1);

    cout << str;
        
    return 0;
}
