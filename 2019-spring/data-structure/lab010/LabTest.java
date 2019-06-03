// Lab 010	: 
// Name :
// Student ID :

import java.util.*;

class LabTest {
	static Scanner in;
	public static void main(String[] args) {
		in = new Scanner(System.in);

		NaturalMerge merge = new NaturalMerge();	// Natural Merge

		while(true) {
			try {
				System.err.print("Merge > ");
	
				String cmd = in.next();
				if(cmd.equals("quit"))
					break;
				if(cmd.equals("merge")) {
					int [] intarr = new int[1024];
					int i = 0;
					int item;
					while(true) {
						item = in.nextInt();
						if(item == -1)
							break;
						intarr[i++] = item;
					}
					int noe = i;
					merge.Init(intarr, noe);
					ShowArray("Input", intarr, noe);

					merge.Merge();
					ShowArray("Output", merge.outputArray, noe);
					System.out.println("");
				}
			} catch (Exception e) {
				System.out.println(e);
			}
		}
		System.err.println("");
	}

	static void ShowArray(String t, int []intarray, int n) {
		System.out.print(t + " : ");
		for(int i = 0; i < n; i++) {
			System.out.print(intarray[i] + " ");
		}
		System.out.println("");
	}
}




