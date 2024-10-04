import java.util.*;

public class Main {

    public static boolean isRange(int r, int c, int N){
        return r - 1 >= 0 && r + 1 < N && c - 1 >= 0 && c + 1 < N;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int[][] arr = new int[n][n];

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                arr[i][j] = sc.nextInt();
            }
        }

        int answer = 0;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                int cnt = 0;
                if (isRange(i, j, n)){
                    for (int r = i-1; r < i+2; r++){
                        for (int c = j-1; c < j+2; c++){
                            if (arr[r][c] == 1){
                                cnt++;
                            }
                        }
                    }
                }
                answer = Math.max(answer, cnt);
            }
        }

        System.out.print(answer);
    }
}
