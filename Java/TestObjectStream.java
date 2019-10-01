import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;

public class TestObjectStream {
    public static void main(String[] args) throws FileNotFoundException, IOException, ClassNotFoundException {
        demo1();
    }

    public static void demo1() throws FileNotFoundException, IOException, ClassNotFoundException {
        File file = new File("TestObjectStream.dat");
        try (ObjectOutputStream output = new ObjectOutputStream(new FileOutputStream(file))) {
            output.writeObject(new Circle());
            output.writeObject(new Circle(2.0));
        }
        try (ObjectInputStream input = new ObjectInputStream(new FileInputStream(file))) {
            Circle c2 = (Circle) input.readObject();
            System.out.println(c2.toString());
            System.out.println((Circle) input.readObject());
        }
    }
}

class Circle implements Serializable {
    private double radius;
    private static int numberOfObject;

    private transient B b = new B();

    Circle() {
        this(5.5);
    }

    Circle(double radius) {
        this.radius = radius;
        ++numberOfObject;
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    @Override
    public String toString() {
        return "Circle { radius = " + radius + " , numberOfObject = " + numberOfObject + " }";
    }
}

class B {
}