import java.awt.BorderLayout;
import java.awt.Font;
import java.awt.GridLayout;

import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;

// GUI for Payroll System
public class PayrollPanel extends JFrame {

    // Input fields
    private JTextField name, id, salary, bonus, address;
    private JComboBox<String> job;
    private JTextArea output;

    public PayrollPanel() {
        setTitle("Payroll System");
        setSize(500, 550);
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        setLayout(new BorderLayout(10, 10));

        // 🔹 Form panel (inputs)
        JPanel form = new JPanel(new GridLayout(6, 2, 5, 5));

        name = new JTextField();
        id = new JTextField();
        salary = new JTextField();
        bonus = new JTextField();
        address = new JTextField();

        // Job dropdown options
        String[] jobs = {"Manager", "Developer", "Designer", "Tester"};
        job = new JComboBox<>(jobs);

        // Add labels and fields
        form.add(new JLabel("Name:")); form.add(name);
        form.add(new JLabel("ID:")); form.add(id);
        form.add(new JLabel("Salary:")); form.add(salary);
        form.add(new JLabel("Bonus %:")); form.add(bonus);
        form.add(new JLabel("Address:")); form.add(address);
        form.add(new JLabel("Job Title:")); form.add(job);

        add(form, BorderLayout.NORTH);

        // Output area (center)
        output = new JTextArea();
        output.setEditable(false);
        output.setFont(new Font("Monospaced", Font.PLAIN, 14));

        add(new JScrollPane(output), BorderLayout.CENTER);

        // Button (bottom)
        JButton calcBtn = new JButton("Calculate Pay");
        add(calcBtn, BorderLayout.SOUTH);

        // Button action
        calcBtn.addActionListener(e -> calculate());

        setVisible(true);
    }

    // Method to validate input and calculate pay
    private void calculate() {
        try {
            // Validate name
            if (name.getText().isEmpty()) {
                JOptionPane.showMessageDialog(this, "Enter name");
                return;
            }

            // Validate ID
            if (id.getText().length() != 6) {
                JOptionPane.showMessageDialog(this, "ID must be 6 characters");
                return;
            }

            // Validate salary
            double sal = Double.parseDouble(salary.getText());
            if (sal < 30000 || sal > 200000) {
                JOptionPane.showMessageDialog(this, "Salary must be 30000–200000");
                return;
            }

            // Validate bonus
            double bon = Double.parseDouble(bonus.getText());
            if (bon < 0 || bon > 100) {
                JOptionPane.showMessageDialog(this, "Bonus must be 0–100");
                return;
            }

            // Validate address
            if (!address.getText().contains(" ")) {
                JOptionPane.showMessageDialog(this, "Invalid address");
                return;
            }

            // Create employee only after validation
            Employee emp = new Employee();

            emp.setEmployeeName(name.getText());
            emp.setEmployeeID(id.getText());
            emp.setSalary(sal);
            emp.setBonusPercentage(bon);
            emp.setAddress(address.getText());
            emp.setJobTitle((String) job.getSelectedItem());

            // Display result
            output.setText(
                    "Name: " + emp.getEmployeeName() +
                    "\nID: " + emp.getEmployeeID() +
                    "\nJob: " + emp.getJobTitle() +
                    "\nSalary: " + emp.getSalary() +
                    "\nBonus: " + emp.getBonusPercentage() +
                    "\nTotal Pay: " + emp.calculateTotalPay()
            );

        } catch (NumberFormatException e) {
            // Handles non-numeric input
            JOptionPane.showMessageDialog(this, "Enter valid numbers!");
        }
    }
}