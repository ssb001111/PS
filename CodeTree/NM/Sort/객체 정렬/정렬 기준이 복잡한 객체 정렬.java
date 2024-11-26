import java.util.*;

class Student implements Comparable<Student> {
    String name;
    int first, second, third;

    public Student(String name, int first, int second, int third){
        this.name = name;
        this.first = first;
        this.second = second;
        this.third = third;
    }

    @Override
    public int compareTo(Student student){
        return (this.first + this.second + this.third) - (student.first + student.second + student.third);
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Student[] arr = new Student[n];
        for (int i = 0; i < n; i++){
            String name = sc.next();
            int first = sc.nextInt();
            int second = sc.nextInt();
            int third = sc.nextInt();
            arr[i] = new Student(name, first, second, third);
        }
        Arrays.sort(arr);
        for (int i = 0; i < n; i++){
            System.out.println(arr[i].name + " " + arr[i].first + " " + arr[i].second + " " + arr[i].third);
        }
    }
}
