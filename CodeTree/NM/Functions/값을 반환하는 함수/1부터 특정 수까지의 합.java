import java.util.*;

public class Main {
    public static int func(int n){
        if (n == 0){
            return 0;
        }
        else{
            return n + func(n-1);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int result = func(n) / 10;
        System.out.print(result);
    }
}
