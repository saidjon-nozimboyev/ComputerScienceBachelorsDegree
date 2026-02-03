import java.util.Scanner;

public class Test {
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);

        // Book 1 input
        System.out.println("Enter details for Book 1:");
        System.out.print("Author Name: ");
        String a1Name = input.nextLine();

        System.out.print("Author Email: ");
        String a1Email = input.nextLine();

        System.out.print("Book Title: ");
        String b1Title = input.nextLine();

        System.out.print("Book Price: ");
        double b1Price = input.nextDouble();
        input.nextLine(); // clear buffer

        Author author1 = new Author(a1Name, a1Email);
        Book book1 = new Book(b1Title, b1Price, author1);

        // Book 2 input
        System.out.println("Enter details for Book 2:");
        System.out.print("Author Name: ");
        String a2Name = input.nextLine();

        System.out.print("Author Email: ");
        String a2Email = input.nextLine();

        System.out.print("Book Title: ");
        String b2Title = input.nextLine();
        System.out.print("Book Price: ");

        double b2Price = input.nextDouble();

        Author author2 = new Author(a2Name, a2Email);
        Book book2 = new Book(b2Title, b2Price, author2);

        // Display books
        System.out.println("\nBook 1 Details:");
        book1.displayBook();

        System.out.println("\nBook 2 Details:");
        book2.displayBook();

        // Compare prices
        if (book1.cheaperThan(book2)) 
        {
            System.out.println(book1.getTitle() + " is cheaper than " + book2.getTitle() + ".");
        } else 
        {
            System.out.println(book2.getTitle() + " is cheaper than " + book1.getTitle() + ".");
        }

        if (book1.hasSameAuthor(book2)) 
        {
            System.out.println("The two books have the same author.");
        } 
        else 
        {
            System.out.println("The two books do not have the same author.");
        }

        // Budget checks
        System.out.print("Enter budget for Book 1: ");
        double budget1 = input.nextDouble();
        if (book1.withinBudget(budget1))
        {
            System.out.println("The book '" + book1.getTitle() + "' is within the budget of " + budget1 + ".");
        } 
        else 
        {
            System.out.println("The book '" + book1.getTitle() + "' is not within the budget of " + budget1 + ".");
        }

        System.out.print("Enter budget for Book 2: ");
        double budget2 = input.nextDouble();

        if (book2.withinBudget(budget2)) 
        {
            System.out.println("The book '" + book2.getTitle() + "' is within the budget of " + budget2 + ".");
        } 
        else 
        {
            System.out.println("The book '" + book2.getTitle() + "' is not within the budget of " + budget2 + ".");
        }

        input.close();
    }
}
