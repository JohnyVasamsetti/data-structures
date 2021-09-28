class Node{
	int data;
	Node next;
	Node prev;
	Node(int data){
		this.data = data;
		this.next = null;
		this.prev = null;
	}
}
public class DoubleLinkedList{
	public Node head;
	void InsertBegin(int data){
		Node temp = new Node(data);
		if (head == null){
			head = temp;
			return;
		}
		head.prev = temp;
		temp.next = head;
		head = temp;
	}

	void InsertEnd(int data){
		Node temp = new Node(data);
		if (head == null){
			head = temp;
			return;
		}
		Node trav = head;
		while(trav.next != null){
			trav = trav.next;
		}
		temp.prev = trav;
		trav.next = temp;
	}

	void InsertPosition(int data,int position){
		Node temp = new Node(data);
		if (head == null){
			head = temp;
			return;
		}
		if (position == 1){
			temp.next = head;
			head = temp;
			return;
		}
		Node trav = head;
		int i = 2;
		while(trav.next != null && i < position){
			trav = trav.next;
			i++;
		}
		temp.prev = trav;
		temp.next = trav.next;
		trav.next = temp;
		if(temp.next != null)
			temp.next.prev = temp;
	}

	void DelBigin(){
		if (head == null){
			return;
		}
		head = head.next;
		head.prev = null;
	}

	void DelEnd(){
		if (head == null){
			return;
		}
		if (head.next == null){
			head = null;
		}
		Node trav = head;
		while(trav.next.next != null){
			trav = trav.next;
		}
		trav.next = null;
	}

	void DelPosition(int position){
		if (head == null){
			return;
		}
		if (position == 1){
			head= head.next ;
			return;
		}
		Node trav = head;
		int i = 2;
		while(trav.next != null && i < position){
			trav = trav.next;
			i++;
		}
		Node last = trav.next;
		trav.next = last.next;
		last.prev = trav;
		last.next = null;
	}
	void Reverse(){
		if (head == null){
			return;
		}
		Node prev = null;
		Node nextnode;
		Node current = head;
		while(current != null){
			nextnode = current.next;
			current.next = prev;
			prev = current;
			current = nextnode;
		}
		head = prev;
	}
	void Print(){
		Node temp = head;
		while (temp != null) {
			System.out.print(temp.data + " ");
			temp = temp.next;
		}
		System.out.println();
	}

	void sort(){
		if (head == null)
			return;
		Node temp = head;
	    while (temp != null) {
	    	this.printList();
	        Node min = temp; // ith element
	        Node curr = temp.next; // iterate i+1 to end
	        while(curr != null) {
	            if (min.data.compareTo(curr.data) > 0) // compare and update the min
	                min = curr;
	            curr = curr.next; // increment curr
	        }
	        if (temp == min){ // if both are same then no need to swap
	        	temp = temp.next;
	        	continue;
	        }
	        // if the consecutive need to swap
	        if(temp.next == min){
	        	Node next = min.next;
	        	if (temp.prev != null){ // if the temp is first then temp.prev is null
	        		temp.prev.next = min;
	        	}
	        	else{
	        		head = min;
	        	}
	        	min.prev = temp.prev;
	        	min.next = temp;
	        	temp.prev = min;
	        	temp.next = next;
	        	if (next != null) // if the min is last element then next is null
	        		next.prev = temp;

	        	temp = min;
	        }
	        // elements between the two swapping elements
	        else{
	        	// taking next and prev
	        	Node next = min.next;
	        	Node prev = min.prev;
	        	if (temp.prev != null){ // if the temp is first then temp.prev is null
	        		temp.prev.next = min;
	        	}
	        	else{
	        		head = min; // update first
	        	}
	        	min.prev = temp.prev;
	        	
	        	min.next = temp.next;
	        	temp.next.prev = min;

	        	temp.next = next;
	        	if (next != null) // if the min is last element then next is null
	        		next.prev = temp;
	        	prev.next = temp;
	        	temp.prev = prev;

	        	temp = min;
	        }
	        temp = temp.next;
	    }

	public static void main(String[] args) {
		DoubleLinkedList l = new DoubleLinkedList();
		l.InsertBegin(10);
		l.InsertBegin(20);
		l.InsertEnd(30);
		l.InsertPosition(40,2);
		l.InsertBegin(11);
		l.InsertBegin(23);
		l.InsertBegin(13);
		l.InsertEnd(111);
		l.InsertEnd(333);
		l.Print();
		l.DelBigin();
		l.DelEnd();
		l.DelPosition(1);
		l.DelPosition(4);
		l.Print();
		l.Reverse();
		l.Print();

	}
}