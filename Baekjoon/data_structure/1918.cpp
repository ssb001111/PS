#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

deque<string> q_alp;
deque<string> q_giho;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    // 일단 input 받기

    string input;
    cin >> input;

    for (int i = 0; i < input.length(); i++){
        if (input[i] == '+' or input[i] == '-' or input[i] == '*' or input[i] == '/'){
            string s = "";
            s += input[i];
            q_giho.push_back(s);
        }
        else if (input[i] == '('){
            q_giho.push_back("(");
        }
        else if (input[i] == ')'){
            if (!q_giho.empty()){
                if (q_giho.back() == "("){
                    q_giho.pop_back();
                }
                else{
                    q_giho.push_back(")");
                }
            }
        }
        else{
            string s = "";
            s += input[i];
            q_alp.push_back(s);
        }
    }

    deque<string> mid_giho;

    while (!q_giho.empty()){
        int size = q_giho.size();
        for (int i = 0; i < size; i++){
            string curr_giho = q_giho.front();
            q_giho.pop_front();
            if (curr_giho == "*" or curr_giho == "/"){
                if (size != 1){
                    if (i == 0){ // 맨 처음
                        if (q_giho.front() == "("){ // *( or /(
                            mid_giho.push_back(curr_giho);
                            string alp = q_alp.front();
                            q_alp.pop_front();
                            q_alp.push_back(alp);
                        }
                        else{ // 기호들만 : +* -* ** /* *+ *- */ +/ -/ */ // /+ /- /*
                            string alp1 = q_alp.front();
                            q_alp.pop_front();
                            string alp2 = q_alp.front();
                            q_alp.pop_front();
                            string s = alp1 + alp2 + curr_giho;
                            q_alp.push_front(s);
                        }
                    }
                    else if (i > 0 and i < size-1){ 
                        if (!mid_giho.empty() and mid_giho.back() == ")"){ // )* or )/
                            mid_giho.push_back(curr_giho);
                            if (q_giho.front() == "("){ // )*( or )/(
                                continue; // 다음 i에서 알아서 해 줄 것
                            }
                        }
                        else if (q_giho.front() == "("){ // *( or /(
                            mid_giho.push_back(curr_giho);
                            string alp = q_alp.front();
                            q_alp.pop_front();
                            q_alp.push_back(alp);
                        }
                        else{ // 기호들만 : +* -* ** /* *+ *- */ +/ -/ */ // /+ /- /* *) /) (* (/
                            if (!mid_giho.empty() and (mid_giho.back() == "*" or mid_giho.back() == "/")){
                                mid_giho.push_back(curr_giho);
                                string alp = q_alp.front();
                                q_alp.pop_front();
                                q_alp.push_back(alp);
                            }
                            else{
                                string alp1 = q_alp.front();
                                q_alp.pop_front();
                                string alp2 = q_alp.front();
                                q_alp.pop_front();
                                string s = alp1 + alp2 + curr_giho;
                                q_alp.push_front(s);
                            }
                        }
                    }
                    else{ // 마지막
                        if (!mid_giho.empty() and mid_giho.back() == ")"){ // )* or )/
                            mid_giho.push_back(curr_giho);
                            string alp = q_alp.front();
                            q_alp.pop_front();
                            q_alp.push_back(alp);
                        }
                        else{ // 기호들만 : +* -* ** /* *+ *- */ +/ -/ */ // /+ /- /*
                            if (!mid_giho.empty() and (mid_giho.back() == "*" or mid_giho.back() == "/")){
                                mid_giho.push_back(curr_giho);
                                string alp = q_alp.front();
                                q_alp.pop_front();
                                q_alp.push_back(alp);
                                alp = q_alp.front();
                                q_alp.pop_front();
                                q_alp.push_back(alp);
                            }
                            else{
                                string alp1 = q_alp.front();
                                q_alp.pop_front();
                                string alp2 = q_alp.front();
                                q_alp.pop_front();
                                string s = alp1 + alp2 + curr_giho;
                                q_alp.push_back(s);
                            }
                        }
                    }
                }
                else{
                    string alp1 = q_alp.front();
                    q_alp.pop_front();
                    string alp2 = q_alp.front();
                    q_alp.pop_front();
                    string s = alp1 + alp2 + curr_giho;
                    q_alp.push_front(s);
                }
            }
            else if (curr_giho == "+" or curr_giho == "-"){
                if (size != 1){
                    if (i == 0){ // 맨 처음
                        if (q_giho.front() == "("){ // +( or -(
                            mid_giho.push_back(curr_giho);
                            string alp = q_alp.front();
                            q_alp.pop_front();
                            q_alp.push_back(alp);
                        }
                        else{ // 기호들만 : 
                            if (q_giho.front() == "+" or q_giho.front() == "-"){  // ++ +- -+ --
                                string alp1 = q_alp.front();
                                q_alp.pop_front();
                                string alp2 = q_alp.front();
                                q_alp.pop_front();
                                string s = alp1 + alp2 + curr_giho;
                                q_alp.push_front(s);
                            }
                            else{ // +* +/ -* -/
                                mid_giho.push_back(curr_giho);
                                string alp = q_alp.front();
                                q_alp.pop_front();
                                q_alp.push_back(alp);
                            }
                        }
                    }
                    else if (i > 0 and i < size-1){
                        if (!mid_giho.empty() and mid_giho.back() == ")"){ // )+ or )-
                            mid_giho.push_back(curr_giho);
                            if (q_giho.front() == "("){ // )+( or )-(
                                continue; // 다음 i에서 알아서 해 줄 것
                            }
                        }
                        else if (q_giho.front() == "("){ // +( or -(
                            mid_giho.push_back(curr_giho);
                            string alp = q_alp.front();
                            q_alp.pop_front();
                            q_alp.push_back(alp);
                        }
                        else{ // 기호들만
                            if (!mid_giho.empty() and (mid_giho.back() == "+" or mid_giho.back() == "-" or mid_giho.back() == "*" or mid_giho.back() == "/")){ // 앞에서 미처 행하지 못한 + 혹은 - 혹은 * 혹은 / 가 남아있음
                                mid_giho.push_back(curr_giho);
                                string alp = q_alp.front();
                                q_alp.pop_front();
                                q_alp.push_back(alp);
                            }
                            else{
                                if (q_giho.front() == "+" or q_giho.front() == "-" or q_giho.front() == ")"){  // ++ +- -+ -- +) -) (+ (-
                                    string alp1 = q_alp.front();
                                    q_alp.pop_front();
                                    string alp2 = q_alp.front();
                                    q_alp.pop_front();
                                    string s = alp1 + alp2 + curr_giho;
                                    q_alp.push_front(s);
                                }
                                else{ // +* +/ -* -/
                                    mid_giho.push_back(curr_giho);
                                    string alp = q_alp.front();
                                    q_alp.pop_front();
                                    q_alp.push_back(alp);
                                }
                            }
                            
                        }
                    }
                    else{ // 제일 마지막
                        if (!mid_giho.empty() and mid_giho.back() == ")"){ // )+ or )-
                            mid_giho.push_back(curr_giho);
                            string alp = q_alp.front();
                            q_alp.pop_front();
                            q_alp.push_back(alp);
                        }
                        else{ // 기호들만 : 
                            if (!mid_giho.empty() and (mid_giho.back() == "+" or mid_giho.back() == "-" or mid_giho.back() == "*" or mid_giho.back() == "/")){ // 앞에서 미처 행하지 못한 + 혹은 - 혹은 * 혹은 /가 남아있음
                                mid_giho.push_back(curr_giho);
                                string alp = q_alp.front();
                                q_alp.pop_front();
                                q_alp.push_back(alp);
                                alp = q_alp.front();
                                q_alp.pop_front();
                                q_alp.push_back(alp);
                            }
                            else{
                                string alp1 = q_alp.front();
                                q_alp.pop_front();
                                string alp2 = q_alp.front();
                                q_alp.pop_front();
                                string s = alp1 + alp2 + curr_giho;
                                q_alp.push_back(s);
                            }
                            
                        }

                    }
                }
                else{
                    string alp1 = q_alp.front();
                    q_alp.pop_front();
                    string alp2 = q_alp.front();
                    q_alp.pop_front();
                    string s = alp1 + alp2 + curr_giho;
                    q_alp.push_front(s);
                }
            }
            else if (curr_giho == "("){
                mid_giho.push_back("(");
            }
            else{ // curr_giho == ")"
                if (mid_giho.back() == "("){
                    mid_giho.pop_back();

                    if (i == size-1){
                        string alp = q_alp.front();
                        q_alp.pop_front();
                        q_alp.push_back(alp);
                    }
                }
                else if (mid_giho.back() == ")"){
                    mid_giho.push_back(")");
                }
                else{
                    mid_giho.push_back(")");
                    
                    string alp = q_alp.front();
                    q_alp.pop_front();
                    q_alp.push_back(alp);
                }
            }
        }

        if (!mid_giho.empty()){
            int fi_size_mid = mid_giho.size();
            for (int i = 0; i < fi_size_mid; i++){
                q_giho.push_back(mid_giho.front());
                mid_giho.pop_front();
            }
        }

    }

    cout << q_alp.front();

    return 0;
}
