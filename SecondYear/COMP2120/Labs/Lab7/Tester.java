public class Tester extends Employee {

    protected String testingType;

    public Tester(String name, int id, double salary, String role, String testingType) {
        super(name, id, salary, role);
        this.testingType = testingType;
    }

    @Override
    public void performDuties() {
        System.out.println(name + " is testing software.");
    }
}