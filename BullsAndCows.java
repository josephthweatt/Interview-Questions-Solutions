/**
 * Writen by: Joseph Thweatt
 * Runtime: N/A
 */
import java.util.HashMap;

public class BullsAndCows {
    //map holds all guess digits that aren't bulls
    HashMap<Integer, Integer> map = new HashMap<>();
    
       public String getHint(String secret, String guess) {
        int bull = 0;
        int cow = 0;
        boolean[] del = new boolean[secret.length()];
        for(int i = secret.length() - 1; i >= 0; i--) {
            if ((int) guess.charAt(i) == (int) secret.charAt(i)) {
                bull++;
                del[i] = true;
            } else {
                if (map.containsKey((int) guess.charAt(i)))
                    map.put((int) guess.charAt(i), map.get((int) guess.charAt(i))+1);
                else
                    map.put((int)guess.charAt(i), 1);
            }
        }
        for (int i = 0; i < guess.length(); i++) {
        	if (!del[i]) {
	            if (map.containsKey((int) secret.charAt(i))) {
	                map.put((int) secret.charAt(i), map.get((int) secret.charAt(i))-1);
	                cow++;
	                if (map.get((int) secret.charAt(i)) == 0){
	                    map.remove((int)secret.charAt(i));
	                }
	            }
        	}
        }
        return bull + "A" + cow + "B";
    }
}
