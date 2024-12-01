import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] arr = new int[4];
        for (int i = 0; i < 4; i++){
            arr[i] = sc.nextInt();
        }
        int first = 60 * arr[0] + arr[1];
        int second = 60 * arr[2] + arr[3];
        System.out.print(second - first);
    }
}
