#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int N, M, P, C, D;
int arr[52][52];

int rdr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int rdc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int sdr[4] = {-1, 0, 1, 0};
int sdc[4] = {0, 1, 0, -1};

struct Rudolph{
    int cRow;
    int cCol;
};

struct Santa{
    int sNum;
    int cRow;
    int cCol;
    bool isOut;
    bool isComa;
    int whenAlive;
    int score;
};

int calDist(int fRow, int sRow, int fCol, int sCol){
    int result = pow((fRow-sRow), 2) + pow((fCol-sCol), 2);
    return result;
}

bool checkInGrid(int row, int col){
    return 0 < row && row <= N && 0 < col && col <= N;
}

Rudolph r;
Santa santaArr[31];

// arr[row][col]에 현재 direction 방향으로 santaIndex번째 santa가 들어왓고 놓고 싶은데 다른 santa가 있음!
void bfs(int row, int col, int santaIndex, int direction, int r_s){

    queue<int> q;

    int santa = arr[row][col];
    arr[row][col] = santaIndex;
    santaArr[santaIndex].cRow = row;
    santaArr[santaIndex].cCol = col;

    q.push(santa);

    while (!q.empty()){

        santa = q.front();
        q.pop();

        int nR;
        int nC;

        if (r_s == 0){
            nR = santaArr[santa].cRow + rdr[direction];
            nC = santaArr[santa].cCol + rdc[direction];
        }
        else{
            nR = santaArr[santa].cRow + sdr[direction];
            nC = santaArr[santa].cCol + sdc[direction];
        }
        

        if (arr[nR][nC] == -2){
            santaArr[santa].isOut = true;
        }
        else if (arr[nR][nC] == -1){
            arr[nR][nC] = santa;
            santaArr[santa].cRow = nR;
            santaArr[santa].cCol = nC;
        }
        else{
            q.push(arr[nR][nC]);
            arr[nR][nC] = santa;
            santaArr[santa].cRow = nR;
            santaArr[santa].cCol = nC;
        }
    }
}

void moveRudolph(int turn){

    arr[r.cRow][r.cCol] = -1;

    int index = 1;
    bool found = false;

    int current_min_dist;

    while (!found){
        if (!santaArr[index].isOut){
            found = true;
            current_min_dist = calDist(r.cRow, santaArr[index].cRow, r.cCol, santaArr[index].cCol);
        }
        else{
            index++;
        }
    }  

    for (int i = index + 1; i <= P; i++){
        if (!santaArr[i].isOut){
            int new_dist = calDist(r.cRow, santaArr[i].cRow, r.cCol, santaArr[i].cCol);
            if (new_dist < current_min_dist){
                index = i;
                current_min_dist = new_dist;
            }
            else if (new_dist == current_min_dist){
                int curr_santa_r = santaArr[index].cRow;
                int new_santa_r = santaArr[i].cRow;
                if (curr_santa_r < new_santa_r){
                    index = i;
                    current_min_dist = new_dist;
                }
                else if (curr_santa_r == new_santa_r){
                    int curr_santa_c = santaArr[index].cCol;
                    int new_santa_c = santaArr[i].cCol;
                    if (curr_santa_c < new_santa_c){
                        index = i;
                        current_min_dist = new_dist;
                    }
                }
            }
        }
    }

    int direction = 0;
    int min_dist = 2*50*50;

    for (int i = 0; i < 8; i++){
        int nR = r.cRow + rdr[i];
        int nC = r.cCol + rdc[i];
        if (checkInGrid(nR, nC)){
            int a = calDist(nR, santaArr[index].cRow, nC, santaArr[index].cCol);
            if (a < min_dist){
                direction = i;
                min_dist = a;
            }
        }
    }

    r.cRow += rdr[direction];
    r.cCol += rdc[direction];
    if (arr[r.cRow][r.cCol] > 0){
        int toMoveSanta = arr[r.cRow][r.cCol];
        arr[r.cRow][r.cCol] = 0;
        santaArr[toMoveSanta].score += C;
        santaArr[toMoveSanta].isComa = true;
        santaArr[toMoveSanta].whenAlive = turn + 2;
        int nR = santaArr[toMoveSanta].cRow + C * rdr[direction];
        int nC = santaArr[toMoveSanta].cCol + C * rdc[direction];
        if (checkInGrid(nR, nC)){
            if (arr[nR][nC] > 0){
                bfs(nR, nC, toMoveSanta, direction, 0);
            }
            else{
                arr[nR][nC] = toMoveSanta;
                santaArr[toMoveSanta].cRow = nR;
                santaArr[toMoveSanta].cCol = nC;
            }
        }
        else{
            santaArr[toMoveSanta].isOut = true;
        }
    }
    else if (arr[r.cRow][r.cCol] == -1){
        arr[r.cRow][r.cCol] = 0;
    }
}

