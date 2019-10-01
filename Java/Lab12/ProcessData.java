
public class ProcessData {
    public static void main(String[] args) {
        try {
            process(new java.io.File("Salary.txt"));
        } catch (java.io.FileNotFoundException e) {
            System.err.println(e);
        }
    }

    public static void process(java.io.File file) throws java.io.FileNotFoundException {
        java.util.Scanner input = new java.util.Scanner(file);
        double[] salary_sum = new double[3];
        int[] Times = new int[3];
        while (input.hasNextLine()) {
            java.util.Scanner readline = new java.util.Scanner(input.nextLine());
            readline.next();
            readline.next();
            switch (readline.next()) {
            case "assistant":
                salary_sum[0] += readline.nextDouble();
                Times[0]++;
                break;
            case "associate":
                salary_sum[1] += readline.nextDouble();
                Times[1]++;
                break;
            case "full":
                salary_sum[2] += readline.nextDouble();
                Times[2]++;
                break;
            default:
                break;
            }
            readline.close();
        }
        input.close();
        System.out.println("Total salary for assistant professor is " + String.format("%,.2f", salary_sum[0]));
        System.out.println("Total salary for associate professor is " + String.format("%,.2f", salary_sum[1]));
        System.out.println("Total salary for full professor is " + String.format("%,.2f", salary_sum[2]));
        System.out.println("Total salary for all professor is "
                + String.format("%,.2f", salary_sum[0] + salary_sum[1] + salary_sum[2]));
        System.out.println(
                "Average salary for assistant professor is " + String.format("%,.2f", salary_sum[0] / Times[0]));
        System.out.println(
                "Average salary for associate professor is " + String.format("%,.2f", salary_sum[1] / Times[1]));
        System.out.println("Average salary for full professor is " + String.format("%,.2f", salary_sum[2] / Times[2]));
        System.out.println("Average salary for all professor is " + String.format("%,.2f",
                (salary_sum[0] + salary_sum[1] + salary_sum[2]) / (Times[0] + Times[1] + Times[2])));
    }
}