// Lab 009	: Graph Floyd Algorithm 
// Name : Lee Kang Hee
// Student ID : 20181653

import java.util.*;


class Graph {
	int numofnodes;  // the number of nodes in the graph
	private int[][] CostAdj; // Adjacency matrix
	private int[] dist; // dist array
	private int[] p; // p array

	final int LargeCost = 999999;

	Graph() { 
		// Graph constructor. 
		numofnodes = 0;
	}


	void Init(int n) { 
		numofnodes = n;
		// now create 2 dimensional array of numofnodes * numofnodes
		CostAdj = new int[numofnodes][numofnodes];
		dist = new int[numofnodes];
		p = new int[numofnodes];

		for(int i = 0; i < numofnodes; i++) {
			// initialize all entries to 0
			for(int j = 0; j < numofnodes; j++)
				CostAdj[i][j] = LargeCost;  // initialize the adjacency matrix
			CostAdj[i][i] = 0;
		}
	}
	public String toString() { 
		String str;
		int i = 0;
		str = "Dist : ";
		for(i = 0; i < numofnodes; i++)
			str +=  dist[i] + " ";
		str += "\n";
	
		str += "P    : ";
		for( i = 0; i < numofnodes; i++)
			str += p[i] + " ";
		str += "\n";
	
		// show the paths to all the destinations
		for( i = 0; i < numofnodes; i++) {
			str += "Path to " + i + " : ";
			str += OutPath(i);	
			str += "\n";
		}
		return str;
	}



	void Edge(int v1, int v2, int cost) { 
		// NEED TO IMPLEMENT
		CostAdj[v1][v2] = cost;
	}


	String OutPath(int i) { 
		if (p[i] == -1) return " " + i;
		String str = "";
		str += OutPath(p[i]);
		str += " " + i;
		return str;
	}

	void BellmanFord(int source) { 
		// NEED TO IMPLEMENT
		for (int i=0;i<numofnodes;++i) dist[i] = LargeCost;
		dist[source] = 0;
		p[source] = -1;
		for (int i=1;i<numofnodes;++i) {
			for (int v=0;v<numofnodes;++v) {
				for (int u=0;u<numofnodes;++u) {
					if (dist[u] + CostAdj[u][v] < dist[v]) {
						dist[v] = dist[u] + CostAdj[u][v];
						p[v] = u;
					}
				}
			}
		}
	}
}




