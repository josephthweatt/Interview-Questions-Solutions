# Written by: Joseph Thweatt
# Runtime: 388 ms
# Given a non-empty array of integers, 
# return the k most frequent elements.
# Note: this algorithm seems to be behind
#       the speed of most other submissions

class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        elements = {}
        for x in nums:
            if not x in elements:
                elements[x] = 1
            else:
                elements[x] += 1

        print elements
        frequents = []        
        for y in elements:
            if not frequents:
                frequents = [y]
            else:
                for z in frequents:
                    if elements[y] > elements[z]:
                        frequents.insert(frequents.index(z),y)
                        break
                
                if not y in frequents:
                    frequents += [y]
            
        return frequents[:k]
            