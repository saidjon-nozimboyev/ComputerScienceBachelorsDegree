class Box {
    int w, h;

    Box() {
        System.out.println("default");
        this(1, 1);    
    }

    Box(int w, int h) {
        this.w = w;
        this.h = h;
        System.out.println("param");
    }
}

public class Main {
    public static void main(String[] args) {
        Box b = new Box();
        System.out.println(b.w + " " + b.h);
    }
}
