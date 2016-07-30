import java.util.Arrays;

public class Solution {
    public int maxCoins(int[] nums) {
        System.out.println(Arrays.toString(nums));
        if (nums.length == 1) {
            return nums[0];
        } else if (nums.length == 2) {
            if (nums[0] < nums[1]) {
                return nums[0] * nums[1] + nums[1];
            } else {
                return nums[0] * nums[1] + nums[0];
            }
        } else if (nums.length == 3) {
            return nums[0] * nums[1] * nums[2] 
                    + maxCoins(new int[]{nums[0], nums[2]});
        } else {
            // find three largest ballons
            int[] big3 = {0, 1, 2}; // index of ballons
            for (int i = 3; i < nums.length; i++) {
                if (nums[i] >= nums[big3[2]] 
                    || nums[i] >= nums[big3[1]]
                    || nums[i] >= nums[big3[0]]) {
                    // replace the smallest ballon
                    if (nums[big3[0]] < nums[big3[1]] 
                        && nums[big3[0]] < nums[big3[2]]) {
                            big3[0] = big3[1];
                            big3[1] = big3[2];
                    } else if (nums[big3[1]] < nums[big3[0]] 
                        && nums[big3[1]] < nums[big3[2]]) {
                            big3[1] = big3[2];
                    }
                    big3[2] = i;
                }
            }
            int coins = 0;
            // pop ballons between these ballons
            if ((big3[0] + 1) != big3[1]) {
                coins += maxCoins(Arrays.copyOfRange(nums, big3[0], big3[1] + 1));
            }
            if (big3[1] + 1 != big3[2]) {
                coins += maxCoins(Arrays.copyOfRange(nums, big3[1], big3[2] + 1));
            }
            coins += maxCoins(new int[]{nums[big3[0]], nums[big3[1]], nums[big3[2]]});
            return coins;
        }
    }
}