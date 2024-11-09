import java.util.*;

public class Main {
    public static String leftSideRight(String s){
        String new_str = "";
        for (int i = 0; i < s.length(); i++){
            new_str = s.charAt(i) + new_str;
        }
        return new_str;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String new_str = leftSideRight(s);
        if (s.equals(new_str)){
            System.out.print("Yes");
        }
        else{
            System.out.print("No");
        }
    }
}
