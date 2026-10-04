class Book extends LibraryItem implements Loanable 
{
    private String author;
    private boolean isAvailable;

    public Book(String title, String author, int year) 
    {
        super(title, year);
        this.author = author;
        this.isAvailable = true;
    }

    @Override
    public void getItemDetails() {
        System.out.println("Book: " + title + " by " + author + ", Year: " + year + ", Available: " + isAvailable);
    }

    @Override
    public void checkout() {
        if (isAvailable) {
            isAvailable = false;
            System.out.println("Book '" + title + "' checked out.");
        } else {
            System.out.println("Book '" + title + "' is not available.");
        }
    }

    @Override
    public void returnItem() {
        isAvailable = true;
        System.out.println("Book '" + title + "' returned.");
    }
}