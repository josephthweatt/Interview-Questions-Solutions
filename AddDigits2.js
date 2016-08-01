/**
 * Written by: Joseph Thweatt
 * Runtime: 176 ms (an improvement from the first solution)
 * 
 * @param {number} num
 * @return {number}
 */
var addDigits = function(num) {
    if (!num) return 0
    return num % 9 || 9
};
