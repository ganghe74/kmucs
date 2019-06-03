// Lab 011	: Huffman Merging Runs
// Name : Lee KangHee
// Student ID : 20181653

import java.util.*;


class Huffman {
	int noe;  // the number of elements
	private int[] inputArray; // input array 


	Huffman() { 
		// Graph constructor. 
		noe = 0;
	}

	void Init(int [] arr, int n) { 
		noe = n;
		inputArray = new int[noe];
		System.arraycopy(arr, 0, inputArray, 0, n);
		System.out.print("Runs : ");
		for(int i = 0; i < noe; i++) {
			System.out.print(inputArray[i] + " ");
		}
		System.out.println();
	}

	void MergeRuns() { 
		PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
		for (int i=0;i<noe;++i) pq.add(inputArray[i]);
		while (pq.size() > 1) {
			int a = pq.poll();
			int b = pq.poll();
			System.out.println("Merging " + a + " " + b);
			pq.add(a+b);
		}
	}
}


