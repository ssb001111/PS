#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int arr[5][5];
    pair<int, int> array[25];
    int check[5][5];

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            cin >> arr[i][j];
            array[arr[i][j]-1].first = i;
            array[arr[i][j]-1].second = j;
            check[i][j] = 0;
        }
    }

    int first_bingo_turn = 0;

    for (int i = 0; i < 25; i++){
        int curr;
        cin >> curr;
        int x = array[curr-1].first;
        int y = array[curr-1].second;
        check[x][y] = 1;
        int bingo = 0;
        if (i > 3 and first_bingo_turn == 0){
            int num_left_cross = 0;
            int num_right_cross = 0;
            for (int k = 0; k < 5; k++){
                int num_horizontal = 0;
                int num_vertical = 0;
                for (int l = 0; l < 5; l++){
                    num_horizontal += check[k][l];
                    num_vertical += check[l][k];
                }
                if (num_horizontal == 5){
                    bingo++;
                }
                if (num_vertical == 5){
                    bingo++;
                }
                
                num_left_cross += check[k][k];
                num_right_cross += check[k][4-k];
            }
            if (num_left_cross == 5){
                bingo++;
            }
            if (num_right_cross == 5){
                bingo++;
            }

            if (bingo > 2){
                first_bingo_turn = i+1;
            }
        }
    }

    cout << first_bingo_turn;

    return 0;
}
