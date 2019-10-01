class MyStringBuilder1 {
    private char[] value;
    private int count;

    public MyStringBuilder1(String s) {
        value = new char[16 + s.length()];
        System.arraycopy(s.toCharArray(), 0, value, 0, s.length());
        count = s.length();
    }

    public MyStringBuilder1 append(MyStringBuilder1 s) {
        if (s == null)
            return this;
        else {
            if (count + s.count > value.length) {
                char[] temp = new char[(value.length + 1) * 2];
                System.arraycopy(value, 0, temp, 0, count);
                value = temp;
            }
            System.arraycopy(s.value, 0, value, count, s.count);
            count += s.count;
            return this;
        }
    }

    public MyStringBuilder1 append(int i) {
        return this.append(new MyStringBuilder1(new Integer(i).toString()));
    }

    public int length() {
        return count;
    }

    public char charAt(int index) {
        if (value == null || index < 0 || index > value.length)
            return '\0';
        else
            return value[index];
    }

    public MyStringBuilder1 toLowerCase() {
        char[] temp = new char[value.length];
        for (int i = 0; i < count; i++) {
            temp[i] = Character.toLowerCase(value[i]);
        }
        return new MyStringBuilder1(String.valueOf(temp));
    }

    public MyStringBuilder1 substring(int begin, int end) {
        if (!(value == null || begin > end || begin < 0 || end > count)) {
            char[] temp = new char[end - begin];
            System.arraycopy(value, begin, temp, 0, end - begin);
            return new MyStringBuilder1(String.valueOf(temp));
        } else
            return new MyStringBuilder1(null);
    }

    public String toString() {
        return String.valueOf(value);
    }
}

public class Lab7_4 {
    public static void main(String[] args) {
        MyStringBuilder1 A = new MyStringBuilder1("World ");
        MyStringBuilder1 B = new MyStringBuilder1("Strat Up Timer Out");
        MyStringBuilder1 C = A.append(B);
        A.append(1);
        System.out.println(C.length());
        System.out.println(C.toString());
        System.out.println(B.charAt(4));
        B = B.toLowerCase();
        System.out.println(B.toString());
        A = A.substring(0, 2);
        System.out.println(A.toString());

    }

}