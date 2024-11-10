import java.util.*;

public class Main {
    public static String original = "";
    public static String substring = "";

    public static void func(){
        if (original.contains(substring)){
            System.out.print(original.indexOf(substring));
        }
        else{
            System.out.print(-1);
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        original = sc.next();
        substring = sc.next();
        func();
    }
}
