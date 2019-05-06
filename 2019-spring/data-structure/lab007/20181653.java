// Lab 007	: Disjoint Sets
// Name : Lee KangHee
// Student ID : 20181653

import java.util.*;


class DisjointSets {
	int numofelements;  // the total number of elements in all the disjoint sets
	private int[] parent; // maintains the parent pointer of each element in the disjoint sets
	private int[] weight; // maintains the weight of each set


	DisjointSets() { 
		// DisjointSets constructor. 
	}

	public String toString() { // Show all the element in sequence
		String str = new String();
	    // Show the array elements in parent[]

		str = "parent[] = - ";
		for(int i = 1; i <= numofelements; i++)
			str += parent[i] + " ";
		return str;
	}

	void InitSet(int n) { 
		// Initialize the array parent[] and weight[]
		numofelements = n;
		parent = new int[n+1];
		weight = new int[n+1];
		Arrays.fill(parent, 0);
		Arrays.fill(weight, 1);
	}

	boolean Union(int i, int j) { 
	// Union the set that contains i and the set that contains j
	// the set that has larger weight is the new root of the unioned set
	// when the weights are the same, choose the root of smaller value

		// first find the root of i and j
		while (parent[i] != 0) i = parent[i];
		while (parent[j] != 0) j = parent[j];
		if (i == j) return false;

		if ((weight[i] < weight[j]) || ((weight[i] == weight[j]) && (i < j))) {
			i = i^j;
			j = i^j;
			i = i^j;
		}

		parent[j] = i;
		weight[i] += weight[j];

		return true;
	}

	int SimpleFind(int i) { 
	// return the root node that contains the element i
		int root = i;
		while (parent[root] != 0) {
			root = parent[root];
		}
		return root;
	}
}

