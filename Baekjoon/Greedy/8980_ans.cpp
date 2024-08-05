#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector< pair< pair<int, int>, int> > v;
int arr[2001] = {0,};
int total = 0;

bool compare(pair< pair<int, int>, int> a, pair< pair<int, int>, int> b){
    if (a.first.second == b.first.second){
        return a.first.first < b.first.first;
    }
    else{
        return a.first.second < b.first.second;
    }
}

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int village, max_;
    cin >> village >> max_;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        int s,e,post;
        cin >> s >> e >> post;

        v.push_back(make_pair(make_pair(s,e), post));
    }

    stable_sort(v.begin(), v.end(), compare);

    for (int i = 0; i < n; i++){
        int from = v[i].first.first;
        int to = v[i].first.second;
        int no_of_posts = v[i].second;

        int max_of_posts = 0;
        for (int j = from; j < to; j++){
            max_of_posts = max(max_of_posts, arr[j]);
        }
        int able = min(no_of_posts, max_ - max_of_posts);

        for (int j = from; j < to; j++){
            arr[j] += able;
        }
        total += able;
    }

    cout << total;

    return 0;
}
