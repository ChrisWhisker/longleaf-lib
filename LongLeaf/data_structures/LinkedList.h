#pragma once
#include <iostream>

namespace data_structures
{
	/*
		A singly linked list implementation in C++ using templates.

		The LinkedList class provides functionality for creating and manipulating
		singly linked lists of any p_data type. It supports operations such as insertion,
		removal, length retrieval, and display of elements in the list.

		This class can be used in situations where a dynamic p_data structure for
		maintaining a collection of elements is needed. It allows flexibility in
		storing and accessing elements, while also providing efficient insertion and
		removal operations. Additionally, the use of templates allows the LinkedList
		class to work with any p_data type.

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
			Node* p_next; // Pointer to the p_next node in the list
			// Constructor for the node
			// Parameters:
			//   value: The p_data to be stored in the node.
			Node(const T& value) : data(value), p_next(nullptr) {}
		};

		Node* p_head; // Pointer to the p_head of the list

	public:
		// Constructor
		LinkedList() : p_head(nullptr) {}

		// Destructor
		~LinkedList()
		{
			// Delete all nodes to avoid memory leaks
			while (p_head != nullptr)
			{
				const Node* p_temp = p_head;
				p_head = p_head->p_next;
				delete p_temp;
			}
		}

		// Check if the list is empty
		// Returns: true if the list is empty, false otherwise.
		bool is_empty() const
		{
			return p_head == nullptr;
		}

		// Insert a node at the beginning of the list
		// Parameters:
		//   value: The p_data to be inserted.
		void insert_at_beginning(const T& value)
		{
			Node* p_new_node = new Node(value);
			p_new_node->p_next = p_head;
			p_head = p_new_node;
		}

		// Insert a node at the end of the list
		// Parameters:
		//   value: The p_data to be inserted.
		void insert_at_end(const T& value)
		{
			// If the list is empty, inserting at the beginning would suffice
			if (is_empty())
			{
				insert_at_beginning(value);
				return;
			}

			// Traverse to the end of the list and insert the new node
			Node* p_new_node = new Node(value);
			Node* p_current = p_head;
			while (p_current->p_next != nullptr)
			{
				p_current = p_current->p_next;
			}
			p_current->p_next = p_new_node;
		}

		// Insert a node at a specified position in the list
		// Parameters:
		//   value: The p_data to be inserted.
		//   position: The position at which the p_data should be inserted.
		// Exception: Prints error message if position is invalid or out of range.
		void insert_at_position(const T& value, int position)
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
				insert_at_beginning(value);
				return;
			}

			// Traverse to the node before the specified position
			Node* p_new_node = new Node(value);
			Node* p_current = p_head;
			for (int i = 0; i < position - 1 && p_current != nullptr; ++i)
			{
				p_current = p_current->p_next;
			}

			// If position is out of range, print error message and return
			if (p_current == nullptr)
			{
				std::cerr << "Position out of range\n";
				delete p_new_node;
				return;
			}

			// Insert the new node at the specified position
			p_new_node->p_next = p_current->p_next;
			p_current->p_next = p_new_node;
		}

		// Remove the first occurrence of a value from the list
		// Parameters:
		//   value: The value to be removed.
		// Exception: Prints error message if list is empty or value is not found.
		void remove(const T& value)
		{
			if (is_empty())
			{
				// List is empty, print error message and return
				std::cerr << "List is empty\n";
				return;
			}

			// If the value to remove is at the p_head, remove the p_head node
			if (p_head->data == value)
			{
				const Node* p_temp = p_head;
				p_head = p_head->p_next;
				delete p_temp;
				return;
			}

			// Traverse the list to find the node with the value to remove
			Node* p_current = p_head;
			while (p_current->p_next != nullptr && p_current->p_next->data != value)
			{
				p_current = p_current->p_next;
			}

			// If value is not found, print error message and return
			if (p_current->p_next == nullptr)
			{
				std::cerr << "Value not found\n";
				return;
			}

			// Remove the node with the value
			const Node* p_to_delete = p_current->p_next;
			p_current->p_next = p_current->p_next->p_next;
			delete p_to_delete;
		}

		// Remove a node at a specified position in the list
		// Parameters:
		//   position: The position of the node to be removed.
		// Exception: Prints error message if list is empty or position is invalid or out of range.
		void remove_at_position(int position)
		{
			if (is_empty())
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

			// If position is 0, remove the p_head node
			if (position == 0)
			{
				const Node* p_temp = p_head;
				p_head = p_head->p_next;
				delete p_temp;
				return;
			}

			// Traverse to the node before the specified position
			Node* p_current = p_head;
			for (int i = 0; i < position - 1 && p_current != nullptr; ++i)
			{
				p_current = p_current->p_next;
			}

			// If position is out of range, print error message and return
			if (p_current == nullptr || p_current->p_next == nullptr)
			{
				std::cerr << "Position out of range\n";
				return;
			}

			// Remove the node at the specified position
			const Node* p_to_delete = p_current->p_next;
			p_current->p_next = p_current->p_next->p_next;
			delete p_to_delete;
		}

		// Get the length of the list
		// Returns: The number of nodes in the list.
		int length() const
		{
			int len = 0;
			Node* p_current = p_head;
			while (p_current != nullptr)
			{
				len++;
				p_current = p_current->p_next;
			}
			return len;
		}

		// Display the list
		void display() const
		{
			Node* p_current = p_head;
			while (p_current != nullptr)
			{
				std::cout << p_current->p_data << " ";
				p_current = p_current->p_next;
			}
			std::cout << "\n";
		}

		// Convert the list to a string
		// Returns: A string representation of the list.
		char* to_string() const
		{
			constexpr int BUFFER_SIZE = 100; // Define a buffer size for the character array
			char* p_result = new char[BUFFER_SIZE]; // Allocate memory for the result
			p_result[0] = '\0'; // Initialize the result string as an empty string

			Node* p_current = p_head;
			while (p_current != nullptr)
			{
				char temp[BUFFER_SIZE] = { 0 }; // Temporary buffer for converting p_data to string
				_itoa_s(p_current->data, temp, BUFFER_SIZE, 10); // Convert p_data to string (assuming integers)
				strcat_s(p_result, BUFFER_SIZE, temp); // Concatenate temp to result
				strcat_s(p_result, BUFFER_SIZE, " "); // Add space between elements

				p_current = p_current->p_next;
			}

			return p_result; // Return the result string
		}
	};
}
