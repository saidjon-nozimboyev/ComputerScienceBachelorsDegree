import java.awt.BorderLayout;
import java.awt.Font;
import java.awt.GridLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;

// GUI to generate seat arrangement
public class SeatsPanel extends JFrame {

    private JTextField rowsField, colsField;
    private JTextArea output;

    public SeatsPanel() {
        setTitle("Seat Generator");
        setSize(500, 500);
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        setLayout(new BorderLayout(10, 10));

        // Input panel
        JPanel inputPanel = new JPanel(new GridLayout(2, 2, 5, 5));

        inputPanel.add(new JLabel("Rows:"));
        rowsField = new JTextField();
        inputPanel.add(rowsField);

        inputPanel.add(new JLabel("Columns:"));
        colsField = new JTextField();
        inputPanel.add(colsField);

        add(inputPanel, BorderLayout.NORTH);

        // Output area
        output = new JTextArea();
        output.setEditable(false);
        output.setFont(new Font("Monospaced", Font.PLAIN, 14));

        add(new JScrollPane(output), BorderLayout.CENTER);

        // Button
        JButton generateBtn = new JButton("Generate Seats");
        add(generateBtn, BorderLayout.SOUTH);

        generateBtn.addActionListener(e -> generateSeats());

        setVisible(true);
    }

    // Generate seat layout
    private void generateSeats() {
        try {
            int rows = Integer.parseInt(rowsField.getText());
            int cols = Integer.parseInt(colsField.getText());

            // Validate input
            if (rows <= 0 || cols <= 0) {
                JOptionPane.showMessageDialog(this, "Enter positive numbers!");
                return;
            }

            output.setText("");

            // Create seat labels (A1, A2, etc.)
            for (int r = 0; r < rows; r++) {
                char letter = (char) ('A' + r);

                for (int c = 1; c <= cols; c++) {
                    output.append(letter + "" + c + " ");
                }
                output.append("\n");
            }

        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(this, "Invalid input! Enter numbers only.");
        }
    }
}