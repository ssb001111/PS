import java.util.*;

public class Main {

    public static int[] A = new int[100];

    public static void func(int a1, int a2){
        int result = 0;
        for (int i = a1-1; i <= a2-1; i++){
            result += A[i];
        }
        System.out.println(result);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        for (int i = 0; i < n; i++){
            A[i] = sc.nextInt();
        }
        for (int i = 0; i < m; i++){
            int a1 = sc.nextInt();
            int a2 = sc.nextInt();
            func(a1, a2);
        }
    }
}
