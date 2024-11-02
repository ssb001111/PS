import java.util.*;

public class Main {
    public static void getLCM(int lower, int greater){
        int highestD = 1;
        for (int i = 2; i <= lower; i++){
            if (lower % i == 0 && greater % i == 0){
                highestD = i;
            }
        }

        int l = lower / highestD;
        int g = greater / highestD;

        System.out.println(highestD * l * g);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int lower = n < m ? n : m;
        int greater = n < m ? m : n;
        getLCM(lower, greater);
    }
}
