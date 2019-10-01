import java.util.Scanner;

class Location {
    public int row, column;
    public double maxValue;

    public static Location locateLargest(double[][] a) {
        Location p = new Location();
        p.column = 0;
        p.row = 0;
        p.maxValue = Double.NEGATIVE_INFINITY;
        for (int r = 0; r < a.length; r++) {
            for (int c = 0; c < a[r].length; c++) {
                if (p.maxValue < a[r][c]) {
                    p.column = c;
                    p.row = r;
                    p.maxValue = a[r][c];
                }
            }
        }
        return p;
    }
}

public class Lab6_3 {
    public static void main(String[] args) {
        System.out.print("Enter the number of rows and columns in the array : ");
        Scanner sysin = new Scanner(System.in);
        int Row = sysin.nextInt();
        int Col = sysin.nextInt();
        double[][] array = new double[Row][Col];
        System.out.println("Enter the array :");
        for (int i = 0; i < Row; i++) {
            for (int j = 0; j < Col; j++) {
                array[i][j] = sysin.nextDouble();
            }
        }
        Location Max = Location.locateLargest(array);
        System.out.println(
                "The location of the largest element is " + Max.maxValue + " at (" + Max.row + ", " + Max.column + ")");
        sysin.close();
    }
}