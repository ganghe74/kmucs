// Lab 012	: Bloom Filter
// Name :
// Student ID :

import java.util.*;


class BloomFilter {
	private int[] bfArray; // Bloom Filter array 
	int m;	// bloom filter size
	int h;	// number of hash functions


	// Constructor
	BloomFilter() { 
		m = 0;
		h = 0;
	}

	// hash function
	private int f(int h, int k) { return (k * (h + 1) % m); }

	// Initialize bloom filter
	void Init(int size, int noh) { 
		bfArray = new int[size];
		m = size;
		h = noh;
		for(int i = 0; i < m; i++)
			bfArray[i] = 0;
	}

	// bloom filter contents
	public String toString() { 
		String str = "Bloom Filter : ";
		for(int i = 0; i < m; i++)
			str += bfArray[i] + " " ;
		return str;
	}

	// insert a key
	void Insert(int key) {
		// NEED TO IMPLEMENT
		for (int i=0;i<h;++i) {
			bfArray[f(i, key)] = 1;
		}
	}

	// check if a key exists
	boolean Check(int key) {
	// NEED TO IMPLEMENT
		for (int i=0;i<h;++i) {
			if (bfArray[f(i, key)] == 0) return false;
		}
		return true;
	}
}


