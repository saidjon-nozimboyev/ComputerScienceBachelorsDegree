class DVD extends LibraryItem implements Loanable 
{
    private int duration;
    private boolean isAvailable;

    public DVD(String title, int year, int duration) {
        super(title, year);
        this.duration = duration;
        this.isAvailable = true;
    }

    @Override
    public void getItemDetails() {
        System.out.println("DVD: " + title + ", Year: " + year + ", Duration: " + duration + " mins, Available: " + isAvailable);
    }

    @Override
    public void checkout() {
        if (isAvailable) {
            isAvailable = false;
            System.out.println("DVD '" + title + "' checked out.");
        } else {
            System.out.println("DVD '" + title + "' is not available.");
        }
    }

    @Override
    public void returnItem() {
        isAvailable = true;
        System.out.println("DVD '" + title + "' returned.");
    }
}