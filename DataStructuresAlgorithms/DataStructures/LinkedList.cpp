#include "LinkedList.h"
#include <iostream>

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr) {}

template <typename T>
LinkedList<T>::~LinkedList()
{
	// Delete all nodes to avoid memory leaks
	while (head != nullptr)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return head == nullptr;
}

template <typename T>
void LinkedList<T>::insertAtBeginning(const T& value)
{
	Node* newNode = new Node(value);
	newNode->next = head;
	head = newNode;
}

template <typename T>
void LinkedList<T>::insertAtEnd(const T& value)
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

template <typename T>
void LinkedList<T>::insertAtPosition(const T& value, int position)
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

template <typename T>
void LinkedList<T>::remove(const T& value)
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

template <typename T>
void LinkedList<T>::removeAtPosition(int position)
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

template <typename T>
int LinkedList<T>::length() const
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

template <typename T>
void LinkedList<T>::display() const
{
	Node* current = head;
	while (current != nullptr)
	{
		std::cout << current->data << " ";
		current = current->next;
	}
	std::cout << std::endl;
}