public class Developer extends Employee {

    protected String programmingLanguage;

    public Developer(String name, int id, double salary, String role, String programmingLanguage) {
        super(name, id, salary, role);
        this.programmingLanguage = programmingLanguage;
    }

    @Override
    public void performDuties() {
        System.out.println(name + " is developing software using " + programmingLanguage + ".");
    }
}