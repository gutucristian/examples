import java.util.*;

class SubsetSum {
	public static void main(String[] args) {
		int set[] = {3, 34, 4, 12, 5, 2};
		int sum = 9;
		int n = set.length;
		int[] subset = new int[n];
		System.out.println(isSubsetSum(set, n, sum, 0, subset));
	}

	public static int isSubsetSum(int set[], int n, int sum, int i, int[] subset) {
		int total = 0;

		if (sum == 0) {
			System.out.println(Arrays.toString(subset));
			return 1;
		}

		if (n == 0 && sum != 0) {
			return 0;
		}

		if (set[n-1] > sum) {
			total += isSubsetSum(set, n-1, sum, i, subset);
			return total;
		}
		
		int[] a = subset.clone();
		total += isSubsetSum(set, n-1, sum, i, a);
		int[] b = subset.clone();
		b[i] = set[n-1];
		total += isSubsetSum(set, n-1, sum-set[n-1], i+1, b);
		return total;
		// return isSubsetSum(set, n-1, sum) || isSubsetSum(set, n-1, sum-set[n-1]);
	}
}
