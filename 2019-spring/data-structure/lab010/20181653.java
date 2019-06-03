// Lab 010	: Natural Merge
// Name :
// Student ID :

import java.util.*;


class NaturalMerge {
	int noe;  // the number of elements
	private int[] inputArray; // input array 
	int[] outputArray; // output array 


	NaturalMerge() { 
		noe = 0;
	}

	void Init(int [] arr, int n) { 
		noe = n;
		inputArray = new int[noe];
		System.arraycopy(arr, 0, inputArray, 0, n);

		outputArray = new int[noe];
	}

	void Merge() {
		int m = 0;
		while (inputArray[m] <= inputArray[++m]);
		System.out.println("n = " + noe + ", m = " + m);

		// NEED TO IMPLEMENT
		outputArray = new int[noe];
		int i = 0, j = m, k = 0;
		while (i<m && j<noe) {
			if (inputArray[i] < inputArray[j]) outputArray[k++] = inputArray[i++];
			else outputArray[k++] = inputArray[j++];
		}
		while (i<m) outputArray[k++] = inputArray[i++];
		while (j<noe) outputArray[k++] = inputArray[j++];
	}
}


