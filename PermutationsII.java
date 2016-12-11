/*
 * Written by: Joseph Thweatt
 * Runtime: 16 ms
 *
 * Given a collection of distinct 
 * numbers, return all possible unique permutations.
 *
 * For example,
 * [1,1,2] have the following unique permutations:
 * [
 *  [1,1,2],
 *  [1,2,1],
 *  [2,1,1]
 * ]
 */

import java.util.ArrayList;
import java.util.List;
import java.util.Set;
import java.util.HashSet;

public class Solution {

    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> permutes = new ArrayList<List<Integer>>();
		List<Integer> permute = new ArrayList<Integer>();
		Set<Integer> occured = new HashSet<Integer>();
		occured.add(nums[0]);
        
        if (nums.length == 1) {
			permute.add(nums[0]);
            permutes.add(permute);
			return permutes;
        } else if (nums.length == 2) {
			// add initial order
			permute.add(nums[0]);
			permute.add(nums[1]);
			permutes.add(permute);

			// add reverse order if they aren't duplicates
			if (nums[0] != nums[1]) {
    			permute = new ArrayList<Integer>();
    			permute.add(nums[1]);
    			permute.add(nums[0]);
    			permutes.add(permute);
			}

			return permutes;
		}
		
		int[] subNums = new int[nums.length - 1];
		System.arraycopy(nums, 1, subNums, 0, subNums.length);
		List<List<Integer>> subPermutes = permuteUnique(subNums);

		for (int p = 0; p < subPermutes.size(); p++) {
			permute.add(nums[0]);
			permute.addAll(subPermutes.get(p));
			permutes.add(permute);

			permute = new ArrayList<Integer>();
		}

		for (int i = 1; i < nums.length; i++) {

			if (!occured.contains(nums[i])) {
				occured.add(nums[i]);

				int temp = nums[i];
				nums[i] = nums[0];
				nums[0] = temp;

				subNums = new int[nums.length - 1];
				System.arraycopy(nums, 1, subNums, 0, subNums.length);
				subPermutes = permuteUnique(subNums);

				for (int p = 0; p < subPermutes.size(); p++) {
					permute.add(nums[0]);
					permute.addAll(subPermutes.get(p));
					permutes.add(permute);

					permute = new ArrayList<Integer>();
				}
			}
		}

		return permutes;
    }
}