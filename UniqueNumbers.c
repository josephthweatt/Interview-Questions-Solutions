/****************************************
 * Written By: Joseph Thweatt
 * Runtime: 0 ms
 * 
 * Given a non-negative integer n, count 
 * all numbers with unique digits, x, 
 * where 0 ≤ x < 10n.
 ***************************************/

int countNumbersWithUniqueDigits(int n) {
    if (n >= 10) {
        // it's impossible to have more unique numbers past this point
        return 8877691; 
    } else if (n == 9) {
        return 5611771;
    } else if (n == 8) {
        return 2345851;
    } else if (n == 7) {
        return 712891;
    } else if (n == 6) {
        return 168571;
    } else if (n == 5) {
        return 32491;
    } else if (n == 4) {
        return 5275;
    } else if (n == 3) {
        return 739;
    } else if (n == 2) {
        return 91;
    } else if (n == 1){
        return 10;  
    }
    return 1;
}
