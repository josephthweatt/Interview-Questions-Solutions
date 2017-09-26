/**
 * Writen by: Joseph Thweatt
 * Runtime: Unknown
 *
 * Given  strings of brackets, determine whether each
 * sequence of brackets is balanced.
 */
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static boolean isBalanced(String expression) {
        Stack<Character> s = new Stack<Character>();
        for (char c : expression.toCharArray()) {
            if (c == '(' || c == '{' || c == '[') {
                s.push(c);
            } else if (!s.empty() &&
                        ((c == ')' && s.peek() == '(') ||
                        (c == '}' && s.peek() == '{') ||
                        (c == ']' && s.peek() == '['))) {
                s.pop();
            } else {
                return false;
            }
        }

        return s.empty();
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int a0 = 0; a0 < t; a0++) {
            String expression = in.next();
            System.out.println( (isBalanced(expression)) ? "YES" : "NO" );
        }
    }
}
