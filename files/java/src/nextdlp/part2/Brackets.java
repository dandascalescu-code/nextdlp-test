package nextdlp.part2;

import java.util.Deque;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Map;
import java.util.Set;

/**
 * Brackets
 * @author Dan
 * Class containing static method isBalanced and required logic
 */
public class Brackets {
	/** String constant specification of brackets to include in logic calculations.
	 * Bracket pairs must be specified together, open before closing */
	private static final String BRACKETPAIRS_STRING = "(){}[]";
	
	/** Map constant, for easy access of bracket open/closing pairs */
	private static final Map<Character, Character> BRACKETPAIRS_MAP;
	
	/** Static block to put bracket pairs from BRACKETPAIRS_STRING into BRACKETPAIRS_MAP */
	static {
		BRACKETPAIRS_MAP = new HashMap<Character, Character>();
		for (int i = 0; i < BRACKETPAIRS_STRING.length(); i+=2) {
			BRACKETPAIRS_MAP.put(
					BRACKETPAIRS_STRING.charAt(i),
					BRACKETPAIRS_STRING.charAt(i+1)
			);
		}
	}
	
	/**
	 * @return the set of all bracket Characters, specified by BRACKETPAIRS_STRING
	 */
	private static Set<Character> allBrackets() {
		HashSet<Character> set = new HashSet<Character>();
		set.addAll(BRACKETPAIRS_MAP.keySet());
		set.addAll(BRACKETPAIRS_MAP.values());
		return set;
	}
	
	/**
	 * @return the set of all open bracket Characters, specified by BRACKETPAIRS_STRING, stored as keys of BRACKETPAIRS_MAP
	 */
	private static Set<Character> bracketFirsts() {
		return BRACKETPAIRS_MAP.keySet();
	}
	
	/**
	 * @param c, open bracket Character
	 * @return closing bracket Character corresponding to c
	 */
	private static Character bracketPair(Character c) {
		return BRACKETPAIRS_MAP.get(c);
	}
	
	/**
	 * Determines whether an input string's brackets are balanced
	 * @param bracketsString, input String to be parsed
	 * @return true if brackets are balanced, false otherwise
	 */
	public static boolean isBalanced(String bracketsString) {
		Deque<Character> queue = new LinkedList<Character>();
		
		for (Character c : bracketsString.toCharArray()) {
			if (!allBrackets().contains(c))
				continue;
			
			if (bracketFirsts().contains(c))
				queue.addFirst(c);
			else
				if (!queue.isEmpty() && bracketPair(queue.peekFirst()).equals(c) )
					queue.removeFirst();
				else
					return false;
		}
		
		return queue.isEmpty();
	}
}
