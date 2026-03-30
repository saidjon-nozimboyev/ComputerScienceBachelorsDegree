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

public class PayrollPanel extends JFrame {

    private JTextField name, id, salary, bonus, address;
    private JComboBox<String> job;
    private JTextArea output;

    public PayrollPanel() {
        setTitle("Payroll System");
        setSize(500, 550); 
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        setLayout(new BorderLayout(10, 10));

        JPanel form = new JPanel(new GridLayout(6, 2, 5, 5));

        name = new JTextField();
        id = new JTextField();
        salary = new JTextField();
        bonus = new JTextField();
        address = new JTextField();

        String[] jobs = {"Manager", "Developer", "Designer", "Tester"};
        job = new JComboBox<>(jobs);

        form.add(new JLabel("Name:")); form.add(name);
        form.add(new JLabel("ID:")); form.add(id);
        form.add(new JLabel("Salary:")); form.add(salary);
        form.add(new JLabel("Bonus %:")); form.add(bonus);
        form.add(new JLabel("Address:")); form.add(address);
        form.add(new JLabel("Job Title:")); form.add(job);

        add(form, BorderLayout.NORTH);

        output = new JTextArea();
        output.setEditable(false);
        output.setFont(new Font("Monospaced", Font.PLAIN, 14));

        JScrollPane scrollPane = new JScrollPane(output);
        add(scrollPane, BorderLayout.CENTER);

        JButton calcBtn = new JButton("Calculate Pay");
        add(calcBtn, BorderLayout.SOUTH);

        calcBtn.addActionListener(e -> calculate());

        setVisible(true);
    }

    private void calculate() {
        try {
            Employee emp = new Employee();

            emp.setEmployeeName(name.getText());
            emp.setEmployeeID(id.getText());
            emp.setSalary(Double.parseDouble(salary.getText()));
            emp.setBonusPercentage(Double.parseDouble(bonus.getText()));
            emp.setAddress(address.getText());
            emp.setJobTitle((String) job.getSelectedItem());

            output.setText(
                    "Name: " + emp.getEmployeeName() +
                    "\nID: " + emp.getEmployeeID() +
                    "\nJob: " + emp.getJobTitle() +
                    "\nSalary: " + emp.getSalary() +
                    "\nBonus: " + emp.getBonusPercentage() +
                    "\nTotal Pay: " + emp.calculateTotalPay()
            );

        } catch (Exception e) {
            JOptionPane.showMessageDialog(this, "Invalid input!");
        }
    }
}