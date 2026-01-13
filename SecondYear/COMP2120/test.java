//                              INSTANCE

// public class Car
// {
//     static string manufact = "Toyota"; //class variable
//     string model; // instance variable
//     int year; // instance variable
    
//     public void printProperties()
//     {
//         System.out.println(manufact);
//         System.out.println(model);
//         System.out.println(year);
//     }
// }

// public class Test{
//     public static void main(String args[])
//     {
//         Car c1 = new Car(); // object create
//         Car c2 = new Car(); // object create
//         c1.model="Camry";
//         c1.year = 2016;
//         c1.printProperties();
//     }
// }


//                              CONSTRUCTOR

public class Car
{
    string model;
    int year;
    static String make = "Toyota";

    public Car()
    {
        model = "Rav4";
        year = 2026;
    }
}

Car c1 = new Car(); // c1 model = Rav4, c1 year = 2026 default
Car c2 = new Car();  // c1 model = Rav4, c1 year = 2026 default