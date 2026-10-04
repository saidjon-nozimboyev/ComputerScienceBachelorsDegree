public class Main {
    public static void main(String[] args) {

        BackendDeveloper backendDev = new BackendDeveloper("Alice", 101, 6000.0, "Backend Developer", "Java");
        AutomationTester tester = new AutomationTester("Bob", 102, 5500.0, "Automation Tester", "Selenium");
        ProjectManager manager = new ProjectManager("Carol", 103, 8000.0, "Project Manager", 5);
        BackendDeveloper backendDev2 = new BackendDeveloper("Mike", 104, 6500.0, "Backend Developer", "Java");

        // Polymorphism
        Employee emp1 = backendDev;
        Employee emp2 = tester;
        Employee emp3 = manager;
        Employee emp4 = backendDev2;

        emp1.performDuties();
        emp2.performDuties();
        emp3.performDuties();
        emp4.performDuties();

        backendDev.optimizeDatabase();
        tester.writeAutomationScript();
        manager.scheduleMeeting();
    }
}