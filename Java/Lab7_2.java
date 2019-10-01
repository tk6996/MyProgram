class Queue {
    private int[] elements;
    private int size = 0;

    public Queue() {
        elements = new int[8];
    }

    public void enqueue(int v) {
        if (size == elements.length) {
            int[] temp = new int[elements.length * 2];
            System.arraycopy(elements, 0, temp, 0, elements.length);
            elements = temp;
        }
        elements[size++] = v;
    }

    public int dequeue() {
        int re = elements[0];
        int i;
        for (i = 0; i < size - 1; i++) {
            elements[i] = elements[i + 1];
        }
        elements[i] = 0;
        if (size > 0)
            size--;
        return re;
    }

    public boolean empty() {
        if (size > 0)
            return false;
        else
            return true;
    }

    public int getSize() {
        return size;
    }
}

public class Lab7_2 {
    public static void main(String[] args) {
        int[] A = new int[20];
        Queue B = new Queue();
        for (int i = 0; i < 20; i++) {
            A[i] = i + 1;
        }
        for (int var : A) {
            B.enqueue(var);
        }
        while (!B.empty()) {
            System.out.print(B.dequeue() + " ");
        }
    }
}