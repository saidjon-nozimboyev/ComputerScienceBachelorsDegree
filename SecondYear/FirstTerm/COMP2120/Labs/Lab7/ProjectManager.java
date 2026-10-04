public class ProjectManager extends Employee {

    protected int teamSize;

    public ProjectManager(String name, int id, double salary, String role, int teamSize) {
        super(name, id, salary, role);
        this.teamSize = teamSize;
    }

    @Override
    public void performDuties() {
        System.out.println(name + " is managing teams and overseeing project deadlines.");
    }

    public void scheduleMeeting() {
        System.out.println(name + " is scheduling a team meeting.");
    }
}