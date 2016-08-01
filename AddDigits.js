/*
 * Written by: Joseph Thweatt
 * Runtime: 308 ms
 * @param {number} num
 * @return {number}
 */
var addDigits = function(num) {
    nums = (num).toString(10).split("").map(function(t){return parseInt(t)})
    sum = nums.reduce(function(a, b) { return a + b}, 0)
    console.log(sum)
    if (sum >= 10) {
        return addDigits(sum)
    } else {
        return sum
    }
};
