
public class ShowErrors {
    public static void main(String[] args) {

    }
}

class C {
    private int p;

    public C() {
        System.out.println("C's no-arg constructor invoked");
        this(0);
    }

    public C(int p) {
        p = p;
    }

    public void setP(int p) {
        p = p;
    }

    public int getP() {
        return p;
    }
}

class Test {
    private int id;

    public void ml() {
        this.id = 45;
    }

    public void m2() {
        Test.id = 45;
    }
}