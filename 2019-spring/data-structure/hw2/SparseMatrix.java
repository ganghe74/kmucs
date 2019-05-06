import java.util.*;

// offset

/**
 * SparseMatrix Class
 * 
 */


// ---------- SparseMatrix class -------------
class SparseMatrix extends LinkedMatrix {

	SparseMatrix() { } // SparseMatrix constructor. 


	boolean AddOneElement(final int r, final int c, final int  v) {
		if (v == 0) return true;

		MatrixNode node = new MatrixNode(r, c, v);
		node.next = null; node.down = null;
		MatrixNode beforeNextNode = row[r];
		MatrixNode beforeDownNode = col[c];

		if (beforeNextNode == null) row[r] = node;
		else {
			if (beforeNextNode.col == c) return false;
			else if (beforeNextNode.col > c) {
				node.next = beforeNextNode;
				row[r] = node;
			}
			else {
				while (beforeNextNode.next != null) {
					if (beforeNextNode.next.col == c) return false;
					if (beforeNextNode.next.col > c) break;
					beforeNextNode = beforeNextNode.next;
				}
				node.next = beforeNextNode.next;
				beforeNextNode.next = node;
			}
		}

		if (beforeDownNode == null) col[c] = node;
		else {
			if (beforeDownNode.row == r) return false;
			else if (beforeDownNode.row > r) {
				node.down = beforeDownNode;
				col[c] = node;
			}
			else {
				while (beforeDownNode.down != null) {
					if (beforeDownNode.down.row == r) return false;
					if (beforeDownNode.down.row > r) break;
					beforeDownNode = beforeDownNode.down;
				}
				node.down = beforeDownNode.down;
				beforeDownNode.down = node;
			}
		}

		return true;
	}

	boolean Delete(final int r, final int c) {
		if (row[r] == null || col[c] == null) return false;

		MatrixNode node = row[r];
		while (node.next != null) {
			if (node.col == c) break;
			node = node.next;
		}
		if (node.col != c) return false;

		if (node == row[r]) row[r] = node.next;
		else {
			MatrixNode beforeNextNode = row[r];
			while (beforeNextNode.next != null) {
				if (beforeNextNode.next.col == c) break;
				beforeNextNode = beforeNextNode.next;
			}
			beforeNextNode.next = node.next;
		}

		if (node == col[c]) col[c] = node.down;
		else {
			MatrixNode beforeDownNode = col[c];
			while (beforeDownNode.down != null) {
				if (beforeDownNode.down.row == r) break;
				beforeDownNode = beforeDownNode.down;
			}
			beforeDownNode.down = node.down;
		}

		return true;
	}

	SparseMatrix Add(SparseMatrix b) {
		SparseMatrix c = new SparseMatrix();
		c.Init(rows, cols);

		for (int i=1;i<=rows;++i) {
			MatrixNode aNode = row[i];
			MatrixNode bNode = b.row[i];
			while (aNode != null && bNode != null) {
				if (aNode.col == bNode.col) {
					if (aNode.value + bNode.value != 0) c.AddOneElement(aNode.row, aNode.col, aNode.value + bNode.value);
					aNode = aNode.next;
					bNode = bNode.next;
				}
				else if (aNode.col < bNode.col) {
					c.AddOneElement(aNode.row, aNode.col, aNode.value);
					aNode = aNode.next;
				}
				else {
					c.AddOneElement(bNode.row, bNode.col, bNode.value);
					bNode = bNode.next;
				}
			}
			while (aNode != null) {
				c.AddOneElement(aNode.row, aNode.col, aNode.value);
				aNode = aNode.next;
			}
			while (bNode != null) {
				c.AddOneElement(bNode.row, bNode.col, bNode.value);
				bNode = bNode.next;
			}
		}

		return c;
	}
}


