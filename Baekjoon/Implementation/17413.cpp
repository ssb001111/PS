#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s;
    getline(cin, s);

    int length = s.length();

    queue<string> q;
    stack<string> st;

    int started = 0;

    for (int i = 0; i < length; i++){
        string curr = "";
        curr += s[i];

        if (curr == "<"){
            int size = st.size();
            while (size){
                string top = st.top();
                q.push(top);
                st.pop();
                size--;
            }

            started = 1;
            q.push(curr);
        }
        else if (curr == ">"){
            started = 0;
            q.push(curr);
        }
        else if (curr == " "){
            if (started == 0){
                int size = st.size();
                while (size){
                    string top = st.top();
                    q.push(top);
                    st.pop();
                    size--;
                }
                q.push(curr);
            }
            else{
                q.push(curr);
            }
        }
        else{
            if (started == 0){
                st.push(curr);
            }
            else{
                q.push(curr);
            }
        }
    }

    int size = st.size();
    while (size){
        string top = st.top();
        q.push(top);
        st.pop();
        size--;
    }

    size = q.size();
    while (size){
        string front = q.front();
        cout << front;
        q.pop();
        size--;
    }

    return 0;
}
