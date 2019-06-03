import java.util.*;

// Name : Lee KangHee
// Student ID : 20181653


class HeapSort {
	int [] heap;	// Heap Array
	int heapSize;	// number of elements in the Heap

	HeapSort(int cap) {
		heap = new int[cap + 1];
		heapSize = 0;
	}

	public String toString() { 
		// Convert heap array into a string
		String str;
		str = "Heap : - ";

		for(int i = 1; i <= heapSize; i++)
			str +=  heap[i] + "  ";

		return str;
	}

	void  Init(int [] es, int n) {	
		// fill the heap array by the input
		// we need to create heap structure when we call Sort()
		heapSize = n;
		for(int i = 1; i <= n; i++)
			heap[i] = es[i];
	}

	void swap(int i, int j) {
		int tmp = heap[i];
		heap[i] = heap[j];
		heap[j] = tmp;
	}
	void  Adjust(int root, int n) {	
		// adjust binary tree with root "root" to satisfy heap property.
		// The left and right subtrees of "root" already satisfy the heap
		// property. No node index is > n.
		//	"NEED TO IMPLEMENT" 
		while (true) {
			int left = root * 2, right = root * 2 + 1;
			if (left > n) break;
			int next = root;
			if (heap[next] < heap[left]) next = left;
			if (right <= n && heap[next] < heap[right]) next = right;
			if (next == root) break;
			swap(next, root);
			root = next;
		}
	}

	void  Sort() {	
		// sort heap[1:n] into nondecreasing order
		//	"NEED TO IMPLEMENT" 
		for (int i=heapSize;i>0;--i) {
			Adjust(i, heapSize);
		}
		System.out.println(this);
		for (int i=heapSize;i>1;--i) {
			swap(i, 1);
			Adjust(1, i-1);
			System.out.println(this);
		}
	}
}