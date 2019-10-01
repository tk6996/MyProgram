
public class TestFileStream {
    public static void main(String[] args) throws java.io.FileNotFoundException, java.io.IOException {
        // demo1();
        demo2();
    }

    public static void demo1() throws java.io.FileNotFoundException, java.io.IOException {
        java.io.File file = new java.io.File("TestTxtStream.txt");
        try (java.io.PrintWriter output = new java.io.PrintWriter(file)) {
            output.write("Hello");
            output.println();
            output.write("Java");
            // output.append("Good Afternoon");
        }
        try (java.io.FileWriter fw = new java.io.FileWriter(file, true)) {
            try (java.io.PrintWriter output2 = new java.io.PrintWriter(fw)) {
                output2.println();
                output2.write("Good Afternoon");
            }
        }
    }

    private static void demo2() throws java.io.FileNotFoundException {
        java.io.File file = new java.io.File("TestBinary.dat");
        java.io.FileOutputStream output = new java.io.FileOutputStream(file);
        try {
            output.write(125);
            output.flush();
            output.write('A');
            output.write(new byte[] { 1, 2, 3 });
            output.close();
        } catch (java.io.IOException e) {
            System.err.println(e);
        }
        try {
            java.io.FileInputStream input = new java.io.FileInputStream("TestBinary.dat");
            System.out.println(input.read());
            System.out.println((char) input.read());
            byte[] b = new byte[3];
            input.read(b);
            for (byte v : b) {
                System.out.println(v);
            }
            input.close();
        } catch (java.io.IOException e) {
            System.err.println(e);
        }
    }
}