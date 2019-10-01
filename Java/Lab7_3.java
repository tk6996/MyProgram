
class Mystring1 {
    private char[] value;

    public Mystring1(char[] chars) {
        if (chars != null) {
            value = new char[chars.length];
            System.arraycopy(chars, 0, value, 0, chars.length);
        }
    }

    public char charAt(int index) {
        if (value != null && index > 0 && index < value.length)
            return value[index];
        else
            return '\0';
    }

    public int length() {
        return (value != null) ? value.length : 0;
    }

    public Mystring1 substring(int begin, int end) {
        if (value == null || begin >= end || begin < 0 || end > value.length) {
            return new Mystring1(null);
        } else {
            char[] temp = new char[end - begin];
            System.arraycopy(value, begin, temp, 0, end - begin);
            return new Mystring1(temp);
        }
    }

    public Mystring1 toLowerCase() {
        if (value == null)
            return new Mystring1(null);
        char temp[] = new char[value.length];
        for (int i = 0; i < value.length; i++) {
            temp[i] = Character.toLowerCase(value[i]);
        }
        return new Mystring1(temp);
    }

    public boolean equals(Mystring1 mystr) {
        if (mystr == null)
            return false;
        else if (mystr.value == null && value == mystr.value)
            return true;
        else {
            if (value == null || value.length != mystr.value.length)
                return false;
            else {
                for (int i = 0; i < mystr.value.length; i++) {
                    if (value[i] != mystr.value[i])
                        return false;
                }
                return true;
            }
        }
    }

    public static Mystring1 valueOf(int i) {

        if (i == 0) {
            return new Mystring1(new char[] { '0' });
        }
        int temp = Math.abs(i);
        int size = 0;
        if (i < 0)
            size++;
        while (temp > 0) {
            temp /= 10;
            size++;
        }
        temp = Math.abs(i);
        char str[] = new char[size];
        while (temp > 0) {
            str[--size] = (char) ('0' + (temp % 10));
            temp /= 10;
        }
        if (--size == 0)
            str[0] = '-';
        return new Mystring1(str);

    }

    public String toString() {
        return String.valueOf(value);
    }
}

public class Lab7_3 {
    public static void main(String[] args) {
        Mystring1 A = new Mystring1(new char[] { 'A', '7', 'C', 'D', 'E' });
        Mystring1 Message = new Mystring1(null);
        Mystring1 B = A.substring(2, 4);
        Mystring1 C = A.toLowerCase();
        System.out.println("Hello".toString());
        System.out.println(A.equals(new Mystring1(new char[] { 'A', '7', 'C', 'D', 'E' })));
        Mystring1 D = Mystring1.valueOf(0);
        Mystring1 E = Mystring1.valueOf(10465000);
        Mystring1 F = Mystring1.valueOf(-454551);
        Mystring1 G = Mystring1.valueOf(5);
        System.out.println("\n" + B + "\n" + C + "\n" + D + "\n" + E + "\n" + F + "\n" + G + "\n");
    }
}