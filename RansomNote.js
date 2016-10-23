/**
 * Written by: Joseph Thweatt
 * Runtime: 280 ms
 * 
 * Given an  arbitrary  ransom  note  string  and 
 * another  string  containing  letters from  all 
 * the  magazines,  write  a  function  that will
 * return  true  if  the  ransom   note  can  be 
 * constructed  from  the  magazines ;  otherwise,
 * it  will  return  false. 
 * 
 * Each  letter  in  the  magazine  string  can  only  be  used  once  in  your  ransom  note.
 * @param {string} ransomNote
 * @param {string} magazine
 * @return {boolean}
 */
var canConstruct = function(ransomNote, magazine) {
    if (ransomNote.length > magazine.length) {
        return false;
    } else {
        letter_count = {}
        mag_count = {}
        for (var x = 0; x < ransomNote.length; x++) {
            if (ransomNote[x] in letter_count) {
                letter_count[ransomNote[x]]++;
            } else {
                letter_count[ransomNote[x]] = 1;
            }
        }
        for (var x = 0; x < magazine.length; x++) {
            if (magazine[x] in mag_count) {
                mag_count[magazine[x]]++;
            } else {
                mag_count[magazine[x]] = 1;
            }
        }
        console.log(letter_count)
        console.log(mag_count)
        for (var x in letter_count) {
            if (!(x in mag_count)
                || mag_count[x] < letter_count[x]) {
                return false;
            }
        }
        return true;
    }
};