#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int arr[73][71];
int exits[73][71];
int r, c, k;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, 1, -1};

struct golem_info{
    int mid_col;
    int dir;
};

vector<golem_info> golems;
int ans;

void calcVal(int startRow, int startCol, int num){
    queue< pair<int, int> > q;
    bool visited[73][71] = {false,};
    int max_row = startRow;
    visited[startRow][startCol] = true;

    for (int i = 0; i < 4; i++){
        q.push(make_pair(startRow + dr[i], startCol + dc[i]));
        visited[startRow + dr[i]][startCol + dc[i]] = true;
    }

    while (!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        max_row = max(max_row, p.first);

        if (exits[p.first][p.second] == 1){
            for (int i = 0; i < 4; i++){
                if (p.first + dr[i] >= 3 && p.first + dr[i] <= r+2 && p.second + dc[i] >= 1 && p.second + dc[i] <= c && arr[p.first + dr[i]][p.second + dc[i]] != num && arr[p.first + dr[i]][p.second + dc[i]] != 0){
                    if (visited[p.first + dr[i]][p.second + dc[i]] == false){
                        q.push(make_pair(p.first + dr[i], p.second + dc[i]));
                        visited[p.first + dr[i]][p.second + dc[i]] = true;
                    }
                }
            }
        }
        else{
            for (int i = 0; i < 4; i++){
                if (p.first + dr[i] >= 3 && p.first + dr[i] <= r+2 && p.second + dc[i] >= 1 && p.second + dc[i] <= c && arr[p.first + dr[i]][p.second + dc[i]] == arr[p.first][p.second]){
                    if (visited[p.first + dr[i]][p.second + dc[i]] == false){
                        q.push(make_pair(p.first + dr[i], p.second + dc[i]));
                        visited[p.first + dr[i]][p.second + dc[i]] = true;
                    }
                }
            }
        }
    }

    ans += max_row-2;
}

bool isSouthOk(int startRow, int startCol){
    return startRow <= r && arr[startRow+1][startCol-1] == 0 && arr[startRow+2][startCol] == 0 && arr[startRow + 1][startCol + 1] == 0;
}

bool isWestOk(int startRow, int startCol){
    return startRow <= r && startCol > 2 && arr[startRow-1][startCol-1] == 0 && arr[startRow][startCol-2] == 0 && arr[startRow + 1][startCol-1] == 0 && arr[startRow + 2][startCol-1] == 0 && arr[startRow+1][startCol-2] == 0;
}

bool isEastOk(int startRow, int startCol){
    return startRow <= r && startCol <= c - 2 && arr[startRow-1][startCol+1] == 0 && arr[startRow][startCol+2] == 0 && arr[startRow+1][startCol+1] == 0 && arr[startRow+1][startCol+2] == 0 && arr[startRow+2][startCol+1] == 0;
}

void mapRemove(){
    for (int i = 0; i < 73; i++){
        for (int j = 0; j < 71; j++){
            arr[i][j] = 0;
            exits[i][j] = 0;
        }
    }
}

void moveGolem(golem_info a, int num){
    int startRow = 1;
    int startCol = a.mid_col;
    int startDir = a.dir;

    while (1){
        if (isSouthOk(startRow, startCol)){
            startRow++;
        }
        else{
            if (isWestOk(startRow, startCol)){
                startRow++;
                startCol--;
                if (startDir == 0){
                    startDir = 3;
                }
                else{
                    startDir--;
                }
            }
            else{
                if (isEastOk(startRow, startCol)){
                    startRow++;
                    startCol++;
                    if (startDir == 3){
                        startDir = 0;
                    }
                    else{
                        startDir++;
                    }
                }
                else{
                    break;
                }
            }
        }
    }

    if (startRow < 4){
        mapRemove();
    }
    else{
        arr[startRow][startCol] = num;
        arr[startRow-1][startCol] = num;
        arr[startRow+1][startCol] = num;
        arr[startRow][startCol+1] = num;
        arr[startRow][startCol-1] = num;

        if (startDir == 0){
            exits[startRow-1][startCol] = 1;
        }
        else if (startDir == 1){
            exits[startRow][startCol+1] = 1;
        }
        else if (startDir == 2){
            exits[startRow+1][startCol] = 1;
        }
        else if (startDir == 3){
            exits[startRow][startCol-1] = 1;
        }

        calcVal(startRow, startCol, num);
    }
}

int main() {

    cin >> r >> c >> k;

    for (int i = 0; i < k; i++){
        golem_info a;
        int w, e;
        cin >> w >> e;
        a.mid_col = w;
        a.dir = e;
        golems.push_back(a);
    }

    for (int i = 0; i < 73; i++){
        for (int j = 0; j < 71; j++){
            arr[i][j] = 0;
            exits[i][j] = 0;
        }
    }
    
    for (int i = 1; i <= k; i++){
        moveGolem(golems[i-1], i);
    }

    cout << ans;

    return 0;
}
