class Stack{
	private Node top;
	
	Stack(){
		top = null;
	}
	
	void push(Object data){
		Node temp = new Node(data);
		if(top == null)
			top = temp;
		else{
			temp.link = top;
			top = temp;
		}
	}
	
	Object pop(){
		Node temp = top;
		if(top != null){
			top = top.link;
		}
		return temp.data;
	}
	
	boolean isEmpty(){
		return (top == null);
	}
	
	int size(){
		int size = 0;
		Node current = top;
		while(current != null){
			size++;
			current = current.link;
		}
		return size;
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