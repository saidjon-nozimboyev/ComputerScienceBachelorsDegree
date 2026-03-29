import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class CalculatorGUI extends JFrame implements ActionListener {

    private JTextField num1Field, num2Field;
    private JButton addBtn, subBtn, mulBtn, divBtn;
    private JLabel resultLabel;

    public CalculatorGUI() {
        setTitle("Calculator GUI");
        setSize(350, 250);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new GridLayout(5, 2, 10, 10));

        // Components
        add(new JLabel("Number 1:"));
        num1Field = new JTextField();
        add(num1Field);

        add(new JLabel("Number 2:"));
        num2Field = new JTextField();
        add(num2Field);

        addBtn = new JButton("Add");
        subBtn = new JButton("Subtract");
        mulBtn = new JButton("Multiply");
        divBtn = new JButton("Divide");

        add(addBtn);
        add(subBtn);
        add(mulBtn);
        add(divBtn);

        resultLabel = new JLabel("Result: ");
        add(resultLabel);

        // Event Handling
        addBtn.addActionListener(this);
        subBtn.addActionListener(this);
        mulBtn.addActionListener(this);
        divBtn.addActionListener(this);

        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        try {
            double num1 = Double.parseDouble(num1Field.getText());
            double num2 = Double.parseDouble(num2Field.getText());
            double result = 0;

            if (e.getSource() == addBtn) result = num1 + num2;
            else if (e.getSource() == subBtn) result = num1 - num2;
            else if (e.getSource() == mulBtn) result = num1 * num2;
            else if (e.getSource() == divBtn) {
                if (num2 == 0) {
                    JOptionPane.showMessageDialog(this, "Cannot divide by zero!");
                    return;
                }
                result = num1 / num2;
            }

            resultLabel.setText("Result: " + result);

        } catch (NumberFormatException ex) {
            JOptionPane.showMessageDialog(this, "Invalid input! Enter numbers only.");
        }
    }

    public static void main(String[] args) {
        new CalculatorGUI();
    }
}