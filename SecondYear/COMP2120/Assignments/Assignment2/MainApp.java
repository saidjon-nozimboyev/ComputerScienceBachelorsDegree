import java.awt.GridLayout;

import javax.swing.JButton;
import javax.swing.JFrame;

public class MainApp extends JFrame {

    public MainApp() {
        setTitle("COMP2120 GUI Project");
        setSize(500, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new GridLayout(3, 1, 10, 10));

        JButton rpsBtn = new JButton("Rock Paper Scissors");
        JButton seatsBtn = new JButton("Seat Generator");
        JButton payrollBtn = new JButton("Payroll System");

        add(rpsBtn);
        add(seatsBtn);
        add(payrollBtn);

        rpsBtn.addActionListener(e -> new RockPaperScissorsPanel());
        seatsBtn.addActionListener(e -> new SeatsPanel());
        payrollBtn.addActionListener(e -> new PayrollPanel());
    }

    public static void main(String[] args) {
        new MainApp().setVisible(true);
    }
}