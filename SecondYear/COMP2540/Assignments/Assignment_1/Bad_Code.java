
import java.util.Map.Entry;
import java.util.Map.Entry;
import java.util.AbstractMap;
import java.util.LinkedList;

public class Bad_Code {

    public static void main(String[] args) {

    int size = 6400;
    String[] words = new String[size];

    for (int i = 0; i < size; i++) {
        words[i] = "word" + i;
    }

    long startTime = System.currentTimeMillis();

    Entry<String, Integer> result = CountTest.count_LINKED_LIST_BAD(words);

    long endTime = System.currentTimeMillis();

    System.out.println("Data size: " + size);
    System.out.println("Most frequent word: " + result.getKey());
    System.out.println("Frequency: " + result.getValue());
    System.out.println("Time taken: " + (endTime - startTime) + " ms");
}
}

class CountTest {

    public static Entry<String, Integer> count_LINKED_LIST_BAD(String[] tokens) {
    LinkedList<Entry<String, Integer>> list = new LinkedList<Entry<String, Integer>>();

    for (int j = 0; j < tokens.length; j++) {
        String word = tokens[j];
        boolean found = false;

        for (int i = 0; i < list.size(); i++) {
            Entry<String, Integer> e = list.get(i);

            if (word.equals(e.getKey())) {
                e.setValue(e.getValue() + 1);
                list.set(i, e);
                found = true;
                break;
            }
        }

        if (!found)
            list.add(new AbstractMap.SimpleEntry<String, Integer>(word, 1));
    }

    int maxCount = 0;
    String maxWord = "";

    for (int i = 0; i < list.size(); i++) {
        int count = list.get(i).getValue();

        if (count > maxCount) {
            maxWord = list.get(i).getKey();
            maxCount = count;
        }
    }

    return new AbstractMap.SimpleEntry<String, Integer>(maxWord, maxCount);
}
}
