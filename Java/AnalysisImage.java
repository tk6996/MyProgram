import java.awt.image.BufferedImage;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

import javax.imageio.ImageIO;

public class AnalysisImage {

    public static int[][] imageToArray(BufferedImage img) {
        int[][] arr = new int[img.getHeight()][img.getWidth()];
        for (int y = 0; y < img.getHeight(); y++) {
            for (int x = 0; x < img.getWidth(); x++) {
                arr[y][x] = (img.getRGB(x, y) & 0xFF) < 64 ? 0 : 1;
            }
        }
        return arr;
    }

    public static char analysis(int[][] data /* coordinate [y][x] */) {
        // pixelAnalysis coordinate [x][y]
        int[][][] pixelAnalysis = { { {14,46}, {24,90}, {76,96} }, // triangle lower left
                { {50,13}, {97,22}, {101,70} }, // triangle upper left
                { {149,59}, {190,62}, {185,108} }, // upper right
                { {44,131}, {85,156}, {76,200} }, // lower left
                { {136,155}, {162,201}, {186,195} }, // triangle lower right
                { {155,130}, {223,136}, {203,177} } }; // triangle upper right
        int collectWhite = 0;
        // check error
        for (int i = 0; i < 18; i++) {
            if (data[pixelAnalysis[i / 3][i % 3][1]][pixelAnalysis[i / 3][i
                    % 3][0]] != data[pixelAnalysis[i / 3][i % 3][1]][pixelAnalysis[i / 3][i % 3][0] - 1]
                    && data[pixelAnalysis[i / 3][i % 3][1]][pixelAnalysis[i / 3][i
                            % 3][0]] != data[pixelAnalysis[i / 3][i % 3][1]][pixelAnalysis[i / 3][i % 3][0] + 1])
                return (char) -1;
        }
        for (int i = 0; i < pixelAnalysis.length; i++) {
            collectWhite |= ((data[pixelAnalysis[i][0][1]][pixelAnalysis[i][0][0]] * 2 - 1
                    + data[pixelAnalysis[i][1][1]][pixelAnalysis[i][1][0]] * 2 - 1
                    + data[pixelAnalysis[i][2][1]][pixelAnalysis[i][2][0]] * 2 - 1) > 0 ? 1 : 0) << i;
        }
        if (collectWhite == 0b000111)
            return 'T';
        else if (collectWhite == 0b111000)
            return 'B';
        else if (collectWhite == 0b001011)
            return 'L';
        else if (collectWhite == 0b110100)
            return 'R';
        else if (collectWhite == 0b100110)
            return 'U';
        else if (collectWhite == 0b011001)
            return 'D';
        else
            return (char) collectWhite;
    }

    public static void arrTocsv(int[][] data) throws IOException {
        try (FileWriter fw = new FileWriter(new File("C:/Users/Administrator/Desktop/testPic/DataLeft.csv"))) {
            for (int y = 0; y < data.length; y++) {
                for (int x = 0; x < data[y].length; x++) {
                    fw.write(data[y][x] > 0 ? "" : "#");
                    fw.append(',');
                }
                fw.append('\n');
            }
        }
    }

    public static void main(String[] args) throws Exception {
        int[][] data = imageToArray(ImageIO.read(new File("C:/Users/Administrator/Desktop/testPic/file13.bmp")));
        System.out.println(analysis(data));
    }
}