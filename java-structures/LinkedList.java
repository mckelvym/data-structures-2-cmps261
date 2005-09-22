class LinkedList{
	private Node head;
	
	// null list
	LinkedList(){
		head = null;
	}
	
	// one node list
	LinkedList(Object data){
		head = new Node(data);
	}
	
	// multi node list
	LinkedList(Object[] data){
		Node current;
		
		if(data[0] != null){
			head = new Node(data[0]);
			current = head;
			for(int i = 1; i < data.length; i++){
				current.link = new Node(data[i]);
				current = current.link;	
			}
		}	
	}
	
	// copy a list
	LinkedList(LinkedList another){
		Node c1, c2;
		if(another.head != null){
			head = new Node(another.head.data);
			c1 = head;
			c2 = another.head.link;
			while(c2 != null){
				c1.link = new Node(c2.data);
				c1 = c1.link;
				c2 = c2.link;	
			}			
		}		
	}
	
	// adds to the back
	void add(Object data){
		Node temp = new Node(data);
		Node current = head;
		
		if(head == null)
			head = temp;
		else{
			while(current.link != null){
				current = current.link;
			}
			current.link = temp;
		}
	}
	
	// add to a specific position
	void add(int index, Object data){
		Node temp = new Node(data);
		Node current = head;
		
		if((index < 0) || (index >= size())){
			return;
		}
		else{
			for(int i = 0; i < (index - 1); i++){
				current = current.link;
			}
			temp.link = current.link;
			current.link = temp;
		}
	}
	
	void addAll(LinkedList another){
		Node current;
		if(head == null){
 			if(another.head != null){
 				Node c1, c2;
 				head = new Node(another.head.data);
 				c1 = head;
 				c2 = another.head.link;
 				while(c2 != null){
 					c1.link = new Node(c2.data);
 					c1 = c1.link;
 					c2 = c2.link;
 				}	
 			} 			
		}
		else{
			Node c1, c2;
			current = head;
			while(current.link != null){
				current = current.link;
			}
			c1 = current;
			c2 = another.head.link;
			while(c2 != null){
				c1.link = new Node(c2.data);
				c1 = c1.link;
				c2 = c2.link;
			}			
		}
	}
	
	// not implemented
	void addAll(int index, LinkedList another){
		addAll(another);
	}
	
	void addFirst(Object data){
		Node temp = new Node(data);
		temp.link = head;
		head = temp;
	}
	
	void addLast(Object data){
		Node temp = new Node(data);
		Node current = head;
		
		if(head == null){
			head = temp;
		}
		else{
			while(current.link != null){
				current = current.link;
			}
			current.link = temp;
		}	
	}
	
	void clear(){
		head = null;
	}
	
	
	LinkedList cloneShallow(){
		return this;
	}
	
	LinkedList cloneDeep(){
		return new LinkedList(this);
	}
	
	boolean contains(Object item){
		boolean found = false;
		Node current = head;
		while(current != null){
			if(current.data.equals(item))
				found = true;
		}
		return found;
	}
	
	// Retrieves, but does not remove, the head (first element) of this list.
	Object head(){
		if(head == null)
			return false;
		else return (head.data);
	}
	
	Object get(int index){
		Node current = head;
		
		if((index < 0) || (index >= size())){
			return null;
		}
		else{
			for(int i = 0; i < index; i++){
				current = current.link;
			}
			return (current.data);
		}
	}
	
	Object getFirst(){
		return head();
	}
	
	Object getLast(){
		Node current = head;
		
		if(current == null)
			return null;
		else{
			while(current.link != null){
				current = current.link;
			}
			return (current.data);
		}
	}
	
	int indexOf(Object data){
		int count = 0;
		Node current = head;
		if(head == null)
			return -1;
		else if(head.data.equals(data))
			return 0;
		else{
			while(current != null){
				if(current.data.equals(data))
					return count;
				current = current.link;
				count++;
			}
			return -1;
		}
	}
	
	// not implemented
	int lastIndexOf(Object data){
		return indexOf();
	}
	
	boolean offer(Object data){
		addLast(data);
		return true;
	}
	
	Object peek(){
		return head();
	}
	
	Object poll(){
		Node temp = head;
		
		if(head == null)
			return null;
		else{
			head = head.link;
			return temp;
		}
	}
	
	Object remove(){
		return poll();
	}
	
	Object remove(int index){
		
	}
	////////////
	Object remove(Object data){
		Node current = head;
		if(head != null){
			if(head.data.equals(data)){
				head = head.link;
				return current.data;
			}
			else{
				if()
			}
		}
	}
	
	int size(){
		int size = 0;
		Node current = head;
		while(current != null){
			size++;
			current = current.link;
		}
		return size;
	}
	
	// print all data to std output
	void printAll(){
		Node current = head;
		
		while(current != null){
			print(current.data);
			current = current.link;	
		}
	}	
		
	void print(Object info){
		System.out.print(info + " ");
	}
	
	void println(Object info){
		System.out.println(info);
	}
	
	private class Node{
		Object data;
		Node link;
		
		Node(Object data){
			this.data = data;
			link = null;
		}		
	}
}