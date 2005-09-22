import java.awt.*;

class main{
	public static void main(String[] args){
		new main();
	}
	
	main(){
		//doBinaryTree();
		stacky();
	}
	
	void doBinaryTree(){
		BinaryTree root = new BinaryTree(new String("ROOT"), 
		 new BinaryTree("m",
		 	new BinaryTree("i",
		 		new BinaryTree("a"),
		 		new BinaryTree("b")),
		 	new BinaryTree("j",
		 		new BinaryTree("c"),
		 		new BinaryTree("d"))), 
		 new BinaryTree("n",
		 	new BinaryTree("k",
		 		new BinaryTree("e"),
		 		new BinaryTree("f")),
		 	new BinaryTree("l",
		 		new BinaryTree("g"),
		 		new BinaryTree("h")))
		);
		System.out.println("           root");
		System.out.println("           /  \\");
		System.out.println("         /      \\");
		System.out.println("       /          \\");
		System.out.println("      m            n");
		System.out.println("     / \\          /  \\");
		System.out.println("   /    \\        /    \\");
		System.out.println("  i      j      k      l");
		System.out.println(" / \\    / \\    / \\    / \\");
		System.out.println("a   b  c   d  e   f  g   h");
		System.out.println();
		
		System.out.println("\n\n" + "InOrder Traversal");
		root.inOrderTraversal();
		
		System.out.println("\n\n" + "PreOrder Traversal");
		root.preOrderTraversal();
		
		System.out.println("\n\n" + "PostOrder Traversal");
		root.postOrderTraversal();
		
		System.out.println("\n\n" + "Breadth First Traversal");
		root.breadthFirstTraversal();
		
		System.out.println("\n\n" + "unTraversal");
		root.unTraversal();
		
		System.out.println("\n\n" + "Previous value to root: " + root.findPrevious());
		
		System.out.println("\n" + "Next value to root: " + root.findNext());		
	}
	
	void stacky(){
		String str[] = new String[5];
		str[0] = "A";
		str[1] = "BB";
		str[2] = "CCC";
		str[3] = "DDDD";
		str[4] = "EEEEE";
		LinkedList l = new LinkedList(str);
		l.printAll();
		System.out.println();
		for(int i = 0; i < 8; i++){
			System.out.println("i = " + i + "  " + l.getAtIndex(i));
		}
		l.add(3, "FLKJA");
		l.printAll();
	}
	
}