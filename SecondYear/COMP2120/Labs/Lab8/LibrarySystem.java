public class LibrarySystem 
{
    public static void processLibraryItem(LibraryItem item) 
    {
        System.out.println("\nProcessing Item:");

        item.getItemDetails();

        if (item instanceof Loanable) {
            Loanable loanItem = (Loanable) item;
            loanItem.checkout();
            loanItem.returnItem();
        } else {
            System.out.println("This item is not loanable.");
        }
    }

    public static void main(String[] args) {

        Book book = new Book("The Alchemist", "Paulo Coelho", 1993);
        Magazine magazine = new Magazine("National Geographic", "Science", 2022);
        DVD dvd = new DVD("Inception", 2010, 148);

        processLibraryItem(book);
        processLibraryItem(magazine);
        processLibraryItem(dvd);
    }
}