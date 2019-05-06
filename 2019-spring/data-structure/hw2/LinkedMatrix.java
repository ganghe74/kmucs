import java.util.*;

// offset

/**
 * LinkedMatrix Class
 * 
 */


// ---------- LinkedMatrix class -------------
public class LinkedMatrix {
	class MatrixNode {	
		int row;	// row
		int col;	// column
		int value;	// value
		MatrixNode down;	// down reference
		MatrixNode next;	// next reference
		MatrixNode(final int r, final int c, final int  v) {
			row = r;
			col = c;
			value = v;
		};
	};

	MatrixNode []row; // reference to the row chains
	MatrixNode []col; // reference to the column chains
	int rows, cols;


	LinkedMatrix() { // LinkedMatrix constructor. 
		row = null;
		col = null;
		rows = 0;
		cols = 0;
	}



	void Init(final int r, final int c) {
		rows = r;
		cols = c;

		row = new MatrixNode[rows + 1];
		for(int i = 1; i <= rows; i++) row[i] = null;
		col = new MatrixNode[cols + 1];
		for(int i = 1; i <= cols; i++) col[i] = null;
	}

	void ShowByRowMajor(String msg) {
		System.out.println();
		System.out.println("Sparse Matrix " + msg);

		MatrixNode p = null;
		int nextcol = 1;
		for(int i = 1; i <= rows; i++) {
			nextcol = 1;
			p = row[i];
			while(p != null) {
				if(p.col == nextcol) {
						System.out.print(p.value + " ");
						p = p.next;
				} else {
					System.out.print( "0 ");
				}
				nextcol++;
			}

			while(nextcol++ <= cols)
				System.out.print( "0 ");
			System.out.println();
		}
	}

	void ShowByColumnMajor(String msg) {
		System.out.println();
		System.out.println("Sparse Matrix " + msg);
		MatrixNode p = null;
		int nextrow = 1;
		for(int i = 1; i <= cols; i++) {
			nextrow = 1;
			p = col[i];
			while(p != null) {
				if(p.row == nextrow) {
					if(p.value == 0) {
						System.out.println("Fatal Error : Sparse Matrix should not have 0 value elements " + p.row + "," + p.col);
					}
					System.out.print(p.value + " ");
					p = p.down;
				} else
					System.out.print( "0 ");
				nextrow++;
			}
			while(nextrow++ <= rows)
				System.out.print( "0 ");
			System.out.println();
		}
	}

}









