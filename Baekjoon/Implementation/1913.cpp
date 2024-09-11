#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int arr[n][n];

    int first = n / 2;

    arr[first][first] = 1;

    int num;
    cin >> num;

    int num_x = first;
    int num_y = first;

    if (n != 1){
        
        int last = n-1;
        int start = 2;

        int last_x = first;
        int last_y = first;
        int the_number_now = 2;

        while (start <= last){
            last_x--;

            for (int i = 0; i < start; i++){
                arr[last_x][last_y + i] = the_number_now;
                if (the_number_now == num){
                    num_x = last_x;
                    num_y = last_y + i;
                }
                the_number_now++;
            }

            last_y += start-1;
            last_x++;

            for (int i = 0; i < start; i++){
                arr[last_x + i][last_y] = the_number_now;
                if (the_number_now == num){
                    num_x = last_x + i;
                    num_y = last_y;
                }
                the_number_now++;
            }

            last_x += start-1;
            last_y--;

            for (int i = 0; i < start; i++){
                arr[last_x][last_y - i] = the_number_now;
                if (the_number_now == num){
                    num_x = last_x;
                    num_y = last_y - i;
                }
                the_number_now++;
            }

            last_y -= start-1;
            last_x--;

            for (int i = 0; i < start; i++){
                arr[last_x - i][last_y] = the_number_now;
                if (the_number_now == num){
                    num_x = last_x - i;
                    num_y = last_y;
                }
                the_number_now++;
            }

            last_x -= start-1;

            start += 2;
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << num_x + 1 << " " << num_y + 1;

    return 0;
}
