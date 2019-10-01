
public class Compute {
    public static void main(String[] args) {
        System.out.print("Result of " + args[0] + " " + args[1] + " " + args[2] + " is ");
        float A = Float.parseFloat(args[0]);
        float B = Float.parseFloat(args[2]);
        switch (args[1]) {
        case "+": {
            System.out.println((int) (A + B));
            break;
        }
        case "-": {
            System.out.println((int) (A - B));
            break;
        }
        case "*": {
            System.out.println((int) (A * B));
            break;
        }
        case "/": {
            System.out.println(A / B);
            break;
        }
        default:
            break;
        }
    }
}