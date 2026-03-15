
class Employee {

    private String employeeName; // add integral and math1020
    private String employeeID;
    private double salary;
    private double bonusPercentage;
    private String address;
    private String jobTitle;

    public String getEmployeeName() {
        return employeeName;
    }

    public void setEmployeeName(String employeeName) {
        if (employeeName != null && !employeeName.isEmpty()) {
            this.employeeName = employeeName;
        } else {
            System.out.println("Invalid name");
        }
    }

    public String getEmployeeID() {
        return employeeID;
    }

    public void setEmployeeID(String employeeID) {
        if (employeeID != null && employeeID.length() == 6) {
            this.employeeID = employeeID;
        } else {
            System.out.println("Employee ID must be exactly 6 characters");
        }
    }

    public double getSalary() {
        return salary;
    }

    public void setSalary(double salary) {
        if (salary >= 30000 && salary <= 200000) {
            this.salary = salary;
        } else {
            System.out.println("Salary must be between 30000 and 200000");
        }
    }

    public double getBonusPercentage() {
        return bonusPercentage;
    }

    public void setBonusPercentage(double bonusPercentage) {
        if (bonusPercentage >= 0 && bonusPercentage <= 100) {
            this.bonusPercentage = bonusPercentage;
        } else {
            System.out.println("Bonus must be between 0 and 100");
        }
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        if (address != null && address.contains(" ")) {
            this.address = address;
        } else {
            System.out.println("Address must contain street and number");
        }
    }

    public String getJobTitle() {
        return jobTitle;
    }

    public void setJobTitle(String jobTitle) {
        if (jobTitle.equals("Manager") || jobTitle.equals("Developer")
                || jobTitle.equals("Designer") || jobTitle.equals("Tester")) {
            this.jobTitle = jobTitle;
        } else {
            System.out.println("Invalid job title");
        }
    }

    public double calculateTotalPay() {
        return salary + (salary * bonusPercentage / 100);
    }
}
