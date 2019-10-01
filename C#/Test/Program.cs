using System;
using System.Linq;
namespace Test
{
    public class Program
    {
        public static void Main(string[] args)
        {
            LinkedList b = new LinkedList();
            b.addFirst(15);
		    b.addFirst(30.2);
		    b.insert("Hello World", 1);
            for (int i = 0; i < b.getSize(); i++)
			    Console.WriteLine(b.getObject(i));
		    if (b.find("Hello World"))
			    Console.WriteLine("Oh");
        }
        public static int indexOf(string word,string pattern)
        {
            int Re=-1;
            for(int i=0,j=0;i<word.Length;i++)
            {
                if(word[i]==pattern[j]) j++;
                else j=0;
                if(j==pattern.Length)  Re=i-pattern.Length+1;
            }
            return Re;
        }
    }
    public class Node {
		public Node() {
		}

		public Node(Object input) {
			data = input;
		}
        public Object data;
		public Node next = null;
	}

    public class LinkedList {
	public LinkedList() {
	}

	public LinkedList(Node node) {
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
	public bool find(Object obj) {
		Node T = new Node();
		T = this.node;
		bool re = false;
		while (T != null) {
			if (T.data.Equals(obj)) {
				re = true;
				break;
			}
			T = T.next;
		}
		return re;
	}

	public void addFirst(Object obj) {
		insert(obj, 0);
	}

	public bool removeFrist() {
		return erase(0);
	}

	public void addLast(Object obj) {
		insert(obj, size);
	}

	public bool removeLast() {
		return erase(size - 1);
	}

	public bool insert(Object obj, int index) {
		Node NodeinLinked = new Node(obj);
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

	public bool erase(int index) {
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

	
}
}
