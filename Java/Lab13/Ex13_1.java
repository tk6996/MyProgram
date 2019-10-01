public class Ex13_1 {
    public static void main(String[] args) {
        java.util.Scanner sysin = new java.util.Scanner(System.in);
        System.out.print("Enter Side 1 : ");
        double side1 = sysin.nextDouble();
        System.out.print("Enter Side 2 : ");
        double side2 = sysin.nextDouble();
        System.out.print("Enter Side 3 : ");
        double side3 = sysin.nextDouble();
        Triangle triangle = new Triangle(side1, side2, side3);
        System.out.print("Enter Color  : ");
        triangle.setColor(sysin.next());
        System.out.print("Enter Fill   : ");
        triangle.setFilled(sysin.nextBoolean());
        System.out.println("Area         is " + triangle.getArea());
        System.out.println("Perimeter    is " + triangle.getPerimeter());
        System.out.println("Color        is " + triangle.getColor());
        System.out.println("Filled       is " + triangle.isFilled());
        sysin.close();
    }
}