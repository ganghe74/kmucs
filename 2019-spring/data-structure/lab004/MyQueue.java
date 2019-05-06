import java.util.*;

/**
 * Generic version of the MyQueue class.
 * @param <T> the type of the value being queued
 */

class MyQueue <T> {
	private T[] queue;	// array for queue elements
	private int front, // one counterclockwise from front
	            rear, 	// array position of rear element
				capacity;	// capacity of queue array

	/**
	 * Create an empty queue whose initial capacity is cap
	 */
	@SuppressWarnings("unchecked")
	MyQueue(int cap) {
		capacity = cap;
		queue = (T []) new Object [capacity];
		front = rear = 0;
	}

	boolean IsEmpty() {
		return front == rear;
	}

	void Push (T x) throws Exception { 
		if (front == (rear+1)%capacity)
			throw new Exception ("Queue is Full");
		rear = (rear + 1) % capacity;
		queue[rear] = x;
	}

	T Pop() throws Exception {
		if (IsEmpty())
			throw new Exception("Queue is empty. Cannot delete.");
		front = (front + 1) % capacity;
		return queue[front];
	}
	
	public String toString() {
		String a = new String();
		a = "Queue : ";
	
		if (rear != front) {
			int i = (front + 1) % capacity;
			while (true) {
				a += queue[i] + " ";
				if (i == rear) break;
				i = (i + 1) % capacity;
			}
		}
		

		a += "\nrear=" + rear + ", front=" + front;
		return a;
	}
}; 


