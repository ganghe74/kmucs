// Lab 013	: 
// Name :
// Student ID :

import java.util.*;

class LabTest {
	static Scanner in;
	public static void main(String[] args) {
		in = new Scanner(System.in);

		BloomFilter bf = new BloomFilter();	// Bloom Filter

		while(true) {
			try {
				System.err.print("BF > ");
	
				String cmd = in.next();
				if(cmd.equals("quit"))
					break;
				if(cmd.equals("init")) {
					int size = in.nextInt();
					int h = in.nextInt();
					bf.Init(size, h);

				} else if(cmd.equals("ins")) {
					int key = in.nextInt();
					bf.Insert(key);
					System.out.println(bf);
				} else if(cmd.equals("check")) {
					int key = in.nextInt();
					System.out.print("Check " + key + ": ");
					if(bf.Check(key))
						System.out.println("MAYBE");
					else 
						System.out.println("NO");
				}
			} catch (Exception e) {
				System.out.println(e);
			}
		}
		System.err.println("");
	}
}




