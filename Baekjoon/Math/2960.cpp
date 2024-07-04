#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector< pair<int, int> > nums;
    
    for (int i = 2; i < n+1; i++){
        nums.push_back(make_pair(i,0));
    }

    int count = 0;
    int num;
    int end = 0;

    while (!nums.empty() and !end){
        int first = nums.begin()->first;
        int second = nums.begin()->second;
        if (second == 0){
            for (int i = 0; i < nums.size(); i+= first){
                if (nums[i].second == 0){
                    nums[i].second = 1;
                    count += 1;
                    if (count == k){
                        num = nums[i].first;
                        end = 1;
                        break;
                    }
                }
            }
        }
        nums.erase(nums.begin(), nums.begin() + 1);
    }

    cout << num;
}
