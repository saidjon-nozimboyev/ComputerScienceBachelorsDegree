import java.util.Random;
import java.util.Scanner;

public class RockPaperScissors {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        Random rand = new Random();

        String[] options = {"rock", "paper", "scissors"};

        while (true) {
            System.out.print("Enter rock, paper, or scissors (or exit to quit): ");
            String user = input.nextLine().toLowerCase();

            if (user.equals("exit")) {
                System.out.println("Game over.");
                break;
            }

            if (!user.equals("rock") && !user.equals("paper") && !user.equals("scissors")) {
                System.out.println("Invalid input! Try again.");
                continue;
            }

            String computer = options[rand.nextInt(3)];
            System.out.println("Computer chose: " + computer);

            if (user.equals(computer)) {
                System.out.println("It's a tie!");
            }
            else if (
                (user.equals("rock") && computer.equals("scissors")) ||
                (user.equals("scissors") && computer.equals("paper")) ||
                (user.equals("paper") && computer.equals("rock"))
            ) {
                System.out.println("You win this round!");
            }
            else {
                System.out.println("Computer wins this round!");
            }
        }
    }
}
