/*
 * Written by: Joseph Thweatt
 * Runtime: 10 ms
 *
 * Given a collection of distinct 
 * numbers, return all possible permutations.
 */
 
import java.util.List;
import java.util.ArrayList;

public class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> permutes = new ArrayList<List<Integer>>();
		List<Integer> permute = new ArrayList<Integer>();
        
        if (nums.length == 0) {
            permutes.add(permute);
            return permutes;
        } else if (nums.length == 1) {
			permute.add(nums[0]);
            permutes.add(permute);
			return permutes;
        } else if (nums.length == 2) {
			// add initial order
			permute.add(nums[0]);
			permute.add(nums[1]);
			permutes.add(permute);

			// add reverse order
			permute = new ArrayList<Integer>();
			permute.add(nums[1]);
			permute.add(nums[0]);
			permutes.add(permute);

			return permutes;
		}

		for (int i = 0; i < nums.length; i++) {

			if (i != 0) {
				int temp = nums[i];
				nums[i] = nums[0];
				nums[0] = temp;
			}

			int[] subNums = new int[nums.length - 1];
			System.arraycopy(nums, 1, subNums, 0, subNums.length);
			List<List<Integer>> subPermutes = permute(subNums);

			for (int p = 0; p < subPermutes.size(); p++) {
				permute.add(nums[0]);
				permute.addAll(subPermutes.get(p));
				permutes.add(permute);

				permute = new ArrayList<Integer>();
			}
		}

		return permutes;
    }
}