package nextdlp.part2;

import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import org.junit.jupiter.api.Test;

public class BracketsTest {
	
	/*@Test
	void initTest() {
		System.out.println("bracketsListInitTest");
		for (Character c : Brackets.bracketFirsts()) {
			System.out.printf("%c & %c\n", c, Brackets.bracketPair(c));
		}
	}*/
	
	@Test
	void balancedTest_True() {
		String bracketsString = "{[(())]()}";
		assertTrue(Brackets.isBalanced(bracketsString));
	}

	@Test
	void balancedTest_False() {
		String bracketsString = "{[(()])()}";
		assertFalse(Brackets.isBalanced(bracketsString));
	}
	
	@Test
	void balancedTest_EmptyTrue() {
		String bracketsString = "";
		assertTrue(Brackets.isBalanced(bracketsString));
	}
	
	@Test
	void balancedTest_IgnoreOtherChars() {
		String bracketsString = "(hello)";
		assertTrue(Brackets.isBalanced(bracketsString));
	}
}
