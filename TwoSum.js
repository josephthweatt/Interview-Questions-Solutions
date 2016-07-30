/**
 * Written By: Joseph Thweatt
 * Runtime: 304 ms (on average)
 *
 * Given an array of integers, return indices of the 
 * two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly
 * one solution.
 *
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    for (var x = 0; x < nums.length - 1; x++) {
        for (var y = x + 1; y < nums.length; y++) {
            if (nums[x] + nums[y] == target) {
                return [x, y]
            }
        }
    }
    return 0;
};
