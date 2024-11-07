import java.util.*;

public class Main {

    public static boolean isMultFour(int n){
        if (n % 4 == 0){
            return true;
        }
        else{
            return false;
        }
    }

    public static boolean isLeap(int n){
        if (n % 100 == 0 && n % 400 != 0){
            return false;
        }
        else{
            return true;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int y = sc.nextInt();
        if (isMultFour(y)){
            if (isLeap(y)){
                System.out.print("true");
            }
            else{
                System.out.print("false");
            }
        }
        else{
            System.out.print("false");
        }
    }
}
