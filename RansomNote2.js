/**
 * Written by: Joseph Thweatt
 * Runtime: Unknown
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
        mag = magazine.split("");
        for (var x = 0; x < ransomNote.length; x++) {
            if (mag.indexOf(ransomNote[x]) != -1) {
                mag.splice(mag.indexOf(ransomNote[x]), 1)
            } else {
                return false;
            }
        }
        return true;
    }
};