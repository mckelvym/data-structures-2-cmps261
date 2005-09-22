class Queue{
	private Node front;
	private Node back;
	
	Queue(){
		front = null;
		back = null;
	}
	
	void enQ(Object data){
		Node temp = new Node(data);
		if(front == null){
			front = temp;
			back = temp;
		}
		else{
			back.link = temp;
			back = back.link;
		}
	}
	
	Object deQ(){
		if(!isEmpty()){
			Node temp = front;
			front = front.link;
			if(front == null)
				back = null;
			return temp.data;
		}
		else return null;
	}
	
	boolean isEmpty(){
		return (front == null);
	}
	
	int size(){
		int size = 0;
		Node current = front;
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