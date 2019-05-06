// Lab 007	: Disjoint Sets
// Name :
// Student ID :

import java.util.*;

class LabTest {
	static Scanner in;
	public static void main(String[] args) {
		in = new Scanner(System.in);

		DisjointSets ds = new DisjointSets();	// disjoint set instance

		while(true) {
			try {
				System.err.println("DS > ");
	
				String cmd = in.next();
				if(cmd.equals("quit"))
					break;
				if(cmd.equals("i")) {
					int noe;
					noe = in.nextInt();

					ds.InitSet(noe);
				} else if(cmd.equals("u")) {
					int i, j;
					i = in.nextInt();
					j = in.nextInt();
					if(ds.Union(i, j) == false)
						System.out.println("The two sets are the same. ");
				} else if(cmd.equals("f")) {
					int i, root;
					i = in.nextInt();
					root = ds.SimpleFind(i);
					System.out.println("Root of " + i + " = " + root);
				}
			} catch (Exception e) {
				System.out.println(e);
			}
			// show the current disjoint sets
			System.out.println(ds);
		}
	}
}




