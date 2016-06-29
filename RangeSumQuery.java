/**
* Written by: Joseph Thweatt
* Runtime: NA
*/

import java.util.HashMap;

public class RangeSumQuery {
    HashMap<Integer, Integer> map;
    
    public RangeSumQuery(int[] nums) {
        map = new HashMap<>();
        int sum = 0;
        for (int i = 0; i < nums.length; i++) {
            map.put(i, sum);
            sum += nums[i];
        }
        map.put(nums.length, sum);
    }

    public int sumRange(int i, int j) {
        return map.get(j + 1) - map.get(i);
    }
}


// Your NumArray object will be instantiated and called as such:
// NumArray numArray = new NumArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
