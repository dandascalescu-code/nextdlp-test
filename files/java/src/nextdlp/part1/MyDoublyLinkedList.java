package nextdlp.part1;

/**
 * MyDoublyLinkedList
 * @author Dan
 * An implementation of a doubly linked list, using no library components
 */
public class MyDoublyLinkedList {
	
	/**
	 * MyDoublyLinkedList.ListItem
	 * @author Dan
	 * An object representing an item in an instance of MyDoublyLinkedList
	 * containing its integer value, and references to the ListItems before and after in the list
	 */
	public class ListItem {
		public ListItem previous;
		public ListItem next;
		public int value;

		public ListItem(int value) {
			super();
			this.previous = null;
			this.next = null;
			this.value = value;
		}
	}
	
	private ListItem head;
	private ListItem tail;
	
	public MyDoublyLinkedList() {
		this.head = null;
		this.tail = null;
	}
	
	/**
	 * Adds item to end of list
	 * @param value, value of integer to be added
	 */
	public void addItem(int value) {
		ListItem newItem = new ListItem(value);
		addItem(newItem);
	}
	
	/**
	 * Adds item to end of list
	 * @param newItem, ListItem to append to list
	 */
	public void addItem(ListItem newItem) {
		if ( this.head == null ) {
			this.head = newItem;
			this.tail = newItem;
		} else {
			this.tail.next = newItem;
			newItem.previous = this.tail;
			this.tail = newItem;
		}
	}
	
	/**
	 * Adds item to start of list
	 * @param value, value of integer to be added
	 */
	public void addItemStart(int value) {
		ListItem newItem = new ListItem(value);
		addItemStart(newItem);
	}
	
	/**
	 * Adds item to start of list
	 * @param newItem, ListItem to append to list
	 */
	public void addItemStart(ListItem newItem) {
		if ( this.tail == null ) {
			this.tail = newItem;
			this.head = newItem;
		} else {
			this.head.previous = newItem;
			newItem.next = this.head;
			this.head = newItem;
		}
	}
	
	/**
	 * @return integer value at start of list
	 */
	public int getFirstValue() {
		if ( this.head == null )
			throw new NullPointerException("List is empty!");
		return this.head.value;
	}
	
	/**
	 * @return integer value at end of list
	 */
	public int getLastValue() {
		if ( this.head == null )
			throw new NullPointerException("List is empty!");
		return this.tail.value;
	}
	
	/**
	 * Removes referenced ListItem object from list, if present
	 * @param item, ListItem to remove
	 * @return true if element was removed successfully, false otherwise
	 */
	public boolean removeItem(ListItem item) {
		ListItem current = this.head;
		
		while ( current != null ) {
			if ( current.equals(item) ) {
				
				if ( current.previous != null && current.next != null ) {
					current.previous.next = current.next;
					current.next.previous = current.previous;
				} else if ( current.previous == null && current.next != null ) {
					current.next.previous = null;
					this.head = current.next;
				} else if ( current.next == null && current.previous != null ) {
					current.previous.next = null;
					this.tail = current.previous;
				} else {
					this.head = null;
					this.tail = null;
				}
				
				return true;
			}
			current = current.next;
		}
		
		return false;
	}
}
