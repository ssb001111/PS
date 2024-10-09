#include <iostream>
#include <queue>

using namespace std;

int arr[42][42] = {0,};
int trap[42][42] = {0,};
int L, N, Q;

struct knight{
    int cRow;
    int cCol;
    int height;
    int width;
    int left_life;
    int damage;
    int num;
};

knight knights[31];

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool ok_to_push(int num, int dir){
    bool done[31] = {false,};

    queue<knight> q;
    q.push(knights[num]);
    done[num] = true;

    while (!q.empty()){
        
        knight a = q.front();
        q.pop();
        for (int i = a.cRow; i < a.cRow + a.height; i++){
            for (int j = a.cCol; j < a.cCol + a.width; j++){

                int nR = i + dr[dir];
                int nC = j + dc[dir];

                if (arr[nR][nC] == -1){
                    return false;
                }
                else{
                    if (arr[nR][nC] != 0 && arr[nR][nC] != a.num){
                        if (done[arr[nR][nC]] == false){
                            q.push(knights[arr[nR][nC]]);
                            done[arr[nR][nC]] = true;
                        }
                    }
                }
            }
        }
    }
    return true;
}

void bfs(int num, int dir){
    bool done[31] = {false,};

    queue<knight> q;
    q.push(knights[num]);
    done[num] = true;

    while (!q.empty()){

        knight a = q.front();
        q.pop();
        int no_of_traps = 0;

        for (int i = a.cRow; i < a.cRow + a.height; i++){
            for (int j = a.cCol; j < a.cCol + a.width; j++){
                if (arr[i][j] == a.num){
                    arr[i][j] = 0;
                }
            }
        }        

        for (int i = a.cRow; i < a.cRow + a.height; i++){
            for (int j = a.cCol; j < a.cCol + a.width; j++){

                int nR = i + dr[dir];
                int nC = j + dc[dir];

                if (arr[nR][nC] != 0){
                    if (done[arr[nR][nC]] == false){
                        q.push(knights[arr[nR][nC]]);
                        done[arr[nR][nC]] = true;
                    }
                }

                if (a.num != num){
                    if (trap[nR][nC] == 1){
                        no_of_traps++;
                    }
                }

                arr[nR][nC] = a.num;
            }
        }

        knights[a.num].cRow += dr[dir];
        knights[a.num].cCol += dc[dir];
        knights[a.num].damage += no_of_traps;
        if (a.left_life - no_of_traps <= 0){
            knights[a.num].left_life = 0;
            for (int i = knights[a.num].cRow; i < knights[a.num].cRow + a.height; i++){
                for (int j = knights[a.num].cCol; j < knights[a.num].cCol + a.width; j++){
                    arr[i][j] = 0;
                }
            }   
        }
        else{
            knights[a.num].left_life -= no_of_traps;
        }
    }
}

void moveKnight(int num, int dir){
    if (knights[num].left_life != 0){
        if (ok_to_push(num, dir)){
            bfs(num, dir);
        }
    }
}

int main() {

    cin >> L >> N >> Q;

    for (int i = 0; i <= L+1; i++){
        for (int j = 0; j <= L+1; j++){
            if (i == 0 or i == L+1 or j == 0 or j == L+1){
                arr[i][j] = -1;
            }
            else{
                int a;
                cin >> a;
                if (a == 0){
                    arr[i][j] = 0;
                }
                else if (a == 1){
                    trap[i][j] = 1;
                }
                else{
                    arr[i][j] = -1;
                }
            }
        }
    }

    for (int i = 1; i < N+1; i++){
        int r, c, h, w, K;
        cin >> r >> c >> h >> w >> K;
        knight a;
        a.cRow = r;
        a.cCol = c;
        a.height = h;
        a.width = w;
        a.left_life = K;
        a.damage = 0;
        a.num = i;
        knights[i] = a;
        for (int j = r; j < r + h; j++){
            for (int k = c; k < c + w; k++){
                arr[j][k] = i;
            }
        }
    }

    for (int l = 0; l < Q; l++){
        int i, d;
        cin >> i >> d;
        moveKnight(i, d);
    }

    int ans = 0;
    for (int i = 1; i < N+1; i++){
        if (knights[i].left_life != 0){
            ans += knights[i].damage;
        }
    }
    cout << ans;

    return 0;
}
