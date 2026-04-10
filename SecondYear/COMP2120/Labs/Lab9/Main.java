import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        System.out.println("Enter number of courses:");

        int n = input.nextInt();
        input.nextLine();

        ArrayList<String> courses = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            courses.add(input.nextLine());
        }

        HashMap<String, Integer> map = new HashMap<>();

        for (String course : courses) {
            if (map.containsKey(course)) {
                map.put(course, map.get(course) + 1);
            } else {
                map.put(course, 1);
            }
        }

        // Convert map to list
        List<Map.Entry<String, Integer>> list = new ArrayList<>(map.entrySet());

        for (Map.Entry<String, Integer> entry : list) {
            System.out.println(entry.getKey() + ": " + entry.getValue());
        }

        // Sort by value 
        Collections.sort(list, (a, b) -> b.getValue() - a.getValue());

        // Print sorted results
        for (Map.Entry<String, Integer> entry : list) {
            System.out.println(entry.getKey() + ": " + entry.getValue());
        }

        input.close();
    }
}