/*
 *  Author: Joseph Thweatt
 *  Runtime 22 ms
 *
 * The string "PAYPALISHIRING" is written in 
 * a zigzag pattern on a given number of rows like this:
 *
 *  P   A   H   N
 *  A P L S I I G
 *  Y   I   R
 *
 * Write code that will take a strign and make this 
 * conversion given a number of rows
 */

class Solution {
    
public:

    string convert(string s, int numRows) {
        
        int lvl;
        int size = s.size();
        
        std::string finalStr = "";
        std::string levels[numRows];
        std::fill_n(levels, numRows, "");
        
        for (int i = 0; i < size; ) {
            
            lvl = 0;
            
            // zig
            do {
                
                levels[lvl] += s.at(i);
                lvl++;
                i++;
                
            } while (lvl < numRows && i < size);
            
            lvl -= 2;
            
            // zag
            while (lvl > 0 && i < size) {
                
                levels[lvl] += s.at(i);
                lvl--;
                i++;
            }
        }
        
        // concat all strings 
        for (int i = 0; i < numRows;finalStr += levels[i++]);
        
        return finalStr;
    }
};