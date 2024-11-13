import java.util.*;

public class Main {
    public static void print(int curr, int goal){
        System.out.print(curr + " ");
        if (curr != goal){
            print(curr+1, goal);
        }
        else{
            System.out.println();
        }
        System.out.print(curr + " ");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        print(1, n);
    }
}
