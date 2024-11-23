import java.util.*;

class Agent {
    char codename;
    int point;

    public Agent(char codename, int point){
        this.codename = codename;
        this.point = point;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Agent[] agents = new Agent[5];
        int leastPoint = 101;
        int leastIndex = 0;
        for (int i = 0; i < 5; i++){
            char codename = sc.next().charAt(0);
            int point = sc.nextInt();
            if (point < leastPoint){
                leastPoint = point;
                leastIndex = i;
            }
            agents[i] = new Agent(codename, point);
        }
        System.out.print(agents[leastIndex].codename + " " + agents[leastIndex].point);
    }
}
