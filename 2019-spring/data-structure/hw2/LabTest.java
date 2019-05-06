import java.util.*;

public class LabTest {
	static Scanner in;
	static void InitSparseMatrix(SparseMatrix mat, String msg) {
        System.err.println();
        System.err.println("Initialize a sparse matrix " + msg);
        int r, c, v;

        System.err.println("Enter number of rows and columns ");
        r = in.nextInt();
        c = in.nextInt();
        mat.Init(r, c);

        for(int i = 1; i <= r; i++) {
            for(int j = 1; j <= c; j++) {
				v = in.nextInt();
				if(v == 0)
					continue;
				mat.AddOneElement(i, j, v);
			}
        }
    }

	public static void main(String[] args) {
		in = new Scanner(System.in);

		while(true) {
			SparseMatrix a = new SparseMatrix();
			SparseMatrix b = new SparseMatrix();

			// form the Polynomial a
			InitSparseMatrix(a, "a");
			a.ShowByRowMajor("a, Row major order");
			a.ShowByColumnMajor("a, Column major order");
	
			InitSparseMatrix(b, "b");
			b.ShowByRowMajor("b, Row major order");
			b.ShowByColumnMajor("b, Column major order");
	
			SparseMatrix c = a.Add(b);
			c.ShowByRowMajor("c = a + b, Row major order");
			c.ShowByColumnMajor("c = a + b, Column major order");
	
			for(int i = 0; i < 9; i++) {
				// update 9 values
				int row, col, v;
				System.err.println();
				System.err.println("Enter new value of an element (r, c, v) ");
				row = in.nextInt();
				col = in.nextInt();
				v = in.nextInt();
				System.out.println();
				System.out.println(String.format("new value: %d %d %d ", row, col, v)); 
				if(c.Delete(row, col) == false) {
					System.out.println("Not Existing Element " + row + " " + col);
				}
				if(c.AddOneElement(row, col, v) == false) {
					System.out.println("Existing Element " + row + " " + col);
				}
				c.ShowByRowMajor("new C, Row major Order ");
				c.ShowByColumnMajor("new C, Column major Order");
			}
	
			System.err.println("Continue (y/n) ");
			String ans = in.next();
			if(ans.equals("n"))
				break;
		}
	}
}





