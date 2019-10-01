import java.util.*;

public class Test_Link {
	public static void main(String[] args) {
		Scanner sysin = new Scanner(System.in);
		LinkedList b = new LinkedList();
		b.addFirst(15);
		b.addFirst(30.2);
		b.insert("Hello World", 1);
		/*
		 * for (int index = 0; index < 10; index++) { Node in = new Node((int)
		 * (Math.random() * Short.MAX_VALUE)); b.addFirst(in);
		 * System.out.println(in.data); }
		 * System.out.println("----------------------------------"); for (int index = 0;
		 * index < b.getSize(); index++) {
		 * System.out.println(b.getObjectLinkedAt(index).data); }
		 */
		for (int i = 0; i < b.getSize(); i++)
			System.out.println(b.getObject(i));
		if (b.find("Hello World"))
			System.out.println("Oh");
		sysin.close();
	}
}

class LinkedList {
	LinkedList() {
	}

	LinkedList(Node node) {
		this.node = node;
		size++;
	}

	private Node node = null;
	private int size = 0;

	public int getSize() {
		return size;
	}

	public Node getNodeAt(int index) {
		Node t = this.node;
		if (index >= size)
			return null;
		else {
			while (index != 0) {
				t = t.next;
				index--;
			}
			return t;
		}
	}

	public Object getObject(int index) {
		Node t = this.node;
		if (index >= size)
			return null;
		else {
			while (index != 0) {
				t = t.next;
				index--;
			}
			return t.data;
		}
	}

	public boolean find(Object object) {
		Node T = new Node();
		T = this.node;
		boolean re = false;
		while (T != null) {
			if (T.data.equals(object)) {
				re = true;
				break;
			}
			T = T.next;
		}
		return re;
	}

	public void addFirst(Object object) {
		insert(object, 0);
	}

	public boolean removeFrist() {
		return erase(0);
	}

	public void addLast(Object object) {
		insert(object, size);
	}

	public boolean removeLast() {
		return erase(size - 1);
	}

	public boolean insert(Object object, int index) {
		Node NodeinLinked = new Node(object);
		if (index == 0) {
			Node t = NodeinLinked;
			t.next = this.node;
			this.node = t;
			size++;
			return false;
		} else {
			Node t = this.node;
			Node p = null;
			if (index > size)
				return true;
			else {
				while (index != 0) {
					p = t;
					t = t.next;
					index--;
				}
				NodeinLinked.next = t;
				p.next = NodeinLinked;
				size++;
				return false;
			}
		}
	}

	public boolean erase(int index) {
		if (index < size) {
			if (index == 0) {
				this.node = this.node.next;
				size--;
				return false;
			} else {
				Node t = this.node;
				Node p = null;
				while (index != 0) {
					p = t;
					t = t.next;
					index--;
				}
				p.next = t.next;
				size--;
				return false;
			}
		} else
			return true;
	}

	class Node {
		Node() {
		}

		Node(Object input) {
			data = input;
		}

		private Object data;
		private Node next = null;
	}
}