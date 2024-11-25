import java.util.*;

class Student implements Comparable<Student> {
    String name;
    int korean, english, maths;

    public Student(String name, int korean, int english, int maths){
        this.name = name;
        this.korean = korean;
        this.english = english;
        this.maths = maths;
    }

    @Override
    public int compareTo(Student student){
        if (this.korean != student.korean){
            return student.korean - this.korean;
        }
        if (this.english != student.english){
            return student.english - this.english;
        }
        return student.maths - this.maths;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Student[] arr = new Student[n];
        for (int i = 0; i < n; i++){
            String name = sc.next();
            int korean = sc.nextInt();
            int english = sc.nextInt();
            int maths = sc.nextInt();
            Student a = new Student(name, korean, english, maths);
            arr[i] = a;
        }
        Arrays.sort(arr);
        for (int i = 0; i < n; i++){
            System.out.println(arr[i].name + " " + arr[i].korean + " " + arr[i].english + " " + arr[i].maths);
        }
    }
}
