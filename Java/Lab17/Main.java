import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.EOFException;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

public class Main {
    public static void main(String[] args) {
        Person[] Account = { new Person("Steve", "San Francisco", "0824569714", "steve@kmitl.ac.th"),
                new Student("Watcharin", "Thailand", "0814295276", "61010960@kmitl.ac.th", Student.FRESHMAN),
                new Employee("Siri", "New York", "0811087951", "siri@kmitl.ac.th", "KMITL", 20000),
                new Faculty("Somsak", "Thailand", "0273924002", "kwsomsak@kmitl.ac.th", "KMITL", 60000, "9:00",
                        Faculty.ASSISTANT_PROFESSOR),
                new Staff("Primo", "Italy", "0976412580", "primo@kmitl.ac.th", "KMITL", 30000, "Hello") };
        try {
            TextIO(Account);
            // BinaryIO(Account);
        } catch (Exception e) {
            System.err.println(e);
        }
    }

    public static void TextIO(Person[] Account) throws IOException, FileNotFoundException {
        File file = new File("Text.txt");
        try (BufferedWriter bfw = new BufferedWriter(new FileWriter(file, false))) {
            for (Person var : Account) {
                bfw.write(var.toString());
                bfw.write("\n\n");
            }
        }
        try (BufferedReader bfr = new BufferedReader(new FileReader(file))) {
            while (bfr.ready()) {
                System.out.println(bfr.readLine());
            }
        }
    }

    public static void BinaryIO(Person[] Account) throws IOException, FileNotFoundException, ClassNotFoundException {
        File file = new File("Binary.dat");
        try (ObjectOutputStream os = new ObjectOutputStream(new FileOutputStream(file))) {
            for (Person var : Account) {
                os.writeObject(var);
            }
        }
        try (ObjectInputStream is = new ObjectInputStream(new FileInputStream(file))) {
            Object temp;
            while ((temp = is.readObject()) instanceof Person) {
                System.out.println(temp + "\n");
            }
        } catch (EOFException e) {
            return;
        }
    }
}