import java.util.*;

class ij {
	int i, j;
	ij(int a, int b) {
		i = a;
		j = b;
	}
}

class Maze {
	private int[][] move = {{0,1},{1,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0}};
	private int[][] maze;	// 2 dim array for maze
	private int[][] mark;	// 2 dim array for visit marking
	
	public Maze(int m, int p) {
		maze = new int[m + 2][p + 2];
		mark = new int[m + 2][p + 2];
		for(int i = 0; i < m + 2; i++)
			for(int j = 0; j < p + 2; j++) {
				maze[i][j] = 1;
				mark[i][j] = 0;
			}
	}

	// create the maze structure
	public void SetWall(int i, int j, int val) {
		maze[i][j] = val;
	}


	public void Path(int m, int p) {
		Stack<ij> st = new Stack<>();
		st.push(new ij(1,1));

		int i, j, g, h;
		i = j = g = h = 0;
		while (!st.isEmpty()) {
			i = st.peek().i;
			j = st.peek().j;
			
			boolean ok = false;

			for (int k=0;k<8;++k) {
				g = i + move[k][0];
				h = j + move[k][1];
				if (maze[g][h] == 0 && mark[g][h] == 0)  {
					ok = true;
					break;
				}
			}

			if (!ok) {
				st.pop();
				continue;
			}

			mark[g][h] = 1;

			st.push(new ij(g,h));

			if ((g == m) && (h == p)) {
				Stack<ij> ans = new Stack<>();
				while (!st.isEmpty()) {
					ans.push(st.peek());
					st.pop();
				}
				while (!ans.isEmpty()) {
					System.out.println("(" + ans.peek().i + "," + ans.peek().j + ")");
					ans.pop();
				}
				return;
			}
			
			i = g;
			j = h;

		}

		System.out.println("No path in the maze.");
	}

}; 

