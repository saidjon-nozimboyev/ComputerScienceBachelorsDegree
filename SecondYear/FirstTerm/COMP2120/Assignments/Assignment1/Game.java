
import java.util.Scanner;

public class Game {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        System.out.println("1) Single Player");
        System.out.println("2) Multiplayer");

        System.out.print("Choose option: ");
        int option = input.nextInt();

        System.out.println("==== Game Menu ====");
        System.out.println("1) Make a wish");
        System.out.println("2) No Mistakes");
        System.out.println("3) Take Chances");
        System.out.println("4) Time Trial");

        System.out.print("Choose a mode: ");
        int mode = input.nextInt();

        if (option == 1) {

            Player p = new Player("Player", 100);

            switch (mode) {

                case 1 -> {
                    System.out.print("How many questions? ");
                    int q = input.nextInt();
                    GameLogic.mode1(p, q);
                }

                case 2 ->
                    GameLogic.mode2(p);

                case 3 ->
                    GameLogic.mode3(p);

                case 4 -> {
                    System.out.print("Enter time limit (seconds): ");
                    int limit = input.nextInt();
                    GameLogic.mode4(p, limit);
                }
            }
        } else if (option == 2) {

            System.out.print("How many players? ");
            int players = input.nextInt();

            int questions = 0;
            int timeLimit = 0;

            if (mode == 1) {
                System.out.print("How many questions? ");
                questions = input.nextInt();
            }

            if (mode == 4) {
                System.out.print("Enter time limit (seconds): ");
                timeLimit = input.nextInt();
            }

            Player[] list = new Player[players];

            for (int i = 0; i < players; i++) {

                System.out.print("Enter player " + (i + 1) + " name: ");
                String name = input.next();

                list[i] = new Player(name, 100);

                switch (mode) {

                    case 1 ->
                        GameLogic.mode1(list[i], questions);
                    case 2 ->
                        GameLogic.mode2(list[i]);
                    case 3 ->
                        GameLogic.mode3(list[i]);
                    case 4 ->
                        GameLogic.mode4(list[i], timeLimit);
                }
            }

            System.out.println("-- Leaderboard --");

            for (int i = 0; i < players; i++) {
                for (int j = i + 1; j < players; j++) {

                    if (list[j].score > list[i].score) {

                        Player temp = list[i];
                        list[i] = list[j];
                        list[j] = temp;
                    }
                }
            }

            for (int i = 0; i < players; i++) {
                System.out.println(list[i].name + " : " + list[i].score);
            }
        }
    }
}
