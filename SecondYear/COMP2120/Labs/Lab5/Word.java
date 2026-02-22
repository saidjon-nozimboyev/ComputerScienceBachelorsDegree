import java.util.Scanner;

public class Word {

    // Instance variable
    private String[] words;

    // 1. inputWords method
    public void inputWords(Scanner sc, int size) {
        words = new String[size];   // create array

        System.out.println("Enter words:");
        for (int i = 0; i < size; i++) {
            words[i] = sc.next();
        }
    }

    // 2. getLongWords method
    public String[] getLongWords(int minLength) {

        // Count qualifying words
        int count = 0;
        for (String word : words) {
            if (word.length() >= minLength) {
                count++;
            }
        }

        // Create new array
        String[] longWords = new String[count];

        // Copy qualifying words
        int index = 0;
        for (String word : words) {
            if (word.length() >= minLength) {
                longWords[index++] = word;
            }
        }

        return longWords;
    }

    // 3. getWordsStartingWith method
    public String[] getWordsStartingWith(char ch) {

        ch = Character.toLowerCase(ch);

        // Count matching words
        int count = 0;
        for (String word : words) {
            if (Character.toLowerCase(word.charAt(0)) == ch) {
                count++;
            }
        }

        // Create new array
        String[] matchingWords = new String[count];

        // Copy matching words
        int index = 0;
        for (String word : words) {
            if (Character.toLowerCase(word.charAt(0)) == ch) {
                matchingWords[index++] = word;
            }
        }

        return matchingWords;
    }

    // 4. displayWords method
    public void displayWords(String[] arr) {
        if (arr.length == 0) {
            System.out.println("No matching words found.");
            return;
        }

        for (String word : arr) {
            System.out.println(word);
        }
    }
}