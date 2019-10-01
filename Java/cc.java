
public class cc {
    public static void main(String[] args) {
        int a=2,b=3;
        Integer A = new Integer(a);
        Integer B = new Integer(b);
        System.out.println("Primtive Type "+ a + b);
        System.out.println("Wrapper Type " + A + B);
        System.out.println("Integer Phase " + Integer.parseInt("2") + Integer.parseInt("3"));
        for (int i=0 ; i<100 ;i++) {
            System.out.println(i+" ");
        }
    }
}