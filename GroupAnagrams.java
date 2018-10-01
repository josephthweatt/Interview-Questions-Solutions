/*
 * Written by: Joseph Thweatt
 * Runtime: 19 ms
 * 
 * Given an array of strings, group anagrams together.
 */
import java.util.*;

public class GroupAnagrams {

	public List<List<String>> groupAnagrams(String[] strs) {
		Map<String, List<String>> letterSets = new HashMap<>();
		for (String s : strs) {
			char[] chars = s.toCharArray();
			Arrays.sort(chars);
			String letterSet = new String(chars);

			if (!letterSets.containsKey(letterSet)) {
				letterSets.put(letterSet, new ArrayList<>());
			}
			letterSets.get(letterSet).add(s);
		}

		return new ArrayList(letterSets.values());
	}

}

