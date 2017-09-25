/********************************************************
* Written by: Joseph Thweatt
* Runtime: Unknown
*
* Given the words in the magazine and the words in the
* ransom note, print Yes if he can replicate his ransom
* note exactly using whole words from the magazine;
* otherwise, print No.
*********************************************************/
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void viable(String[] magazine, String[] ransom) {

        if (ransom.length > magazine.length) {
            System.out.println("No");
        } else {
            Map<String, Integer> magazineMap = new HashMap<String, Integer>();
            Map<String, Integer> ransomMap = new HashMap<String, Integer>();

            for (String s : magazine) {
                Integer i = magazineMap.get(s);
                if (i != null) {
                    magazineMap.put(s, i + 1);
                } else {
                    magazineMap.put(s, 1);
                }
            }

            for (String s : ransom) {
                Integer i = magazineMap.get(s);

                if (i == null || i == 0) {
                    System.out.println("No");
                    return;
                } else {
                    magazineMap.put(s, i - 1);
                }
            }
            System.out.println("Yes");
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int m = in.nextInt();
        int n = in.nextInt();
        String magazine[] = new String[m];
        for(int magazine_i=0; magazine_i < m; magazine_i++){
            magazine[magazine_i] = in.next();
        }
        String ransom[] = new String[n];
        for(int ransom_i=0; ransom_i < n; ransom_i++){
            ransom[ransom_i] = in.next();
        }

        // my code is in 'viable'
        viable(magazine, ransom);
    }
}
