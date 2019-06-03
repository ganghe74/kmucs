// Lab 010	:
// Name : Lee KangHee
// Student ID :	20181653

import java.util.*;

class LabTest {
	static Scanner in;
	public static void main(String[] args) {
		in = new Scanner(System.in);

		Huffman hf = new Huffman();	// Huffman

		while(true) {
			try {
				System.err.print("Huff > ");
	
				String cmd = in.next();
				if(cmd.equals("quit"))
					break;
				if(cmd.equals("huff")) {
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
					hf.Init(intarr, noe);
					hf.MergeRuns();
				}
			} catch (Exception e) {
				System.out.println(e);
			}
		}
		System.err.println("");
	}

}




