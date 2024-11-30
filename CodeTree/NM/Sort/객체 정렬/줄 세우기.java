import java.util.*;

class Student implements Comparable<Student> {
    int height, weight, number;

    public Student(int height, int weight, int number){
        this.height = height;
        this.weight = weight;
        this.number = number;
    }

    @Override
    public int compareTo(Student student){
        if (this.height != student.height){
            return student.height - this.height;
        }

        if (this.weight != student.weight){
            return student.weight - this.weight;
        }

        return this.number - student.number;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Student[] arr = new Student[n];
        for (int i = 1; i <= n; i++){
            int height = sc.nextInt();
            int weight = sc.nextInt();
            arr[i-1] = new Student(height, weight, i);
        }
        Arrays.sort(arr);
        for (int i = 0; i < n; i++){
            System.out.println(arr[i].height + " " + arr[i].weight + " " + arr[i].number);
        }
    }
}
