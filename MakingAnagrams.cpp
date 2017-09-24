/******************************************************************
* Written by: Joseph Thweatt
* Runtime: Unknown
*
* Given two strings, a and b, that may or may not be of the same
* length, determine the minimum number of character deletions
* required to make a and b anagrams. Any characters can be deleted
* from either of the strings.
*
* Note: A big lesson learned here about iterating through cpp's
*       map. DO NOT erase map's pairs while iterating through it.
*       Iterators have a complicated internal behavior, and the
*       order in which it traverses maps & sets can get derailed
*       when data is removed.
******************************************************************/
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int number_needed(string a, string b) {
    int deletions = 0;

    // {character, occurences}
    map<char, int> a_m;
    map<char, int> b_m;

    // map string a
    for (char &c : a) {
        if (a_m.find(c) == a_m.end()) {
            a_m[c] = 1;
        } else {
            a_m[c]++;
        }
    }

    // map string b
    for (char &c : b) {
        if (b_m.find(c) == b_m.end()) {
            b_m[c] = 1;
        } else {
            b_m[c]++;
        }
    }

    // find similar characters between strings
    map<char, int>::iterator it;
    for(it = a_m.begin(); it != a_m.end(); it++) {
        char c = it->first;
        if (b_m.find(c) != b_m.end()) {
            deletions += std::abs(a_m[c] - b_m[c]);
            b_m.erase(c);
        } else {
            // 'c' is unique to string a
            deletions += a_m[c];
        }
    }

    // remaining keys in b_m are unique to string b
    for(it = b_m.begin(); it != b_m.end(); it++) {
        deletions += b_m[it->first];
    }

    return deletions;
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}
