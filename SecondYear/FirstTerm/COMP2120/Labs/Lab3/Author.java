public class Author 
{
    private String name;
    private String email;

   
    public Author(String name, String email) 
    {
        this.name = name;
        this.email = email;
    }

    public String getName() 
    {
        return name;
    }

    public String getEmail() 
    {
        return email;
    }

    public void displayAuthor()
    {
        System.out.println("Author Name: " + name);
        System.out.println("Author Email: " + email);
    }
}
