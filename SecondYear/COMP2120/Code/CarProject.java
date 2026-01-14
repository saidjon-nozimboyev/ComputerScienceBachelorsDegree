
public class CarProject
{
    public static void main(String args[])
    {
        Car c1; // declare
        c1 = new Car(); // create object 

        Car c2 = new Car(); // declar + create object

        c1.printInfo();
        c2.printInfo();

        c1.model ="Corolla";
        c1.year = 2025;
        c1.printInfo();

        c2.model="Camry";
        c2.year = 2023;
        c2.printInfo();

        // Car.make = "Ford"; every make becomes Ford
    }
}