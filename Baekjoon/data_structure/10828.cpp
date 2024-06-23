// 백준 10828번 스택 : 실버 4
// 2164KB, 380ms, C++17
#include <iostream>
#include <algorithm> 
#include <vector>
#include <string>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	string num;
	getline(cin, num);
	n = stoi(num);

	string input_str;
	vector<int> stack;

	vector<int> output;

	for (int i = 0; i < n; i++) {
		getline(cin, input_str);
		if (input_str.substr(0, 4) == "push") {
			int num = stoi(input_str.substr(5));
			stack.push_back(num);
		}
		else if (input_str == "pop") {
			if (stack.size() == 0) {
				output.push_back(-1);
			}
			else {
				output.push_back(stack.back());
				stack.pop_back();
			}
		}
		else if (input_str == "size") {
			output.push_back(stack.size());
		}
		else if (input_str == "empty") {
			if (stack.size() == 0) {
				output.push_back(1);
			}
			else {
				output.push_back(0);
			}
		}
		else if (input_str == "top") {
			if (stack.size() == 0) {
				output.push_back(-1);
			}
			else {
				output.push_back(stack.back());
			}
		}
	}

	for (int i = 0; i < output.size(); i++) {
		cout << output[i] << endl;
	}
	return 0;
}