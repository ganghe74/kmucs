import java.util.*;

// ---------- Graph class -------------

class Graph {
    int numofnodes;  // the number of nodes in the graph
    private int[][] AdjMatrix; // Adjacency matrix
    private int[] visited; // mark the visitied node


    Graph() {
        // Graph constructor. 
        numofnodes = 0;
    }

    void Init(int n) {
        numofnodes = n;
        // now create 2 dimensional array of numofnodes * numofnodes
        AdjMatrix = new int[numofnodes][numofnodes];
        for(int i = 0; i < numofnodes; i++) {
            // initialize all entries to 0
            for(int j = 0; j < numofnodes; j++)
                AdjMatrix[i][j] = 0;  // initialize the adjacency matrix
        }
    }

	void Edge(int n1, int n2) { 
        AdjMatrix[n1][n2] = 1;
        AdjMatrix[n2][n1] = 1;
	}

	void Bfs(int v) { 
        visited = new int[numofnodes];
        Queue<Integer> q = new LinkedList<>();
        q.add(v);
        visited[v] = 1;

        while (q.size() > 0) {
            int now = q.peek();
            q.poll();
            System.out.print(now + " ");
            for (int next=0;next<numofnodes;++next) {
                if (AdjMatrix[now][next] > 0) {
                    if (visited[next] == 0) {
                        q.add(next);
                        visited[next] = 1;
                    }
                }
            }
        }

	}


}

