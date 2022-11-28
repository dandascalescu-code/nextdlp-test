package nextdlp.part1;

import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;
import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import nextdlp.part1.MyDoublyLinkedList.ListItem;

public class MyDoublyLinkedListTest {
	MyDoublyLinkedList list;
	
	@BeforeEach
	void setUp() {
		list = new MyDoublyLinkedList();
	}
	
	@Test
	void whenQueryEmptyList_throwNullPointer() {
		assertThrows(NullPointerException.class, () -> {
			list.getFirstValue();
		});
		assertThrows(NullPointerException.class, () -> {
			list.getLastValue();
		});
	}
	
	@Test
	void whenQuerySingle_returnSameValue() {
		int value = 0;
		list.addItem(value);
		assertEquals(value, list.getFirstValue());
		assertEquals(value, list.getLastValue());
	}
	
	@Test
	void whenAddMultiple_allCorrect() {
		int value1 = 0;
		int value2 = 1;
		int value3 = 2;
		
		list.addItem(value1);
		assertEquals(value1, list.getFirstValue());
		assertEquals(value1, list.getLastValue());
		
		
		list.addItem(value2);
		assertEquals(value1, list.getFirstValue());
		assertEquals(value2, list.getLastValue());
		
		list.addItem(value3);
		assertEquals(value1, list.getFirstValue());
		assertEquals(value3, list.getLastValue());
	}
	
	@Test
	void whenAddMultipleStart_allCorrect() {
		int value1 = 0;
		int value2 = 1;
		int value3 = 2;
		
		list.addItemStart(value1);
		assertEquals(value1, list.getFirstValue());
		assertEquals(value1, list.getLastValue());
		
		
		list.addItemStart(value2);
		assertEquals(value2, list.getFirstValue());
		assertEquals(value1, list.getLastValue());
		
		list.addItemStart(value3);
		assertEquals(value3, list.getFirstValue());
		assertEquals(value1, list.getLastValue());
	}
	
	@Test
	void whenRemoveEmpty_returnFalse() {
		ListItem item = list.new ListItem(0);
		
		assertFalse(list.removeItem(item));
	}
	
	@Test
	void whenRemoveUnincluded_returnFalse() {
		ListItem item = list.new ListItem(0);
		list.addItem(0);
		list.addItem(1);
		list.addItem(2);
		
		assertFalse(list.removeItem(item));
	}
	
	@Test
	void whenRemoveItem_allCorrect() {
		int value1 = 0;
		int value2 = 1;
		int value3 = 2;
		ListItem item1 = list.new ListItem(value1);
		ListItem item2 = list.new ListItem(value2);
		ListItem item3 = list.new ListItem(value3);
		list.addItem(item1);
		list.addItem(item2);
		list.addItem(item3);
		
		assertTrue(list.removeItem(item3));
		assertEquals(value1, list.getFirstValue());
		assertEquals(value2, list.getLastValue());
		
		assertTrue(list.removeItem(item2));
		assertEquals(value1, list.getFirstValue());
		assertEquals(value1, list.getLastValue());
		
		assertTrue(list.removeItem(item1));
		assertThrows(NullPointerException.class, () -> {
			list.getFirstValue();
		});
		assertThrows(NullPointerException.class, () -> {
			list.getLastValue();
		});
	}
}
