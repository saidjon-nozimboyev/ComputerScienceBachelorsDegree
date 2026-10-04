
import java.util.Arrays;
import java.util.Comparator;


class Student {
    String name;
    int grade;

    Student(String n, int s) {
        name = n;
        grade = s;
    }
}

public class Main {
    public static void main(String[] args) {

        Student[] students = {
            new Student("Alice", 80),
            new Student("Bob", 95),
            new Student("Charlie", 70)
        };

        // Example: sort by grade
        Arrays.sort(students, Comparator.comparingInt(s -> s.grade));

        // Print results
        for (Student s : students) {
            System.out.println(s.name + " - " + s.grade);
        }
    }
}