void moveSanta(int index, int turn){
    int initial_dist = calDist(r.cRow, santaArr[index].cRow, r.cCol, santaArr[index].cCol);
    
    int min_dist = 2*50*50;
    int direction = -1;

    for (int i = 0; i < 4; i++){
        int nR = santaArr[index].cRow + sdr[i];
        int nC = santaArr[index].cCol + sdc[i];
        if (checkInGrid(nR, nC)){
            if (arr[nR][nC] == -1 or arr[nR][nC] == 0){
                int new_dist = calDist(r.cRow, nR, r.cCol, nC);
                if (new_dist < initial_dist){
                    if (new_dist < min_dist){
                        min_dist = new_dist;
                        direction = i;
                    }
                }
            }
        }
    }

    if (direction != -1){
        arr[santaArr[index].cRow][santaArr[index].cCol] = -1;
        int nR = santaArr[index].cRow + sdr[direction];
        int nC = santaArr[index].cCol + sdc[direction];
        
        // 만약 update한 칸에 루돌프가 있다면
        if (arr[nR][nC] == 0){
            // 0 -> 2, 1 -> 3, 2 -> 0, 3 -> 1
            int new_direction = (direction + 2) % 4;
            nR += D * sdr[new_direction];
            nC += D * sdc[new_direction];
            santaArr[index].score += D;
            santaArr[index].isComa = true;
            santaArr[index].whenAlive = turn + 2;
            if (checkInGrid(nR, nC)){
                if (arr[nR][nC] > 0){
                    bfs(nR, nC, index, new_direction, 1);
                }
                else{
                    arr[nR][nC] = index;
                    santaArr[index].cRow = nR;
                    santaArr[index].cCol = nC;
                }
            }
            else{
                santaArr[index].isOut = true;
            }
        }
        else{
            arr[nR][nC] = index;
            santaArr[index].cRow = nR;
            santaArr[index].cCol = nC;
        }
    }
}

void updateSantaScore(){
    for (int i = 1; i <= P; i++){
        if (!santaArr[i].isOut){
            santaArr[i].score++;
        }
    }
}

void printAllSantaScore(){
    for (int i = 1; i <= P; i++){
        cout << santaArr[i].score << " ";
    }
}

bool func(int turn){

    // 기절해 있던, 현재 턴에 깨워야 하는 산타 깨우기
    for (int i = 1; i <= P; i++){
        if (!santaArr[i].isOut and santaArr[i].isComa){
            if (santaArr[i].whenAlive == turn){
                santaArr[i].isComa = false;
                santaArr[i].whenAlive = 0;
            }
        }
    }

    moveRudolph(turn);

    for (int i = 1; i <= P; i++){
        if (!santaArr[i].isOut and !santaArr[i].isComa){
            moveSanta(i, turn);
        }
    }

    int numOfLeftSantas = 0;
    for (int i = 1; i <= P; i++){
        if (!santaArr[i].isOut){
            numOfLeftSantas++;
        }
    }
    if (numOfLeftSantas == 0){
        return false;
    }
    else{
        updateSantaScore();
        return true;
    }
    
}

int main() {

    cin >> N >> M >> P >> C >> D;

    for (int i = 0; i <= N+1; i++){
        for (int j = 0; j <= N+1; j++){
            if (i == 0 or i == N+1 or j == 0 or j == N+1){
                arr[i][j] = -2;
            }
            else{
                arr[i][j] = -1;
            }
        }
    }

    cin >> r.cRow >> r.cCol;
    arr[r.cRow][r.cCol] = 0;

    for (int i = 0; i < P; i++){
        int p, sr, sc;
        cin >> p >> sr >> sc;
        Santa s;
        s.sNum = p;
        s.cRow = sr;
        s.cCol = sc;
        s.isOut = false;
        s.isComa = false;
        s.whenAlive = 0;
        s.score = 0;
        santaArr[p] = s;
        arr[sr][sc] = p;
    }

    for (int i = 0; i < M; i++){
        bool ok = func(i);
        if (ok == false){
            printAllSantaScore();
            return 0;
        }
    }

    printAllSantaScore();

    return 0;
}
