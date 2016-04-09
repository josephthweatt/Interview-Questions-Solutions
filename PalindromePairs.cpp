/******************************************************************
* Given a list of unique words. Find all pairs of distinct indices 
* (i, j) in the given list, so that the concatenation of the two 
* words, i.e. words[i] + words[j] is a palindrome.
*
* The program seems to work fine, but was not accepted becuase it 
* wasn't "fast enough" (even though it took 128 ms to process a 
* list of 500+ values). I'll come back to work on this problem 
* when I get experience with binary trees (that was their hint) 
*******************************************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> pair;
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> pairs;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++) {
                if (j == i) {
                    continue;
                } else {
                    if (isPalindrome(words.at(i), words.at(j))) {
                        pair.push_back(i);
                        pair.push_back(j);
                        pairs.push_back(pair);
                        pair.clear();
                    }
                }
            }
        }
        return pairs;
    }
    
    bool isPalindrome(string str1, string str2) {
        string newString = str1 + str2;
        string half1 = newString.substr(0, newString.length() / 2);
        string half2 = newString.substr(newString.length() / 2, newString.length() - 1);
        // half 1 == reverse of half 2
        for (int i = 0; i < half1.length(); i++) {
            if (half1.at(i) != half2.at(half2.length() - 1 - i)) {
                return false;
            }
        }
        return true;
    }
};
