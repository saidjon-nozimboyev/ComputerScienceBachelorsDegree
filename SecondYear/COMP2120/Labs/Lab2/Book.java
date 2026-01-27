
public class Book 
{
    private String title; //intance variables
    private String author;
    private double price;

    public static int totalBooks = 0; //class variable

    public Book() 
    {
        this.title = "Unknown";
        this.author = "Unknown";
        this.price = 0.0;
        totalBooks++;
    }

    public Book(String title, String author, double price) 
    {
        this.title = title;
        this.author = author;
        this.price = price;
        totalBooks++;
    }

    public Book(Book otherBook) 
    {
        this.title = otherBook.title;
        this.author = otherBook.author;
        this.price = otherBook.price;
        totalBooks++;
    }

    public void setProperties(String title, String author, double price) 
    {
        this.title = title;
        this.author = author;
        this.price = price;
    }

    public void displayDetails() 
    {
        System.out.println("Title: " + title);
        System.out.println("Author: " + author);
        System.out.println("Price: $" + price);
        System.out.println("Total Books: " + totalBooks);
    }
}
