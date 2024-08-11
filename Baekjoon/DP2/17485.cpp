#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    int grid[n][m];

    int real[n][m][3];

    int result_minimum = 100000;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];
            if (i == 0){
                real[i][j][0] = grid[i][j];
                real[i][j][1] = grid[i][j];
                real[i][j][2] = grid[i][j];
            }
            else{
                if (j == 0){

                    // "S"
                    real[i][j][1] = real[i-1][j][2] + grid[i][j];
                    if (i == n-1){
                        result_minimum = min(result_minimum, real[i][j][1]);
                    }

                    // "R"
                    int minimum = real[i-1][j+1][0];
                    minimum = min(minimum, real[i-1][j+1][1]);
                    real[i][j][2] = minimum + grid[i][j];
                    if (i == n-1){
                        result_minimum = min(result_minimum, real[i][j][2]);
                    }

                }
                else if (j == m-1){

                    // "S"
                    real[i][j][1] = real[i-1][j][0] + grid[i][j];
                    if (i == n-1){
                        result_minimum = min(result_minimum, real[i][j][1]);
                    }

                    // "L"
                    int minimum = real[i-1][j-1][2];
                    minimum = min(minimum, real[i-1][j-1][1]);
                    real[i][j][0] = minimum + grid[i][j];
                    if (i == n-1){
                        result_minimum = min(result_minimum, real[i][j][0]);
                    }

                }
                else{

                    // "L"
                    int minimum = real[i-1][j-1][2];
                    minimum = min(minimum, real[i-1][j-1][1]);
                    real[i][j][0] = minimum + grid[i][j];
                    if (i == n-1){
                        result_minimum = min(result_minimum, real[i][j][0]);
                    }

                    // "S"
                    minimum = real[i-1][j][0];
                    minimum = min(minimum, real[i-1][j][2]);
                    real[i][j][1] = minimum + grid[i][j];
                    if (i == n-1){
                        result_minimum = min(result_minimum, real[i][j][1]);
                    }

                    // "R"
                    minimum = real[i-1][j+1][0];
                    minimum = min(minimum, real[i-1][j+1][1]);
                    real[i][j][2] = minimum + grid[i][j];
                    if (i == n-1){
                        result_minimum = min(result_minimum, real[i][j][2]);
                    }
                    
                }
            }
        }
    }

    cout << result_minimum;

    return 0;
}
