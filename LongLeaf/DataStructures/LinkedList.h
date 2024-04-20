#pragma once
#include <iostream>

/*
	A singly linked list implementation in C++ using templates.

	The LinkedList class provides functionality for creating and manipulating
	singly linked lists of any data type. It supports operations such as insertion,
	removal, length retrieval, and display of elements in the list.

	This class can be used in situations where a dynamic data structure for
	maintaining a collection of elements is needed. It allows flexibility in
	storing and accessing elements, while also providing efficient insertion and
	removal operations. Additionally, the use of templates allows the LinkedList
	class to work with any data type.

	When using this class, it's important to note that manual memory management
	is required, as the LinkedList class uses raw pointers for node allocation
	and deallocation.
 */
template <typename T>
class LinkedList
{
private:
	// Node structure for each element in the linked list
	struct Node
	{
		T data;	 // Data stored in the node
		Node* next; // Pointer to the next node in the list
		// Constructor for the node
		// Parameters:
		//   value: The data to be stored in the node.
		Node(const T& value) : data(value), next(nullptr) {}
	};

	Node* head; // Pointer to the head of the list

public:
	// Constructor
	LinkedList() : head(nullptr) {}

	// Destructor
	~LinkedList()
	{
		// Delete all nodes to avoid memory leaks
		while (head != nullptr)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}

	// Function to check if the list is empty
	// Returns: true if the list is empty, false otherwise.
	bool isEmpty() const
	{
		return head == nullptr;
	}

	// Function to insert a node at the beginning of the list
	// Parameters:
	//   value: The data to be inserted.
	void insertAtBeginning(const T& value)
	{
		Node* newNode = new Node(value);
		newNode->next = head;
		head = newNode;
	}

	// Function to insert a node at the end of the list
	// Parameters:
	//   value: The data to be inserted.
	void insertAtEnd(const T& value)
	{
		// If the list is empty, inserting at the beginning would suffice
		if (isEmpty())
		{
			insertAtBeginning(value);
			return;
		}

		// Traverse to the end of the list and insert the new node
		Node* newNode = new Node(value);
		Node* current = head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = newNode;
	}

	// Function to insert a node at a specified position in the list
	// Parameters:
	//   value: The data to be inserted.
	//   position: The position at which the data should be inserted.
	// Exception: Prints error message if position is invalid or out of range.
	void insertAtPosition(const T& value, int position)
	{
		if (position < 0)
		{
			// Invalid position, print error message and return
			std::cerr << "Invalid position\n";
			return;
		}

		// If position is 0, insert at the beginning
		if (position == 0)
		{
			insertAtBeginning(value);
			return;
		}

		// Traverse to the node before the specified position
		Node* newNode = new Node(value);
		Node* current = head;
		for (int i = 0; i < position - 1 && current != nullptr; ++i)
		{
			current = current->next;
		}

		// If position is out of range, print error message and return
		if (current == nullptr)
		{
			std::cerr << "Position out of range\n";
			delete newNode;
			return;
		}

		// Insert the new node at the specified position
		newNode->next = current->next;
		current->next = newNode;
	}

	// Function to remove the first occurrence of a value from the list
	// Parameters:
	//   value: The value to be removed.
	// Exception: Prints error message if list is empty or value is not found.
	void remove(const T& value)
	{
		if (isEmpty())
		{
			// List is empty, print error message and return
			std::cerr << "List is empty\n";
			return;
		}

		// If the value to remove is at the head, remove the head node
		if (head->data == value)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
			return;
		}

		// Traverse the list to find the node with the value to remove
		Node* current = head;
		while (current->next != nullptr && current->next->data != value)
		{
			current = current->next;
		}

		// If value is not found, print error message and return
		if (current->next == nullptr)
		{
			std::cerr << "Value not found\n";
			return;
		}

		// Remove the node with the value
		Node* toDelete = current->next;
		current->next = current->next->next;
		delete toDelete;
	}

	// Function to remove a node at a specified position in the list
	// Parameters:
	//   position: The position of the node to be removed.
	// Exception: Prints error message if list is empty or position is invalid or out of range.
	void removeAtPosition(int position)
	{
		if (isEmpty())
		{
			// List is empty, print error message and return
			std::cerr << "List is empty\n";
			return;
		}

		if (position < 0)
		{
			// Invalid position, print error message and return
			std::cerr << "Invalid position\n";
			return;
		}

		// If position is 0, remove the head node
		if (position == 0)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
			return;
		}

		// Traverse to the node before the specified position
		Node* current = head;
		for (int i = 0; i < position - 1 && current != nullptr; ++i)
		{
			current = current->next;
		}

		// If position is out of range, print error message and return
		if (current == nullptr || current->next == nullptr)
		{
			std::cerr << "Position out of range\n";
			return;
		}

		// Remove the node at the specified position
		Node* toDelete = current->next;
		current->next = current->next->next;
		delete toDelete;
	}

	// Function to get the length of the list
	// Returns: The number of nodes in the list.
	int length() const
	{
		int len = 0;
		Node* current = head;
		while (current != nullptr)
		{
			len++;
			current = current->next;
		}
		return len;
	}

	// Function to display the list
	void display() const
	{
		Node* current = head;
		while (current != nullptr)
		{
			std::cout << current->data << " ";
			current = current->next;
		}
		std::cout << "\n";
	}

	// Function to convert the list to a string
	// Returns: A string representation of the list.
	char* toString() const
	{
		const int BUFFER_SIZE = 100; // Define a buffer size for the character array
		char* result = new char[BUFFER_SIZE]; // Allocate memory for the result
		result[0] = '\0'; // Initialize the result string as an empty string

		Node* current = head;
		while (current != nullptr)
		{
			char temp[BUFFER_SIZE] = { 0 }; // Temporary buffer for converting data to string
			_itoa_s(current->data, temp, BUFFER_SIZE, 10); // Convert data to string (assuming integers)
			strcat_s(result, BUFFER_SIZE, temp); // Concatenate temp to result
			strcat_s(result, BUFFER_SIZE, " "); // Add space between elements

			current = current->next;
		}

		return result; // Return the result string
	}
};
