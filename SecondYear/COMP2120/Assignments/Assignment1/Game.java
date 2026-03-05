import java.util.Random;
import java.util.Scanner;

public class Game 
{
    static Scanner input = new Scanner(System.in);
    static Random rand = new Random();

    public static double askQuestion(Player p) 
    {
        int type = rand.nextInt(4); // 0 add,1 sub,2 mul,3 div

        int a = rand.nextInt(20) + 1;
        int b = rand.nextInt(20) + 1;

        double correct = 0;
        String question = "";

        if (type == 0) 
        {
            correct = a + b;
            question = a + " + " + b;
        }

        else if (type == 1) 
        {
            int big = Math.max(a, b);
            int small = Math.min(a, b);
            correct = big - small;
            question = big + " - " + small;
        }

        else if (type == 2) 
        {
            correct = a * b;
            question = a + " * " + b;
        }

        else 
        {
            int divisor = rand.nextInt(10) + 1;
            correct = (double)a / divisor;
            correct = Math.round(correct * 100.0) / 100.0;
            question = a + " / " + divisor;
        }

        System.out.print("What is " + question + " ? ");
        double user = input.nextDouble();

        boolean right = Math.abs(user - correct) < 0.01;

        if (right)
            p.score++;
        
        p.addSummary(question + " = " + user + " : " + right);

        return right ? 1 : 0;
    }

    public static void mode1(Player p) 
    {
        System.out.print("How many questions? ");
        int q = input.nextInt();

        long start = System.currentTimeMillis();

        for (int i = 0; i < q; i++) 
            askQuestion(p);
        

        long end = System.currentTimeMillis();

        System.out.println("-- Results --");
        System.out.println("Time taken: " + (end - start)/1000 + " seconds");
        System.out.println("Score: " + p.score);
        p.printSummary();
    }

    public static void mode2(Player p) 
    {
        long start = System.currentTimeMillis();

        while (true) 
        {
            double result = askQuestion(p);
            if (result == 0) 
                break;
            
        }

        long end = System.currentTimeMillis();

        System.out.println("-- Results --");
        System.out.println("Time taken: " + (end - start)/1000 + " seconds");
        System.out.println("Score: " + p.score);
    }

    public static void mode3(Player p) 
    {
        int lives = 3;

        while (lives > 0) 
        {
            System.out.println("[Lives: " + lives + "]");
            double result = askQuestion(p);

            if (result == 0)
                lives--;
            
        }

        System.out.println("Lives exhausted!");

        System.out.println("-- Results --");
        System.out.println("Score: " + p.score);
        p.printSummary();
    }

    public static void mode4(Player p) 
    {
        System.out.print("Enter time limit (seconds): ");
        int limit = input.nextInt();

        long start = System.currentTimeMillis();

        int questions = 0;

        while (System.currentTimeMillis() < start + limit * 1000) 
        {
            askQuestion(p);
            questions++;
        }

        System.out.println("Time's up!");

        System.out.println("-- Results --");
        System.out.println("Questions answered: " + questions);
        System.out.println("Score: " + p.score);

        p.printSummary();
    }

    public static void main(String[] args) 
    {
        System.out.println("==== Game Menu ====");
        System.out.println("1) Make a wish");
        System.out.println("2) No Mistakes");
        System.out.println("3) Take Chances");
        System.out.println("4) Time Trial");

        System.out.print("Choose a mode: ");
        int mode = input.nextInt();

        System.out.print("How many players? ");
        int players = input.nextInt();

        Player[] list = new Player[players];

        for (int i = 0; i < players; i++) 
        {
            System.out.print("Enter player " + (i+1) + " name: ");
            String name = input.next();

            list[i] = new Player(name, 100);

            switch (mode) 
            {
                case 1 -> mode1(list[i]);
                case 2 -> mode2(list[i]);
                case 3 -> mode3(list[i]);
                case 4 -> mode4(list[i]);
                default -> {
                    System.out.println("Invalid mode selected.");
                }
            }
        }

        System.out.println("-- Leaderboard (Score only) --");

        for (int i = 0; i < players; i++) 
        {
            for (int j = i+1; j < players; j++) 
            {
                if (list[j].score > list[i].score) 
                {
                    Player temp = list[i];
                    list[i] = list[j];
                    list[j] = temp;
                }
            }
        }

        for (int i = 0; i < players; i++) 
        {
            System.out.println(list[i].name + " : " + list[i].score);
        }
    }
}