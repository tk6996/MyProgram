
class Time {
    private int hour;
    private int minute;
    private int second;

    Time() {
        setTime(System.currentTimeMillis());
    }

    Time(int hour, int minute, int second) {
        this.hour = hour;
        this.minute = minute;
        this.second = second;
    }

    Time(long elapseTime) {
        setTime(elapseTime);
    }

    public int getHour() {
        return hour;
    }

    public int getMinute() {
        return minute;
    }

    public int getSecond() {
        return second;
    }

    public void setTime(long elapseTime) {
        second = (int) (elapseTime / 1000) % 60;
        minute = ((int) (elapseTime / 1000) / 60) % 60;
        hour = (((int) (elapseTime / 1000) / 60) / 60) % 24;
    }
}

public class Lab7_1 {
    public static void main(String[] args) {
        Time A = new Time();
        Time B = new Time(555550000);
        System.out.printf("%d:%d:%d\n", A.getHour(), A.getMinute(), A.getSecond());
        System.out.printf("%d:%d:%d", B.getHour(), B.getMinute(), B.getSecond());
    }
}