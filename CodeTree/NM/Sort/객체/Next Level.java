import java.util.*;

class Need {
    String id;
    int level;

    public Need() {
        this.id = "codetree";
        this.level = 10;
    }

    public Need(String id, int level){
        this.id = id;
        this.level = level;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String id = sc.next();
        int level = sc.nextInt();

        Need first = new Need();
        Need second = new Need(id, level);

        System.out.println("user " + first.id + " lv " + first.level);
        System.out.print("user " + second.id + " lv " + second.level);
    }
}
