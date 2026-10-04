import javax.swing.JOptionPane;

class Employee {

    // Variables for employee information
    private String employeeName;
    private String employeeID;
    private double salary;
    private double bonusPercentage;
    private String address;
    private String jobTitle;

    // Get employee name
    public String getEmployeeName() { return employeeName; }

    // Set employee name with validation
    public void setEmployeeName(String employeeName) {
        if (employeeName != null && !employeeName.isEmpty()) {
            this.employeeName = employeeName;
        } else {
            JOptionPane.showMessageDialog(null, "Invalid name");
        }
    }

    // Get employee ID
    public String getEmployeeID() { return employeeID; }

    // Set employee ID (must be 6 characters)
    public void setEmployeeID(String employeeID) {
        if (employeeID != null && employeeID.length() == 6) {
            this.employeeID = employeeID;
        } else {
            JOptionPane.showMessageDialog(null, "ID must be 6 characters");
        }
    }

    // Get salary
    public double getSalary() { return salary; }

    // Set salary with range validation
    public void setSalary(double salary) {
        if (salary >= 30000 && salary <= 200000) {
            this.salary = salary;
        } else {
            JOptionPane.showMessageDialog(null, "Salary must be 30000–200000");
        }
    }

    // Get bonus percentage
    public double getBonusPercentage() { return bonusPercentage; }

    // Set bonus with validation
    public void setBonusPercentage(double bonusPercentage) {
        if (bonusPercentage >= 0 && bonusPercentage <= 100) {
            this.bonusPercentage = bonusPercentage;
        } else {
            JOptionPane.showMessageDialog(null, "Bonus must be 0–100");
        }
    }

    // Get address
    public String getAddress() { return address; }

    // Set address (must contain space)
    public void setAddress(String address) {
        if (address != null && address.contains(" ")) {
            this.address = address;
        } else {
            JOptionPane.showMessageDialog(null, "Invalid address");
        }
    }

    // Get job title
    public String getJobTitle() { return jobTitle; }

    // Set job title (only specific roles allowed)
    public void setJobTitle(String jobTitle) {
        if (jobTitle.equals("Manager") || jobTitle.equals("Developer")
                || jobTitle.equals("Designer") || jobTitle.equals("Tester")) {
            this.jobTitle = jobTitle;
        } else {
            JOptionPane.showMessageDialog(null, "Invalid job title");
        }
    }

    // Calculate total pay (salary + bonus)
    public double calculateTotalPay() {
        return salary + (salary * bonusPercentage / 100);
    }
}