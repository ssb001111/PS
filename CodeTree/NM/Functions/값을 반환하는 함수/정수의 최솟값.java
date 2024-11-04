import java.util.*;

public class Main {
    public static void sum(int a, int b, int c){
        int minNumber = Math.min(Math.min(a, b), c);
        System.out.print(minNumber);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        sum(a, b, c);
    }
}
