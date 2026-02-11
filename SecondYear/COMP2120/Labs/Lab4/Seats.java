import java.util.Scanner;

public class Seats {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        System.out.print("Enter rows: ");
        int rows = input.nextInt();

        System.out.print("Enter columns: ");
        int cols = input.nextInt();

        for (int r = 0; r < rows; r++) {
            char rowLetter = (char)('A' + r);

            for (int c = 1; c <= cols; c++) {
                System.out.print(rowLetter + "" + c + " ");
            }

            System.out.println();
        }
    }
}
