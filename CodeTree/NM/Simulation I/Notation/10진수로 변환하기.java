import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[8];
        int cnt = 0;

        while (true) {
            if (n == 0){
                break;
            }
            arr[cnt++] = n % 10;
            n /= 10;
        }

        int num = 0;
        for (int i = cnt-1; i >= 0; i--){
            num = num * 2 + arr[i];
        }

        System.out.print(num);
    }
}
