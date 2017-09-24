/**
 * Written By: Joseph Thweatt
 * Runtime: 9 ms
 *
 * Implement atoi to convert a string to an integer.
 */
#include <iostream>

class Solution {

    public:

        int myAtoi(string str) {
			bool isNum = false;
			bool isNeg = false;
			int start = 0;
			int end = 0;
			int number = 0;

			while (start < str.size() && !isNum) {
			    char c = str.at(start);
				if (c == '-') {
					isNum = true;
					isNeg = true;
				} else if (std::isdigit(c)) {
					isNum = true;
				} else if (c == '+') {
				    start++;
				    isNum = true;
				} else if  (c != ' ') {
				    start = str.size(); // jump to end
				} else {
					start++;
				}
			}

			if (isNeg) {
			    end = start + 1;
			} else {
    			end = start;
			}

			while (end < str.size() && isNum) {

			    if (!std::isdigit(str.at(end))) {
			        isNum = false;
			    } else {
			        end++;
			    }
			}

			if (end <= str.size() && start != end) {
			    str = str.substr(start, end);

				const char *strChar = str.c_str();
				number = std::atoi(strChar);

				if (isNeg && (number > 0 || end - start > 11)) {
					number = INT_MIN;
				} else if (!isNeg && (number < 0  || end - start > 10)) {
					number = INT_MAX;
				}
			}

			return number;
		}

};
