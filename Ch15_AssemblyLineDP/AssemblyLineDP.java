
public class AssemblyLineDP {
	
	private static int[] fastestWay(int[][] a, int[][] t, int[] e, int[] x, int n,
			                       int[][] f, int[][] l) {
		f[0][0] = e[0] + a[0][0];
		f[1][0] = e[1] + a[1][0];
		for (int j = 1; j < n; j++) {
			if (f[0][j - 1] + a[0][j] <= f[1][j - 1] + +t[1][j - 1] + a[0][j]) {
				f[0][j] = f[0][j - 1] + a[0][j];
				l[0][j] = 0;
			} else {
				f[0][j] = f[1][j - 1] + t[1][j - 1] + a[0][j];
				l[0][j] = 1;
			}
			
			if (f[1][j - 1] + a[1][j] <= f[0][j - 1] + +t[0][j - 1] + a[1][j]) {
				f[1][j] = f[1][j - 1] + a[1][j];
				l[1][j] = 1;
			} else {
				f[1][j] = f[0][j - 1] + t[0][j - 1] + a[1][j];
				l[1][j] = 0;
			}
		}
		int f_star, l_star;
		if (f[0][n - 1] + x[0] <= f[1][n - 1] + x[1]) {
			f_star = f[0][n - 1] + x[0];
			l_star = 0;
		} else {
			f_star = f[1][n - 1] + x[1];
			l_star = 1;
		}
		return new int[] { f_star, l_star };
	}
	
	private static void printStations(int l_star, int[][] l) {
		int i = l_star;
		int n = l[0].length;
		System.out.println("line " + i + ", station " + (n - 1));
		for (int j = n - 1; j > 0; j--) {
			i = l[i][j];
			System.out.println("line " + i + ", station " + (j - 1));
		}
	}
	
	private static void printTables(int[][] fastest, int f_star, int[][] lines, int l_star) {
		System.out.println("===== f table ======");
		for (int i = 0; i < fastest[0].length; i++) {
			System.out.printf("%3d", i);
		}
		System.out.println();
		for (int i = 0; i < fastest[0].length; i++) {
			System.out.print("---");
		}
		System.out.println();
		for (var row : fastest) {
			for (int elem : row) {
				System.out.printf("%3d", elem);
			}
			System.out.println();
		}
		System.out.println("f* = " + f_star);
		System.out.println("===== l table ======");
		for (int i = 1; i < lines[0].length; i++) {
			System.out.printf("%2d", i);
		}
		System.out.println();
		for (int i = 1; i < lines[0].length; i++) {
			System.out.print("--");
		}
		System.out.println();
		for (var row : lines) {
			for (int i = 1; i < row.length; i++) {
				System.out.printf("%2d", row[i]);
			}
			System.out.println();
		}
		System.out.println("l* = " + l_star);
	}

	public static void main(String[] args) {
		int[][] a = {{7, 9, 3, 4, 8, 4}, 
				     {8, 5, 6, 4, 5, 7}};
		int[][] t = {{2, 3, 1, 3, 4}, 
				     {2, 1, 2, 2, 1}};
		int[] e = {2, 4};
		int[] x = {3, 2};
		
		int[][] fastest = {{0, 0, 0, 0, 0, 0},
		                   {0, 0, 0, 0, 0, 0}};
		
		int[][] lines = {{0, 0, 0, 0, 0, 0},
				         {0, 0, 0, 0, 0, 0}};
		
		int[] vals = fastestWay(a, t, e, x, fastest[0].length, fastest, lines);
		int f_star = vals[0];
		int l_star = vals[1];
		
		printTables(fastest, f_star, lines, l_star);
		printStations(l_star, lines);
	}
}
