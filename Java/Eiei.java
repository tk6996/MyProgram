import java.io.*;

public class Eiei {
    public static void main(String args[]) {
        String[][] table = {{"1","1","1"},{"1","1","1"},{"1","1","1"}};
        try (FileWriter fw = new FileWriter(new File("C:/out/Temp.csv"))) {
                for(var i : table)
                {
                    for(var j : i)
                    {
                        fw.append(j);
                        fw.append(",");
                    }
                    fw.append("\n");
                }
        } catch (Exception e) {
                e.printStackTrace();
        }
    }
}