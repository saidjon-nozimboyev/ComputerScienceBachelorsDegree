import javax.swing.JOptionPane;

class Employee {

    private String employeeName;
    private String employeeID;
    private double salary;
    private double bonusPercentage;
    private String address;
    private String jobTitle;

    public String getEmployeeName() { return employeeName; }

    public void setEmployeeName(String employeeName) {
        if (employeeName != null && !employeeName.isEmpty()) {
            this.employeeName = employeeName;
        } else {
            JOptionPane.showMessageDialog(null, "Invalid name");
        }
    }

    public String getEmployeeID() { return employeeID; }

    public void setEmployeeID(String employeeID) {
        if (employeeID != null && employeeID.length() == 6) {
            this.employeeID = employeeID;
        } else {
            JOptionPane.showMessageDialog(null, "ID must be 6 characters");
        }
    }

    public double getSalary() { return salary; }

    public void setSalary(double salary) {
        if (salary >= 30000 && salary <= 200000) {
            this.salary = salary;
        } else {
            JOptionPane.showMessageDialog(null, "Salary must be 30000–200000");
        }
    }

    public double getBonusPercentage() { return bonusPercentage; }

    public void setBonusPercentage(double bonusPercentage) {
        if (bonusPercentage >= 0 && bonusPercentage <= 100) {
            this.bonusPercentage = bonusPercentage;
        } else {
            JOptionPane.showMessageDialog(null, "Bonus must be 0–100");
        }
    }

    public String getAddress() { return address; }

    public void setAddress(String address) {
        if (address != null && address.contains(" ")) {
            this.address = address;
        } else {
            JOptionPane.showMessageDialog(null, "Invalid address");
        }
    }

    public String getJobTitle() { return jobTitle; }

    public void setJobTitle(String jobTitle) {
        if (jobTitle.equals("Manager") || jobTitle.equals("Developer")
                || jobTitle.equals("Designer") || jobTitle.equals("Tester")) {
            this.jobTitle = jobTitle;
        } else {
            JOptionPane.showMessageDialog(null, "Invalid job title");
        }
    }

    public double calculateTotalPay() {
        return salary + (salary * bonusPercentage / 100);
    }
}