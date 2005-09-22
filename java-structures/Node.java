class Node{
	public Object data;
	public BinaryTree left;
	public BinaryTree right;
	
	Node(){
		data = null;
		left = null;
		right = null;	
	}
	
	Node(Object data){
		this.data = data;
		left = null;
		right = null;
	}
	
	Node(Object data, BinaryTree tree, boolean isLeft){
		this.data = data;
		if(isLeft)
			left = tree;
		else
			right = tree;
	}
	
	Node(Object data, BinaryTree left, BinaryTree right){
		this.data = data;
		this.left = left;
		this.right = right;
	}	
}