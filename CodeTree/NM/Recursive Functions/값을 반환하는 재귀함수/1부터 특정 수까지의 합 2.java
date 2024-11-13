import java.util.*;

public class Main {
    public static int func(int n){
        if (n == 1){
            return 1;
        }
        return func(n-1) + n;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.print(func(n));
    }
}
