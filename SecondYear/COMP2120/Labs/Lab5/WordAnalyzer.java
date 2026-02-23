import java.util.Scanner;

public class WordAnalyzer 
{
    private String[] words;
    
    public void inputWords(Scanner input, int size) 
    {
        words = new String[size];   

        System.out.println("Enter words:");
        for (int i = 0; i < size; i++) 
            words[i] = input.next();

    }
    
    public String[] getLongWords(int minLength) 
    {
        int count = 0;
        for (String word : words) 
        {
            if (word.length() >= minLength) 
                count++;
        }
        
        String[] longWords = new String[count];

        int index = 0;
        for (String word : words) 
        {
            if (word.length() >= minLength) 
                longWords[index++] = word; 
        }

        return longWords;
    }

    public String[] getWordsStartingWith(char ch) 
    {
        ch = Character.toLowerCase(ch);

        int count = 0;
        for (String word : words) 
        {
            if (Character.toLowerCase(word.charAt(0)) == ch) 
                count++;
        }

        String[] matchingWords = new String[count];

        int index = 0;
        for (String word : words) 
        {
            if (Character.toLowerCase(word.charAt(0)) == ch) 
                matchingWords[index++] = word;
        }

        return matchingWords;
    }

    public void displayWords(String[] arr) 
    {
        if (arr.length == 0) 
        {
            System.out.println("No matching words found");
            return;
        }

        for (String word : arr) 
            System.out.println(word);
        
    }
}