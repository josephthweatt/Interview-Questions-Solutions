/**
 * Given two arrays, write a function to compute their intersection.
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var maxInt = 0;
var maxNum = function(num) {
    if (num > maxInt) {
        maxInt = num;
    }
}
 
var intersection = function(nums1, nums2) {
    result = [];
    if (nums1.length >= nums2.length) {
        bigArray = nums1;
        smallArray = nums2;
    } else {
        bigArray = nums2;
        smallArray = nums1;
    }
    
    bigMap = {};
    smallMap = {};
    
    // map the existence of the numbers
    for (var x = 0; x < bigArray.length; x++) {
        if (x < smallArray.length) {
            smallMap[smallArray[x]] = true;
            maxNum(smallArray[x]);
        }
        bigMap[bigArray[x]] = true;
        maxNum(bigArray[x]);
    }
    
    // see when a number exists for both arrays
    for (var y = 0; y <= maxInt; y++) {
        if (smallMap[y] && bigMap[y]) {
            result.push(y);
        }
    }
    return result;
};