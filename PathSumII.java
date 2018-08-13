/********************************************************
* Written by: Joseph Thweatt
* Runtime: 2 ms
*
* Given a binary tree and a sum, find all root-to-leaf 
* paths where each path's sum equals the given sum.
*
* Runtime was origionally 5 ms, but the discussion showed
* me I could reduce time if I removed the last element
* from the list when I wasn't on a leaf node. I was
* initially creating copies of the array as I traversed.
*********************************************************/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
import java.util.Stack;

class Solution {
    List<List<Integer>> paths = new ArrayList<>();
    int finalSum = 0;
    
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        finalSum = sum;
        findPaths(root, new ArrayList<Integer>(), 0);
        return paths;
    }
    
    public void findPaths(TreeNode root, List<Integer> list, int sum) {
        if (root == null) return;
        
        list.add(root.val);
        
        findPaths(root.left, list, sum + root.val);
        findPaths(root.right, list, sum + root.val);

        if (root.left == null && root.right == null && sum + root.val == finalSum) {
            paths.add(new ArrayList(list));
        }
        
        list.remove(list.size() - 1);
    }
}
