abstract class LibraryItem 
{
    protected String title;
    protected int year;

    public LibraryItem(String title, int year) {
        this.title = title;
        this.year = year;
    }

    public abstract void getItemDetails();
}