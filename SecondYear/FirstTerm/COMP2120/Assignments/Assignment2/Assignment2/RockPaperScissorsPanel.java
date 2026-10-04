import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.util.Random;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

// GUI for Rock Paper Scissors game
public class RockPaperScissorsPanel extends JFrame {

    private JLabel userLabel, computerLabel, resultLabel;
    private Random rand = new Random();

    public RockPaperScissorsPanel() {
        setTitle("Rock Paper Scissors");
        setSize(500, 300);
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        setLayout(new BorderLayout(10, 10));

        // Top panel to display results
        JPanel topPanel = new JPanel(new GridLayout(3, 1));

        userLabel = new JLabel("Your Choice: ", JLabel.CENTER);
        computerLabel = new JLabel("Computer Choice: ", JLabel.CENTER);
        resultLabel = new JLabel("Result: ", JLabel.CENTER);

        topPanel.add(userLabel);
        topPanel.add(computerLabel);
        topPanel.add(resultLabel);

        add(topPanel, BorderLayout.NORTH);

        // Buttons panel
        JPanel buttonPanel = new JPanel(new GridLayout(1, 3, 10, 10));

        JButton rockBtn = new JButton("Rock");
        JButton paperBtn = new JButton("Paper");
        JButton scissorsBtn = new JButton("Scissors");

        buttonPanel.add(rockBtn);
        buttonPanel.add(paperBtn);
        buttonPanel.add(scissorsBtn);

        add(buttonPanel, BorderLayout.CENTER);

        // Button actions
        rockBtn.addActionListener(e -> play("rock"));
        paperBtn.addActionListener(e -> play("paper"));
        scissorsBtn.addActionListener(e -> play("scissors"));

        setVisible(true);
    }

    // Game logic
    private void play(String user) {
        String[] options = {"rock", "paper", "scissors"};
        String computer = options[rand.nextInt(3)];

        String result;

        if (user.equals(computer)) {
            result = "Tie!";
        } else if (
                (user.equals("rock") && computer.equals("scissors")) ||
                (user.equals("paper") && computer.equals("rock")) ||
                (user.equals("scissors") && computer.equals("paper"))
        ) {
            result = "You Win!";
        } else {
            result = "Computer Wins!";
        }

        // Update labels
        userLabel.setText("Your Choice: " + user);
        computerLabel.setText("Computer Choice: " + computer);
        resultLabel.setText("Result: " + result);
    }
}