import java.util.*;

public class Main {
    public static void power(int a, int b){
        System.out.print((int)Math.pow(a, b));
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        power(a, b);
    }
}
