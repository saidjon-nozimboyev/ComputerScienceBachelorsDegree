
import java.util.Random;
import java.util.Scanner;

public class GameLogic {

    static Scanner input = new Scanner(System.in);
    static Random rand = new Random();

    public static boolean askQuestion(Player p) {

        int type = rand.nextInt(4);

        int a = rand.nextInt(20) + 1;
        int b = rand.nextInt(20) + 1;

        double correct = 0;
        String question = "";

        switch (type) {

            case 0 -> {
                correct = a + b;
                question = a + " + " + b;
            }

            case 1 -> {
                int big = Math.max(a, b);
                int small = Math.min(a, b);
                correct = big - small;
                question = big + " - " + small;
            }

            case 2 -> {
                correct = a * b;
                question = a + " * " + b;
            }

            default -> {
                int divisor = rand.nextInt(10) + 1;
                correct = (double) a / divisor;
                correct = Math.round(correct * 100.0) / 100.0;
                question = a + " / " + divisor;
            }
        }

        System.out.print("What is " + question + " ? ");
        double user = input.nextDouble();

        boolean correctAns = Math.abs(user - correct) < 0.01;

        if (correctAns) {
            p.score++;
        }

        p.addSummary(question + " = " + user + " : " + correctAns);

        return correctAns;
    }

    public static void mode1(Player p, int questions) {

        long start = System.currentTimeMillis();

        for (int i = 0; i < questions; i++) {
            askQuestion(p);
        }

        long end = System.currentTimeMillis();

        System.out.println("-- Results --");
        System.out.println("Time taken: " + (end - start) / 1000 + " seconds");
        System.out.println("Score: " + p.score);
        p.printSummary();
    }

    public static void mode2(Player p) {

        long start = System.currentTimeMillis();

        while (true) {

            boolean result = askQuestion(p);

            if (!result) {
                break;
            }
        }

        long end = System.currentTimeMillis();

        System.out.println("-- Results --");
        System.out.println("Time taken: " + (end - start) / 1000 + " seconds");
        System.out.println("Score: " + p.score);
    }

    public static void mode3(Player p) {

        int lives = 3;

        while (lives > 0) {

            System.out.println("[Lives: " + lives + "]");

            boolean result = askQuestion(p);

            if (!result) {
                lives--;
            }
        }

        System.out.println("Lives exhausted!");

        System.out.println("-- Results --");
        System.out.println("Score: " + p.score);
        p.printSummary();
    }

    public static void mode4(Player p, int limit) {

        long start = System.currentTimeMillis();
        int questions = 0;

        while (System.currentTimeMillis() < start + limit * 1000) {

            askQuestion(p);
            questions++;
        }

        System.out.println("Time's up!");

        System.out.println("-- Results --");
        System.out.println("Questions answered: " + questions);
        System.out.println("Score: " + p.score);
        p.printSummary();
    }
}
