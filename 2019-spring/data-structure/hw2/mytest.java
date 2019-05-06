public class mytest {
    public static void main(String[] args) {
        SparseMatrix a = new SparseMatrix();
        a.Init(5, 5);
        a.AddOneElement(1,1,5);
        a.AddOneElement(1,5,10);
        a.AddOneElement(1,3,20);
        a.Delete(1,1);

        a.ShowByRowMajor("a rowmajor");
        a.ShowByColumnMajor("a columnmajor");
    }
}