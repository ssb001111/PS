import java.util.*;

class Need {
    String secretCode;
    char meetingPoint;
    int time;

    public Need(String secretCode, char meetingPoint, int time){
        this.secretCode = secretCode;
        this.meetingPoint = meetingPoint;
        this.time = time;
    }
};

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String secretCode = sc.next();
        char meetingPoint = sc.next().charAt(0);
        int time = sc.nextInt();
        Need need = new Need(secretCode, meetingPoint, time);
        System.out.println("secret code : " + secretCode);
        System.out.println("meeting point : " + meetingPoint);
        System.out.println("time : " + time);
    }
}
