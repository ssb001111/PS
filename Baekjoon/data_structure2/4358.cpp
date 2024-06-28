#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main(){

    cin.tie(NULL);
	  ios_base::sync_with_stdio(false);

    map<string, float> m;
    float no = 0;

    string str = "";
    while(getline(cin, str)){

        if (m.find(str) == m.end()){ // map 안에 없음
            m.insert(make_pair(str, 1));
        }
        else{
            m[str] += 1; // m.find(str)->second로도 접근 가능하지만 이렇게도 접근 가능하다.
        }

        no += 1;
    }

    cout << fixed;
    cout.precision(4);

    for (auto iter = m.begin(); iter != m.end(); iter++){
        cout << iter->first << " " << iter->second * 100 / no << "\n";
    }

    return 0;
}
