import java.util.Scanner;

public class Main 
{
    public static void main(String[] args) 
    {

        Scanner input = new Scanner(System.in);

        System.out.print("Enter number of words: ");
        int size = input.nextInt();

        WordAnalyzer analyzer = new WordAnalyzer();

        analyzer.inputWords(input, size);

        System.out.print("\nEnter minimum length: ");
        int minLength = input.nextInt();

        System.out.print("Enter starting character: ");
        char ch = input.next().charAt(0);

        String[] longWords = analyzer.getLongWords(minLength);
        String[] startingWords = analyzer.getWordsStartingWith(ch);

        System.out.println("\n--- Words with length >= " + minLength + " ---");
        analyzer.displayWords(longWords);

        System.out.println("\n--- Words starting with '" + ch + "' ---");
        analyzer.displayWords(startingWords);

    }
}