
public class Main 
{
    public static void main(String[] args) {

        Book b1 = new Book();
        Book b2 = new Book("Effective Java", "Joshua Bloch", 45.50);

        System.out.println("Book 1 Details:");
        b1.displayDetails();

        System.out.println("Book 2 Details:");
        b2.displayDetails();

        System.out.println("Book 1 (Updated) Details:");
        b1.setProperties("Clean Code", "Robert C. Martin", 32.99);
        b1.displayDetails();

        System.out.println("Book 3 (Copied) Details:");
        Book b3 = new Book(b2);
        b3.displayDetails();

        System.out.println("Total books created: " + Book.totalBooks);
    }
}