public class AutomationTester extends Tester {

    public AutomationTester(String name, int id, double salary, String role, String testingType) {
        super(name, id, salary, role, testingType);
    }

    @Override
    public void performDuties() {
        System.out.println(name + " is writing scripts to automate test cases.");
    }

    public void writeAutomationScript() {
        System.out.println(name + " is writing an automation script for regression testing.");
    }
}