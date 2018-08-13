/********************************************************
* Written by: Joseph Thweatt
* Runtime: 1 ms
*
* New iteration much faster and simpler than previous
* implementation
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
    List<List<Integer>> treeLevels = new ArrayList<>();
    
    public List<List<Integer>> levelOrder(TreeNode root) {
        addOnLevel(root, 0);
        
        return treeLevels;
    }
    
    public void addOnLevel(TreeNode root, int level) {
        if (root == null) return;
        
        // add root
        if (treeLevels.size() < level + 1) {
            treeLevels.add(new ArrayList<Integer>());
        }
        treeLevels.get(level).add(root.val);
        
        level++;
        addOnLevel(root.left, level);
        addOnLevel(root.right, level);
    }
}
