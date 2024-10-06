#include <iostream>
#include <queue>

using namespace std;

int k, m;
int original_grid[5][5];
queue<int> parts;
int ans;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

struct Cmp{
    bool operator()(pair<int, int> a, pair<int, int> b){
        if (a.second != b.second){
            return a.second > b.second;
        }
        return a.first < b.first;
    }
};

struct rotate_info {
    int value;
    int rotate_angle;
    int col;
    int row;
    priority_queue<pair<int, int>,vector< pair<int, int>>,Cmp> pq;
};

struct Cmp1{
    bool operator()(rotate_info a, rotate_info b){
        if (a.value != b.value){
            return a.value < b.value;
        }
        else if (a.rotate_angle != b.rotate_angle){
            return a.rotate_angle > b.rotate_angle;
        }
        else if (a.col != b.col){
            return a.col > b.col;
        }
        else if (a.row != b.row){
            return a.row > b.row;
        }
    }
};

rotate_info calcValue(int copy_grid[][5] , int u, int sy, int sx){

    queue< pair<int, int> > q;
    priority_queue< pair<int, int>, vector<pair<int, int>>, Cmp> pq;

    bool visited[5][5] = {false, };
    int value = 0;

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            queue< pair<int, int> > q2;
            if (visited[i][j] == true){
                continue;
            }
            else{
                q.push(make_pair(i, j));
                q2.push(make_pair(i, j));
                visited[i][j] = true;
                int cnt = 1;
                while (!q.empty()){
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();
                    for (int p = 0; p < 4; p++){
                        int ny = y + dy[p];
                        int nx = x + dx[p];
                        if (ny >= 0 && ny < 5 && nx >= 0 && nx < 5){
                            if (visited[ny][nx] == false){
                                if (copy_grid[y][x] == copy_grid[ny][nx]){
                                    cnt++;
                                    q.push(make_pair(ny, nx));
                                    q2.push(make_pair(ny, nx));
                                    visited[ny][nx] = true;
                                }
                            }
                        }
                    }
                }

                if (cnt >= 3){
                    value += cnt;
                    while (!q2.empty()){
                        pq.push(q2.front());
                        q2.pop();
                    }
                }
            }
        }
    }
    rotate_info ret = {value, u, sx, sy, pq};
    return ret;
}

rotate_info func1(){

    priority_queue<rotate_info, vector<rotate_info>, Cmp1> q;

    for (int i = 1; i < 4; i++){
        for (int j = 1; j < 4; j++){

            int copy_grid[5][5] = {0, };
            for (int n = 0; n < 5; n++){
                for (int o = 0; o < 5; o++){
                    copy_grid[n][o] = original_grid[n][o];
                }
            }

            int sy = i-1;
            int sx = j-1;

            for (int u = 1; u <= 3; u++){
                int again_copy_grid[5][5] = {0, };
                for (int n = 0; n < 5; n++){
                    for (int o = 0; o < 5; o++){
                        again_copy_grid[n][o] = copy_grid[n][o];
                    }
                }
                for (int n = 0; n < 3; n++){
                    for (int o = 0; o < 3; o++){
                        copy_grid[o + sy][(2-n) + sx] = again_copy_grid[n + sy][o + sx];
                    }
                }
                rotate_info r = calcValue(copy_grid, u, sy, sx);
                q.push(r);
            }
        }
    }
    return q.top();
}

void func2(rotate_info selected){

    int copy_grid[5][5] = {0, };
    for (int n = 0; n < 5; n++){
        for (int o = 0; o < 5; o++){
            copy_grid[n][o] = original_grid[n][o];
        }
    }

    int sy = selected.row;
    int sx = selected.col;

    for (int u = 1; u <= selected.rotate_angle; u++){
        int again_copy_grid[5][5] = {0, };
        for (int n = 0; n < 5; n++){
            for (int o = 0; o < 5; o++){
                again_copy_grid[n][o] = copy_grid[n][o];
            }
        }
        for (int n = 0; n < 3; n++){
            for (int o = 0; o < 3; o++){
                copy_grid[o + sy][(2-n) + sx] = again_copy_grid[n + sy][o + sx];
            }
        }
    }

    while (!selected.pq.empty()){
        int y = selected.pq.top().first;
        int x = selected.pq.top().second;
        int p = parts.front();
        parts.pop();
        copy_grid[y][x] = p;
        selected.pq.pop();
    }

    ans += selected.value;

    while (true){
        rotate_info r = calcValue(copy_grid, 0, 0, 0);
        if (r.value == 0){
            break;
        }
        else{
            while (!r.pq.empty()){
                int ny = r.pq.top().first;
                int nx = r.pq.top().second;
                int pa = parts.front();
                parts.pop();
                copy_grid[ny][nx] = pa;
                r.pq.pop();
            }
            ans += r.value;
        }
    }

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            original_grid[i][j] = copy_grid[i][j];
        }
    }
}

bool func(){
    rotate_info selected = func1();
    if (selected.value == 0){
        return false;
    }
    else{
        func2(selected);
        return true;
    }
}

void inputs(){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j< 5; j++){
            cin >> original_grid[i][j];
        }
    }
    for (int i = 0; i < m; i++){
        int s;
        cin >> s;
        parts.push(s);
    }
}

int main() {

    cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    cin >> k >> m;
    inputs();

    for (int i = 0; i < k; i++){
        ans = 0;
        bool a = func();
        if (a == false){
            break;
        }
        cout << ans << " ";
    }

    return 0;
}
