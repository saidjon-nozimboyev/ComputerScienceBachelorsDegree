class Magazine extends LibraryItem 
{
    private String genre;

    public Magazine(String title, String genre, int year) {
        super(title, year);
        this.genre = genre;
    }

    @Override
    public void getItemDetails() {
        System.out.println("Magazine: " + title + ", Genre: " + genre + ", Year: " + year);
        System.out.println("Note: This item is for reference only and cannot be loaned.");
    }
}