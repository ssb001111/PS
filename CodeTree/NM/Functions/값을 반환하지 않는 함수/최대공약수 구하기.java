import java.util.*;

public class Main {
    public static void findCommonD(int lower, int higher){
        int highestD = 1;
        for (int i = 2; i <= lower; i++){
            if (lower % i == 0 && higher % i == 0){
                highestD = i;
            }
        }
        System.out.print(highestD);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int lower = a < b ? a : b;
        int higher = a < b? b : a;
        findCommonD(lower, higher);
    }
}
