#ifndef __LIST_H
#define __LIST_H
#include <memory>
#include <iostream>
#include <functional>

using namespace std;

template <class T>
class List {
public:
  class Node {
    friend class List<T>;
    T val;
    Node *next = NULL;
		Node(const T& val) {
			this->val = val;
		}
		Node(T&& t) { // &&t std::unique_ptr<T>& t)	
			val = std::move(t);
		}
  };
  Node *head = NULL;
private:
   
public:
  List() {
		// cout << "Create List!" << endl;
	}

  ~List() {
		// cout << "Destroy List!" << endl;
	}

  void insert(const T& v) {
		Node *new_head = new Node(v);
		if (head != NULL) {
			new_head->next = head;
		}
		head = new_head;	
  }

	void insert(T&& t) {
		Node *new_head = new Node(std::move(t));
		if (head != NULL) {
			new_head->next = head;
		}
		head = new_head;	
	}

  void append(const T& v) {
		Node *tail = new Node(v);
		if (head) {
			Node *cur = head;
			while(cur->next != NULL) {
				cur = cur->next;
			}
			cur->next = tail;
		} else {
			head = tail;
		}	
	}

	void append(T&& t) {
		Node *tail = new Node(std::move(t));
		if (head) {
			Node *cur = head;
			while(cur->next != NULL) {
				cur = cur->next;
			}
			cur->next = tail;
		} else {
			head = tail;
		}	
	}

  void forEach(std::function<void(const T&)> body) {
		Node *cur = head;
		while (cur != NULL) {
			body(cur->val);
			cur = cur->next;
		}
	}

	void forEach(std::function<void(std::unique_ptr<T>&)> body) {
		Node *cur = head;
		while (cur != NULL) {
			body(std::move(cur->val));
			cur = cur->next;
		}
	}
};

#endif
