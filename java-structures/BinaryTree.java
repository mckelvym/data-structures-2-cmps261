class BinaryTree{
	private Node root;
	private Node current;
	
	BinaryTree(){
		root = new Node();	
	}
	
	BinaryTree(Object data){
		root = new Node(data);
	}
	
	BinaryTree(Object data, BinaryTree tree, boolean isLeft){
		root = new Node(data, tree, isLeft);
	}
	
	BinaryTree(Object data, BinaryTree left, BinaryTree right){
		root = new Node(data, left, right);
	}
	
	void inOrderTraversal(){
		if(root.left != null)
			root.left.inOrderTraversal();
		if(root.data != null)
			print(root.data);
		if(root.right != null)
			root.right.inOrderTraversal();
	}
	
	void preOrderTraversal(){
		if(root.data != null)
			print(root.data);
		if(root.left != null)
			root.left.preOrderTraversal();
		if(root.right != null)
			root.right.preOrderTraversal();
	}
	
	void postOrderTraversal(){
		if(root.left != null)
			root.left.postOrderTraversal();
		if(root.right != null)
			root.right.postOrderTraversal();
		if(root.data != null)
			print(root.data);
	}
	
	void breadthFirstTraversal(){
		Queue q = new Queue();
		q.enQ(this);
		while(!q.isEmpty()){
			Object obj = q.deQ();
			if(obj instanceof BinaryTree){
				BinaryTree temp = (BinaryTree)obj;
				print(temp.getRootData());
				if(temp.getLeftChild() != null)
					q.enQ(temp.getLeftChild());
				if(temp.getRightChild() != null)
					q.enQ(temp.getRightChild());
			}
		}		
	}
	
	void unTraversal(){
		Stack s = new Stack();
		s.push(this);
		while(!s.isEmpty()){
			Object obj = s.pop();
			if(obj instanceof BinaryTree){
				BinaryTree temp = (BinaryTree)obj;
				print(temp.getRootData());
				if(temp.getLeftChild() != null)
					s.push(temp.getLeftChild());
				if(temp.getRightChild() != null)
					s.push(temp.getRightChild());
			}
		}		
	}
	
	boolean isEmpty(){
		return (root.data == null);
	}
	
	BinaryTree getLeftChild(){
		if(root.left != null)
			return root.left;
		else return null;
	}
	
	BinaryTree getRightChild(){
		if(root.right != null)
			return root.right;
		else return null;
	}
	
	Object getRootData(){
		return root.data;
	}
	
	Object findPrevious(){
		current = root;
		if(current.left == null)
		  return (current.data);
		else{
			current = current.left.root;
			while(current.right != null){
				current = current.right.root;
			}
			return (current.data);
		}
	}
	
	Object findNext(){
		current = root;
		if(current.right == null)
		  return (current.data);
		else{
			current = current.right.root;
			while(current.left != null){
				current = current.left.root;
			}
			return (current.data);
		}
	}
		
	void print(Object info){
		System.out.print(info + " ");
	}
	
	void println(Object info){
		System.out.println(info);
	}
}