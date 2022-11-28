package nextdlp.part1;

public class MyDoublyLinkedList {
	
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
	
	public void addItem(int value) {
		ListItem newItem = new ListItem(value);
		addItem(newItem);
	}
	
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
	
	public void addItemStart(int value) {
		ListItem newItem = new ListItem(value);
		addItemStart(newItem);
	}
	
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
	
	public int getFirstValue() {
		if ( this.head == null )
			throw new NullPointerException("List is empty!");
		return this.head.value;
	}
	
	public int getLastValue() {
		if ( this.head == null )
			throw new NullPointerException("List is empty!");
		return this.tail.value;
	}
	
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
