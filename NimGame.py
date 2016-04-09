class Solution(object):
    def canWinNim(self, n):
        """
        :type n: int
        :rtype: bool
        """
        # 4 is the base case. Whoever gets a 
        # turn with 4 stones is gauranteed to lose.
        # An amount of stones that is a multiple of 4
        # holds the same idea
        if (n % 4 == 0):
            return False
        return True
            
