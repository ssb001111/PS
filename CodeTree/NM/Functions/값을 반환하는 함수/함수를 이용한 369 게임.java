import java.util.*;

public class Main {
    public static boolean isThreeMult(int n){
        if (n % 3 == 0){
            return true;
        }
        else{
            return false;
        }
    }

    public static boolean includeThreeMult(int n){
        while (n / 10 != 0){
            int last_num = n % 10;
            if (last_num != 0 && last_num % 3 == 0){
                return true;
            }
            n /= 10;
        }
        if (n % 3 == 0){
            return true;
        }
        else{
            return false;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int result = 0;
        for (int i = a; i <= b; i++){
            if (isThreeMult(i) || includeThreeMult(i)){
                result++;
            }
        }
        System.out.print(result);
    }
}
