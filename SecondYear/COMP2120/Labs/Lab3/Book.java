public class Book 
{
    private String title;
    private double price;
    private Author author;

    public Book(String title, double price, Author author) // constructor
    {
        this.title = title;
        this.price = price;
        this.author = author;
    }

    public void displayBook() // print info
    {
        System.out.println("Title: " + title);
        System.out.println("Price: " + price);
        author.displayAuthor();
    }

    public boolean cheaperThan(Book other) 
    {
        return this.price < other.price;
    }

    public boolean hasSameAuthor(Book other) 
    {
        return this.author.getName().equals(other.author.getName()) && // ==
               this.author.getEmail().equals(other.author.getEmail());
    }

    public boolean withinBudget(double budget) 
    {
        return this.price <= budget;
    }

    public String getTitle() 
    {
        return title;
    }
}
