/***********************************************
 * Written by: Joseph Thweatt
 * Runtime: 2ms
 * 
 * Given a board with m by n cells, each 
 * cell has an initial state live (1) or dead (0).
 * Each cell interacts with its eight neighbors 
 * (horizontal, vertical, diagonal) using the 
 * following four rules.
 ***********************************************/
class Solution {
    int m, n;
    int[][] originalBoard;
    
    public void gameOfLife(int[][] board) {
        originalBoard = board;
        m = board.length;
        n = board[0].length;
        
        int[][] newBoard = new int[m][n];
        for (int _m = 0; _m < m; _m++) {
            for (int _n = 0; _n < n; _n++) {
                newBoard[_m][_n] = applyRules(_m, _n, sweepOnes(_m, _n));
            }
        }
        
        for (int _m = 0; _m < m; _m++) {
            for (int _n = 0; _n < n; _n++) {
                originalBoard[_m][_n] = newBoard[_m][_n];
            }
        }
    }
    
    public int sweepOnes(int m, int n) {
        int ones = 0;
        int left = m - 1;
        int right = m + 1;
        int up = n - 1;
        int down = n + 1;
        
        boolean hasLeft = left >= 0;
        boolean hasRight = right < this.m;
        boolean hasUpper = up >= 0;
        boolean hasLower = down < this.n;
        
        if (hasLeft) {
            ones += originalBoard[left][n];
            ones += (hasUpper) ? originalBoard[left][up] : 0;
            ones += (hasLower) ? originalBoard[left][down] : 0;
        }
        
        if (hasRight) {
            ones += originalBoard[right][n];
            ones += (hasUpper) ? originalBoard[right][up] : 0;
            ones += (hasLower) ? originalBoard[right][down] : 0;
        }
        
        ones += (hasUpper) ? originalBoard[m][up] : 0;
        ones += (hasLower) ? originalBoard[m][down] : 0;
        return ones;
    }
    
    public int applyRules(int m, int n, int ones) {
        int result = originalBoard[m][n];
        
        if (ones < 2 || ones > 3) {
            result = 0;
        } else if (ones == 3) {
            result = 1;
        }
        return result;
    }
}
