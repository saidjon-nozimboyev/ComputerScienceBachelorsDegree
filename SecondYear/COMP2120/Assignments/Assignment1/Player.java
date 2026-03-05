public class Player 
{
    String name;
    int score;
    String[] summary;
    int index;

    public Player(String name, int maxQuestions) 
    {
        this.name = name;
        this.score = 0;
        this.summary = new String[maxQuestions];
        this.index = 0;
    }

    public void addSummary(String s) 
    {
        summary[index] = s;
        index++;
    }

    public void printSummary() 
    {
        System.out.println("Summary:");
        for (int i = 0; i < index; i++) {
            System.out.println(summary[i]);
        }
    }
}