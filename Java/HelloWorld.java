import java.io.Console;

public class HelloWorld {
    public static void main(String[] args) {
        Console con = System.console();
        con.printf("Hello");
        long Time, hour, min, sec, second, GMT = 7;
        while (true) {
            Time = System.currentTimeMillis();
            second = Time / 1000;
            sec = second % 60;
            min = (second / 60) % 60;
            hour = (second / 3600) % 24 + GMT;
            System.out.println(hour + ":" + min + ":" + sec + " GMT + " + GMT);
        }
    }
}