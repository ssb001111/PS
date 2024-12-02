import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] numOfDays = new int[]{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int[] arr = new int[4];
        for (int i = 0; i < 4; i++){
            arr[i] = sc.nextInt();
        }

        int first = 0;
        for (int i = 0; i < arr[0]; i++){
            first += numOfDays[i];
        }
        first += arr[1];

        int second = 0;
        for (int i = 0; i < arr[2]; i++){
            second += numOfDays[i];
        }
        second += arr[3];

        System.out.print(second - first + 1);
    }
}
