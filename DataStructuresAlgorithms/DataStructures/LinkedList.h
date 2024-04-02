#pragma once

/**
 * @brief A singly linked list implementation in C++ using templates.
 *
 * The LinkedList class provides functionality for creating and manipulating
 * singly linked lists of any data type. It supports operations such as insertion,
 * removal, length retrieval, and display of elements in the list.
 *
 * This class can be used in situations where a dynamic data structure for
 * maintaining a collection of elements is needed. It allows flexibility in
 * storing and accessing elements, while also providing efficient insertion and
 * removal operations. Additionally, the use of templates allows the LinkedList
 * class to work with any data type.
 *
 * When using this class, it's important to note that manual memory management
 * is required, as the LinkedList class uses raw pointers for node allocation
 * and deallocation.
 */
template <typename T>
class LinkedList
{
private:
	// Node structure for each element in the linked list
	struct Node
	{
		T data;
		Node* next;
		// Constructor for the node
		Node(const T& value) : data(value), next(nullptr) {}
	};

	Node* head; // Pointer to the head of the list

public:
	// Constructor
	LinkedList();

	// Destructor
	~LinkedList();

	// Function to check if the list is empty
	bool isEmpty() const;

	// Function to insert a node at the beginning of the list
	void insertAtBeginning(const T& value);

	// Function to insert a node at the end of the list
	void insertAtEnd(const T& value);

	// Function to insert a node at a specified position in the list
	void insertAtPosition(const T& value, int position);

	// Function to remove the first occurrence of a value from the list
	void remove(const T& value);

	// Function to remove a node at a specified position in the list
	void removeAtPosition(int position);

	// Function to get the length of the list
	int length() const;

	// Function to display the list
	void display() const;
};
