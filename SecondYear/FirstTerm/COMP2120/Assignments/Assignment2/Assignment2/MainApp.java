import java.awt.GridLayout;

import javax.swing.JButton;
import javax.swing.JFrame;

// Main menu window to open different GUI programs
public class MainApp extends JFrame {

    public MainApp() {
        setTitle("COMP2120 Assignment 2");
        setSize(500, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Layout with 3 buttons
        setLayout(new GridLayout(3, 1, 10, 10));

        JButton rpsBtn = new JButton("Rock Paper Scissors");
        JButton seatsBtn = new JButton("Seat Generator");
        JButton payrollBtn = new JButton("Payroll System");

        // Add buttons to frame
        add(rpsBtn);
        add(seatsBtn);
        add(payrollBtn);

        // Open respective windows on click
        rpsBtn.addActionListener(e -> new RockPaperScissorsPanel());
        seatsBtn.addActionListener(e -> new SeatsPanel());
        payrollBtn.addActionListener(e -> new PayrollPanel());
    }

    public static void main(String[] args) {
        new MainApp().setVisible(true);
    }
}