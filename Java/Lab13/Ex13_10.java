
public class Ex13_10 {
    public static void main(String[] args) {
        Rectangle foo = new Rectangle(0.00005, 0.0007);
        System.out.println(foo.equals(new Rectangle(0.000000035, 1.0)));
        Rectangle[] lArrayList = new Rectangle[3];
        lArrayList[0] = new Rectangle(0.045455, 0.454507);
        lArrayList[1] = new Rectangle(0.0778, 0.07);
        lArrayList[2] = new Rectangle(55.5, 0.47);
        java.util.Arrays.sort(lArrayList);
        for (Rectangle itr : lArrayList) {
            System.out
                    .println("width = " + itr.getWidth() + " height = " + itr.getHeight() + " Area = " + itr.getArea());
        }
    }
}