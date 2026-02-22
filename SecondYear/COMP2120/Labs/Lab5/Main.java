import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        // 1. Ask for number of words
        System.out.print("Enter number of words: ");
        int size = sc.nextInt();

        // 2. Create object
        Word analyzer = new Word();

        // 3. Call inputWords
        analyzer.inputWords(sc, size);

        // 4. Ask for minimum length and starting character
        System.out.print("\nEnter minimum length: ");
        int minLength = sc.nextInt();

        System.out.print("Enter starting character: ");
        char ch = sc.next().charAt(0);

        // 5. Call methods
        String[] longWords = analyzer.getLongWords(minLength);
        String[] startingWords = analyzer.getWordsStartingWith(ch);

        // 6. Display results
        System.out.println("\n--- Words with length >= " + minLength + " ---");
        analyzer.displayWords(longWords);

        System.out.println("\n--- Words starting with '" + ch + "' ---");
        analyzer.displayWords(startingWords);

        sc.close();
    }
}