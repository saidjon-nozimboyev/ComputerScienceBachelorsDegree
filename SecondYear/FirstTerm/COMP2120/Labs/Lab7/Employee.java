public class Employee {
    protected String name;
    protected int id;
    protected double salary;
    protected String role;

    public Employee(String name, int id, double salary, String role) {
        this.name = name;
        this.id = id;
        this.salary = salary;
        this.role = role;
    }

    public void performDuties() {
        System.out.println(name + " is performing general employee duties");
    }
}