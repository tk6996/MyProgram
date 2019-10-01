
public class CreateData {
    public static String GenerateData(int index) {

        Member[] Data = { new Member("assistant", 50000D, 80000D), new Member("associate", 60000D, 110000D),
                new Member("full", 75000D, 130000D) };
        int Rank = (int) (Math.random() * 3);
        return "FirstName" + index + " LastName" + index + " " + Data[Rank].getRank() + " "
                + String.format("%.2f", (Data[Rank].getMin_salary()
                        + Math.random() * (Data[Rank].getMax_salary() - Data[Rank].getMin_salary())));
    }

    public static void main(String[] args) {
        try {
            java.io.File file = new java.io.File("Salary.txt");
            java.io.PrintWriter output = new java.io.PrintWriter(file);
            for (int i = 1; i <= 1000; i++) {
                output.print(GenerateData(i));
                if (i != 1000)
                    output.print("\n");
            }
            output.close();
        } catch (java.io.FileNotFoundException e) {
            System.err.println(e);
        }
    }
}

class Member {
    private String rank;
    private double min_salary;
    private double max_salary;

    Member(String rank, double min_salary, double max_salary) {
        this.rank = rank;
        this.min_salary = min_salary;
        this.max_salary = max_salary;
    }

    public String getRank() {
        return rank;
    }

    public void setRank(String rank) {
        this.rank = rank;
    }

    public double getMin_salary() {
        return min_salary;
    }

    public void setMin_salary(double min_salary) {
        this.min_salary = min_salary;
    }

    public double getMax_salary() {
        return max_salary;
    }

    public void setMax_salary(double max_salary) {
        this.max_salary = max_salary;
    }
}