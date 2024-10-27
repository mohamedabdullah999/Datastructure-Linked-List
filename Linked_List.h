#pragma once
#include <iostream>

using namespace std;

template <class T>
class Linked_List
{
private:
	struct Node {
		T data;
		Node* next;
		Node(T val):data(val),next(nullptr){}
    };
	long long size;
	Node* head;
	Node* tail;

	void get_tail() {
		Node* temp = head;
		while (temp) {
			temp = temp->next;
		}
		tail = temp;
	}
public:
	Linked_List():head(nullptr) , tail(nullptr) , size(0){}

	//push_front
	void push_front(T element) {
		Node* newnode = new Node(element);
		newnode->next = head;
		head = newnode;
		size++;
	}

	//push _back
	void push_back(T element) {
		Node* newnode = new Node(element);
		if (!head) {
			head = newnode;
			size++;
			return;
		}
		Node* cur = head;
		while (cur->next) {
			cur = cur->next;
		}
		cur->next = newnode;
		size++;
	}

	void insert(T element , int index) {
		if (index <= 0) {
			cout << "Cannot allocate memory......\n";
			return;
		}
		if (index == 1) {
			push_front(element);
			return;
		}
		
		if (index == size + 1) {
			push_back(element);
			return;
		}
		Node* newnode = new Node(element);
		
		if (head == nullptr) {
			head = newnode;
			return;
		}
		
		Node* cur = head;

		for (int i = 1; i < index - 1 ; i++) {
			cur = cur->next;
		}
	
		if (cur == nullptr) {
			cout << "out of renge.....\n";
			return;
		}
		
		newnode->next = cur->next;
		cur->next = newnode;
		
		size++;
	}

	void display() {
		Node* cur = head;
		if (cur == nullptr) {
			cout << "Empty Linked List...\n";
			return;
		}
		while (cur) {
			cout << cur->data << endl;
			cur = cur->next;
		}
	}

	void clear() {
		Node* current = head;
		while (current) {
			Node* temp = current->next;
			delete current;
			current = temp;
		}
		size = 0;
		head = nullptr;
	}

	long long getsize() {
		return size;
	}

	bool search(T item) {
		if (!head)return false;
		Node* current = head;
		while (current) {
			if (current->data == item) return true;
			current = current->next;
		}
		return false;
	}

	bool Empty() {
		return size == 0;
	}

	void pop_front() {
		if (!head) { 
			cout << "There isnnot any data to remove......\n";
			return;
		}
		Node* temp = head->next;
		delete head;
		head = temp;
		size--;
		if (Empty()) head = nullptr;
	}

	/*void pop_back() {
		if (size == 0) {
			cout << "cannot delete empty linked list\n"; 
			return;
		}

		Node* temp = head;
		while (temp->next) {
			temp = temp->next;
		}
		delete temp;
		size--;
		temp = head;

		for (int i = 1; i < size; i++) {
			temp = temp->next;
		}
		tail = temp;
		tail->next = nullptr;

		if (Empty()) head = tail = nullptr;
	}
	*/

	void Delete(int index) {
		if (Empty()) {
			cout << "Cannot delete any item from Linked List\n";
			return;
		}

		if (index == 1) {
			pop_front();
			return;
		}

		if (index == size) {
			pop_back();
			return;
		}

		Node* pointed_node = head;
		for (int i = 1; i < index - 1; i++) {
			pointed_node = pointed_node->next;
		}
		Node* node_to_delete = pointed_node->next;
		pointed_node->next = node_to_delete->next;
		delete node_to_delete;
		node_to_delete = nullptr;
		size--;
	}
	
	//another way to delete bck element 
	void pop_back() {
		if (Empty()) {
			cout << "Cannot delete any  element from this linked list\n";
			return;
		}

		if (size == 1) {
			delete head;
			head = nullptr;
			return;
		}

		Node* temp = head;
		while (temp->next->next) temp = temp->next;

		delete temp->next->next;
		temp->next = nullptr;
		tail = temp;
		size--;
	}
};

