import java.util.*;

public class Main {

    public static int result = 0;
    public static int m = 0;

    public static void func(int[] arr){
        while (m != 1){
            result += arr[m-1];
            if (m % 2 == 1){
                m -= 1;
            }
            else{
                m /= 2;
            }
        }
        result += arr[0];
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        m = sc.nextInt();
        int[] arr = new int[n];

        for (int i = 0; i < n; i++){
            arr[i] = sc.nextInt();
        }

        func(arr);
        System.out.print(result);
    }
}
