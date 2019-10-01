
import java.util.Scanner;

public class Pactice {
    public static void main(String[] args) {
        int a = 3, b = 5;
        a = swap(b, b = a, b - a);
        System.out.println(a + " " + b);

    }

    public static int swap(int x, int y, int z) {
        return x + z;
    }
}