import java.util.*;

// Name : Lee KangHee
// Student ID : 20181653

@SuppressWarnings("unchecked")
class BST <T extends KeyValue> {

	class TreeNode <U extends KeyValue> {
		U data;	// storage for data : in HW 3, T will be Item
		TreeNode<U> leftChild;	// link to the left Child
		TreeNode<U> rightChild;	// link to the right Child

		// constructors come here
		TreeNode() {
			leftChild = rightChild = null;
		}
		TreeNode(U d) {
			// data is given
			data = d;
			// the leftChild and rightChild field are null
			leftChild = rightChild = null;
		}
	};

	TreeNode <T> root;// the reference to the root node

	BST() { 
		// BST constructor. 
		root = null;
	}

    void Show() {

		System.out.print( "Pre  Order : ");
		PreOrder(root);
		System.out.println("");
		System.out.print("In   Order : ");
		InOrder(root);
		System.out.println("");
		System.out.print("Post Order : ");
		PostOrder(root);
		System.out.println("");
		System.out.print("Number of Nodes : ");
		System.out.print( Count(root));
		System.out.println("");
		System.out.print("Height : ");
		System.out.println( Height(root));
		System.out.println("");
	}


	// IMPLEMENT THE FOLLOWING FUNCTIONS

	boolean Insert(T item)  {
		// first search the key
		if(root == null) {
			root = new TreeNode(item);
			return true;
		}

		TreeNode<T> ptr, parent;
		ptr = root;

		while (true) {
			parent = ptr;
			if (item.GetKey() == ptr.data.GetKey()) return false;
			else if (item.GetKey() < ptr.data.GetKey()) ptr = ptr.leftChild;
			else ptr = ptr.rightChild;
			if (ptr == null) break;
		}
		
		if (item.GetKey() < parent.data.GetKey()) parent.leftChild = new TreeNode(item);
		else parent.rightChild = new TreeNode(item);

		return true;
	}

	T Get(T item)  {
		// use the key field of item and find the node
		// do not use val field of item
		TreeNode<T> ptr = GetNode(item);
		if (ptr == null) return null;
		return ptr.data;
	}

	TreeNode<T> GetNode(T item) {
		TreeNode<T> ptr = root;
		while (true) {
			if (ptr == null) return null;
			if (item.GetKey() == ptr.data.GetKey()) break;
			else if (item.GetKey() < ptr.data.GetKey()) {
				ptr = ptr.leftChild;
			}
			else {
				ptr = ptr.rightChild;
			}
		}
		return ptr;
	}

	boolean Delete(T item) {
		TreeNode<T> ptr, parent;
		ptr = root; parent = null;
		while (true) {
			if (ptr == null) return false;
			if (item.GetKey() == ptr.data.GetKey()) break;
			parent = ptr;
			if (item.GetKey() < ptr.data.GetKey()) ptr = ptr.leftChild;
			else ptr = ptr.rightChild;
		}
		if (ptr.leftChild == null && ptr.rightChild == null) {
			if (root == ptr) root = null;
			else if (parent.leftChild == ptr) parent.leftChild = null;
			else parent.rightChild = null;
		}
		else if (ptr.leftChild == null) {
			if (root == ptr) root = ptr.rightChild;
			if (parent.leftChild == ptr) parent.leftChild = ptr.rightChild;
			else parent.rightChild = ptr.rightChild;
		}
		else if (ptr.rightChild == null) {
			if (root == ptr) root = ptr.leftChild;
			if (parent.leftChild == ptr) parent.leftChild = ptr.leftChild;
			else parent.rightChild = ptr.leftChild;
		}
		else {
			TreeNode<T> largest, largestParent;
			largest = ptr.leftChild; largestParent = ptr;
			while (largest.rightChild != null) {
				largestParent = largest;
				largest = largest.rightChild;
			}
			
			ptr.data = largest.data;
			if (ptr.leftChild == largest) {
				ptr.leftChild = largest.leftChild;
			}
			else {
				largestParent.rightChild = largest.leftChild;
			}
		}
		return true;
	}

	void  PreOrder(TreeNode<T> t)  {
		if (t == null) return;
		System.out.print("[" + t.data.GetKey() + "(" + t.data.GetValue() + ")]");
		PreOrder(t.leftChild);
		PreOrder(t.rightChild);
	}

	void  InOrder(TreeNode<T> t)  {
		if (t == null) return;
		InOrder(t.leftChild);
		System.out.print("[" + t.data.GetKey() + "(" + t.data.GetValue() + ")]");
		InOrder(t.rightChild);
	}

	void  PostOrder(TreeNode<T> t)  {
		if (t == null) return;
		PostOrder(t.leftChild);
		PostOrder(t.rightChild);
		System.out.print("[" + t.data.GetKey() + "(" + t.data.GetValue() + ")]");
	}

	int Count(TreeNode<T> t)  {
		if (t == null) return 0;
		return Count(t.leftChild) + Count(t.rightChild) + 1;
	}

	int  Height(TreeNode<T> t)  {
		if (t == null) return 0;
		int left = Height(t.leftChild);
		int right = Height(t.rightChild);
		return (left > right ? left : right) + 1;
	}
}