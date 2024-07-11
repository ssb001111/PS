#include <iostream>
#include <string>
#include <algorithm>

using namespace std; 
 
int main() {

	cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;

    int blue = 0;
    int red = 0;

    int prev_blue = 0;
    int prev_red = 0;

    string str;
    cin >> str;

    for (int i = 0; i < n; i++){
        if (str[i] == 'B'){
            if (prev_blue == 0){
                prev_red = 0;
                prev_blue = 1;
                blue += 1;
            }
        }
        else{
            if (prev_red == 0){
                prev_blue = 0;
                prev_red = 1;
                red += 1;
            }
        }
    }

    int result = 0;
    if (blue <= red){
        result = blue + 1;
    }
    else{
        result = red + 1;
    }

    cout << result;
        
    return 0;
}
