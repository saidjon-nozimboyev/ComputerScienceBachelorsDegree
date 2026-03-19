public class PayrollSystem {

    public static void displayEmployeeInfo(Employee emp) {
        System.out.println("Employee Name: " + emp.getEmployeeName());
        System.out.println("Employee ID: " + emp.getEmployeeID());
        System.out.println("Job Title: " + emp.getJobTitle());
        System.out.println("Address: " + emp.getAddress());
        System.out.println("Salary: " + emp.getSalary());
        System.out.println("Bonus %: " + emp.getBonusPercentage());
        System.out.println("Total Pay: " + emp.calculateTotalPay());
        System.out.println("----------------------------------");
    }

    public static void main(String[] args) {

        // Employee 1 (Valid)
        Employee emp1 = new Employee();
        emp1.setEmployeeName("Alice Smith");
        emp1.setEmployeeID("A12345");
        emp1.setSalary(70000);
        emp1.setBonusPercentage(10);
        emp1.setAddress("MainStreet 12");
        emp1.setJobTitle("Developer");

        // Employee 2 (Invalid salary then corrected)
        Employee emp2 = new Employee();
        emp2.setEmployeeName("Bob Johnson");
        emp2.setEmployeeID("B54321");
        emp2.setSalary(25000); // invalid
        emp2.setSalary(50000); // corrected
        emp2.setBonusPercentage(110); // invalid
        emp2.setBonusPercentage(15); // corrected
        emp2.setAddress("OakRoad 45");
        emp2.setJobTitle("Tester");

        Employee emp3 = new Employee();
        emp3.setEmployeeName("Charlie Brown");
        emp3.setEmployeeID("123"); // invalid
        emp3.setEmployeeID("C67890"); // corrected
        emp3.setSalary(60000);
        emp3.setBonusPercentage(8);
        emp3.setAddress("PineStreet 77");
        emp3.setJobTitle("Designer");

        displayEmployeeInfo(emp1);
        displayEmployeeInfo(emp2);
        displayEmployeeInfo(emp3);
    }
}