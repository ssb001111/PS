import java.util.*;

public class Main {

    public static int func(int n){
        if (n < 10){
            return (int)Math.pow(n, 2);
        }
        return func(n / 10) + (int)Math.pow(n % 10, 2);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.print(func(n));
    }
}
