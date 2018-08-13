/********************************************************
* Written by: Joseph Thweatt
* Runtime: 5 ms
*
* Given a binary tree, return the level order traversal 
* of its nodes' values. (ie, from left to right, 
* level by level).
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
import java.util.ArrayList;

class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> treeLevels = new ArrayList<>();
        
        // add root
        if (root == null) {
            return treeLevels;
        }
        treeLevels.add(new ArrayList<Integer>());
        treeLevels.get(0).add(root.val);
        
        // add leaf nodes
        List<List<Integer>> left = levelOrder(root.left);
        List<List<Integer>> right = levelOrder(root.right);
        
        if (left.size() > 0 && right.size() > 0) {
            List<List<Integer>> combined = combineLevels(left, right);
            treeLevels.addAll(combined);
        } else if (left.size() > 0) {
            treeLevels.addAll(left);
        } else if (right.size() > 0) {
            treeLevels.addAll(right);
        }
        
        return treeLevels;
    }
    
    public List<List<Integer>> combineLevels(List<List<Integer>> left, List<List<Integer>> right) {
        List<List<Integer>> combined = new ArrayList<>();
        
        int i = 0;
        while (i < left.size() && i < right.size()) {
            List<Integer> level = left.get(i);
            level.addAll(right.get(i));
            combined.add(level);
            i++;
        }
        
        if (left.size() != right.size()) {
            List<List<Integer>> longer = (left.size() > i) ? left : right;
            combined.addAll(longer.subList(i, longer.size()));
        }
        return combined;
    }
}
