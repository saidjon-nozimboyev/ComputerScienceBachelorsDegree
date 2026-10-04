import java.io.File;
import java.util.AbstractMap;
import java.util.Arrays;
import java.util.Map.Entry;
import java.util.Scanner;

public class Count_Array {

    public static void main(String[] args) throws Exception {

        String[] tokens = readWordsFromFile("text.txt");

        long startTime = System.currentTimeMillis();

        Entry<String, Integer> result = countFAST(tokens);

        // End timer
        long endTime = System.currentTimeMillis();

        System.out.println("Most frequent word: " + result.getKey());
        System.out.println("Frequency: " + result.getValue());
        System.out.println("Time taken: " + (endTime - startTime) + " ms");
    }

    public static Entry<String, Integer> countFAST(String[] tokens) {

        if (tokens.length == 0) {
            return new AbstractMap.SimpleEntry<String, Integer>("", 0);
        }

        Arrays.sort(tokens);

        String maxWord = tokens[0];
        int maxCount = 1;

        String currentWord = tokens[0];
        int currentCount = 1;

        for (int i = 1; i < tokens.length; i++) {

            if (tokens[i].equals(currentWord)) {
                currentCount++;
            } else {

                if (currentCount > maxCount) {
                    maxCount = currentCount;
                    maxWord = currentWord;
                }

                currentWord = tokens[i];
                currentCount = 1;
            }
        }

        if (currentCount > maxCount) {
            maxCount = currentCount;
            maxWord = currentWord;
        }

        return new AbstractMap.SimpleEntry<String, Integer>(
                maxWord, maxCount
        );
    }

    public static String[] readWordsFromFile(String fileName) throws Exception {

        Scanner scanner = new Scanner(new File(fileName));
        scanner.useDelimiter("[^a-zA-Z]+");

        int size = 0;

        while (scanner.hasNext()) {
            scanner.next();
            size++;
        }

        scanner.close();

        String[] tokens = new String[size];

        scanner = new Scanner(new File(fileName));
        scanner.useDelimiter("[^a-zA-Z]+");

        int i = 0;

        while (scanner.hasNext()) {
            tokens[i] = scanner.next().toLowerCase();
            i++;
        }

        scanner.close();

        return tokens;
    }
}