import java.util.Scanner;

/**
 * JavaTestExpection
 */
public class JavaTestExpection {
    public static void main(String[] args) {
        try {
            test01();
        } catch (Exception e) {
            System.err.println(e);
        }
    }

    public static void test01() throws Exception {
        try {
            Scanner sysin = new Scanner(System.in);
            sysin.nextInt();
            sysin.close();
        } catch (ArithmeticException e) {

        } catch (Exception e) {
            throw e;
        } finally {
            System.out.println("Finally is working");
        }
        System.out.println("After is working");
    }
}