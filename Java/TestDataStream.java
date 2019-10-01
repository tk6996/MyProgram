import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

public class TestDataStream {
    public static void main(String[] args) throws FileNotFoundException, IOException {
        demo2();
    }

    public static void demo1() throws FileNotFoundException, IOException {
        File file = new File("TestDataStream.dat");
        FileOutputStream fos = new FileOutputStream(file);
        DataOutputStream output = new DataOutputStream(fos);
        output.writeInt(125);
        output.writeByte(2500);
        output.close();
        fos.close();
        FileInputStream fis = new FileInputStream(file);
        DataInputStream input = new DataInputStream(fis);
        System.out.println(input.readInt());
        System.out.println(input.readByte());
        input.close();
        fis.close();
    }

    public static void demo2() throws FileNotFoundException, IOException {
        File file = new File("TestBufferStream.dat");
        BufferedOutputStream output = new BufferedOutputStream(new FileOutputStream(file));
        output.write(127);
        output.close();
        BufferedInputStream input = new BufferedInputStream(new FileInputStream(file));
        System.out.println(input.read());
        input.close();
    }
}