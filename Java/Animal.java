import java.io.PrintWriter;

public class Animal {
    public static void main(String[] args) {
        /*
         * java.util.Scanner A = new java.util.Scanner(System.in); String b = new
         * String(A.next()); Integer c = Integer.parseInt(b);
         */

        Dog d = new Dog();
        Cat a = new Cat();
        try {
            Cat ea = (Cat) a.clone();
            Dog ee = (Dog) d.clone();
            System.out.println("L");
        } catch (CloneNotSupportedException e) {
            System.err.println(e);
        }
        d.print();
        System.out.println(d);
        /*
         * try { PrintWriter p = new
         * PrintWriter("C:\\Users\\Administrator\\Desktop\\program\\Hello.txt"); for
         * (int i = 1; i <= 300; i++) p.println(i + "."); p.close(); } catch (Exception
         * e) { System.err.println(e); }
         */
    }

}

abstract class Life {
    int val = 0;

    protected Life() {
    }

    public Object clone() throws CloneNotSupportedException {
        return super.clone();
    }

    abstract void print();
}

class Dog extends Life {
    int val = -4;

    @Override
    void print() {
        val = val >> 1;
        System.out.println(val);

    }
}

class Cat extends Life implements Cloneable {
    @Override
    void print() {
        System.out.println("I am Cat");
    }
}

interface aa {
    void l(int b);
}

interface bb {

}