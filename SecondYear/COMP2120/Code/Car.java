
public class Car
{
    static String make = "Toyota"; // class variable
    String model; // instance(object) variable
    int year; // instance(object) variable

    public Car()
    {   
        System.out.println("Object created");
    }

    void printInfo() // method
    {
        System.out.println("Brand: "+ make);
        System.out.println("Model: "+ model);
        System.out.println("Year: "+year);
    }
}
