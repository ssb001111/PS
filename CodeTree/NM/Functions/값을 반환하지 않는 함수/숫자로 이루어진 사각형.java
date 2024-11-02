import java.util.*;

public class Main {
    public static void printSquare(int n){
        int a = 1;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                System.out.print(a + " ");
                a++;
                if (a == 10){
                    a = 1;
                }
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        printSquare(n);
    }
}
