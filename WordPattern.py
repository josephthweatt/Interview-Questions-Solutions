"""
Written by: Joseph Thweatt
Runtime: NA
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
"""
import itertools

class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        words = str.split(' ')
        if len(pattern) != len(words):
            return False
        
        patternmap = {}
        index = 0
        for x in pattern:
            if x not in patternmap:
                patternmap[x] = index
            index += 1
        
        # make sure there are no duplicate starting words
        for index, x in enumerate(itertools.islice(patternmap, 0, len(patternmap) / 2)):
            for y in itertools.islice(patternmap, index + 1, len(patternmap)):
                if words[patternmap[x]] == words[patternmap[y]]:
                    return False
        
        # make sure all other words are according to pattern
        for x, y in zip(words, pattern):
            if x != words[patternmap[y]]:
                return False
        
        return True
