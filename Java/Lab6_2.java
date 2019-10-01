
public class Lab6_2 {
    public static void main(String[] args) {
        int[] num = new int[100000];
        for (int i = 0; i < 100000; i++) {
            num[i] = (int) (Math.random() * Integer.MAX_VALUE);
        }
        Stopwatch watch = new Stopwatch();
        sectionSort(num);
        watch.stop();
        System.out.println(watch.getElapsedTime());
    }

    public static void sectionSort(int[] num) {
        for (int i = 0; i < num.length; i++) {
            int temp = i;
            for (int j = i + 1; j < num.length; j++) {
                if (num[temp] > num[j])
                    temp = j;
            }
            int t = num[temp];
            num[temp] = num[i];
            num[i] = t;
        }
    }
}

class Stopwatch {
    private long startTime, endTime;

    Stopwatch() {
        start();
    }

    void start() {
        startTime = System.currentTimeMillis();
    }

    void stop() {
        endTime = System.currentTimeMillis();
    }

    long getElapsedTime() {
        return endTime - startTime;
    }
}