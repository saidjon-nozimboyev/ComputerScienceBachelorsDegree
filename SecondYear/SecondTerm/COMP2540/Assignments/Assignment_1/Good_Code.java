import java.util.Map.Entry;
import java.util.AbstractMap;
import java.util.LinkedList;
import java.util.Map.Entry;
import java.util.Random;



public class Good_Code {

    public static void main(String[] args) {

        int[] sizes = {800, 1600, 3200, 6400, 10000, 100000};

        Random random = new Random();

        for (int size : sizes) {

            String[] words = new String[size];

            // Generate random numbers from 0 to 100
            // and convert them to Strings
            for (int i = 0; i < size; i++) {
                words[i] = String.valueOf(random.nextInt(101));
            }

            // Start timer
            long startTime = System.currentTimeMillis();

            Entry<String, Integer> result =
                    CountTest.count_LINKED_LIST_GOOD(words);

            // End timer
            long endTime = System.currentTimeMillis();

            long elapsedTime = endTime - startTime;

            System.out.println("Data size: " + size);
            System.out.println("Most frequent word: " + result.getKey());
            System.out.println("Frequency: " + result.getValue());
            System.out.println("Time taken: " + elapsedTime + " ms");
            System.out.println("-------------------------");
        }
    }
}


class CountTest 
{
    public static Entry<String, Integer> count_LINKED_LIST_GOOD(String[] tokens) {
    LinkedList<Entry<String, Integer>> list =
            new LinkedList<Entry<String, Integer>>();

    for (int j = 0; j < tokens.length; j++) {
        String word = tokens[j];
        boolean found = false;

        for (Entry<String, Integer> e : list) {
            if (word.equals(e.getKey())) {
                e.setValue(e.getValue() + 1);
                found = true;
                break;
            }
        }

        if (!found) {
            list.add(new AbstractMap.SimpleEntry<String, Integer>(word, 1));
        }
    }

    int maxCount = 0;
    String maxWord = "";

    for (Entry<String, Integer> e : list) {
        if (e.getValue() > maxCount) {
            maxWord = e.getKey();
            maxCount = e.getValue();
        }
    }

    return new AbstractMap.SimpleEntry<String, Integer>(maxWord, maxCount);
}
    
}