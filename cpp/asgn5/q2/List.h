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
    int val;
		Node *next1 = NULL;
    std::unique_ptr<Node> next = NULL;
		//Node(const T& t) { // const T& t
		//	this->val = t; // this->val = val
		//}
		Node(int val) { // int val
			this->val = val;
		}
		void setNext(std::unique_ptr<Node>& z) {
			this->next = std::move(z);			
		}
  };
  std::unique_ptr<Node> head = NULL;
  Node *head1 = NULL;
private:
   
public:

	List() {
		std::cout << "make a list" << std::endl;
	}

  void insert1(int v) {
		//std::unique_ptr<T>& new_head(new Node(v));
		//if (head1 != NULL) {
		//	new_head->next1 = head1;
		//}
		//head1 = new_head;	
		Node *new_head = new Node(v);
		if (head1 != NULL) {
			new_head->next1 = head1;
		}
		head1 = new_head;
  }

	void insert(std::unique_ptr<int>& t) { // T& t
		std::unique_ptr<Node> new_head(new Node(*t));
		if (head != NULL) {
			(*new_head).setNext(head);
		}
		head = std::move(new_head);
	}

  void append1(const T& v) {
		Node *tail = new Node(v);
		if (head1) {
			Node *cur = head1;
			while(cur->next1 != NULL) {
				cur = cur->next1;
			}
			cur->next1 = tail;
		} else {
			head1 = tail;
		}	
	}

	void append(std::unique_ptr<int>& t) { // std::unique_ptr<int>& t)
		std::unique_ptr<Node> tail(new Node(*t));
		if (head) {
			Node *cur = head.get();
			while (cur->next != NULL) {
				cur = (cur->next.get());
			}
			cur->next = std::unique_ptr<Node>(new Node(*t));
		} else { 
			head = std::move(tail);
		}
	}

  void forEach1(std::function<void(const T&)> body) {
		Node *cur = head1;
		while (cur != NULL) {
			body(cur->val);
			cur = cur->next1;
		}
	}

	void forEach(function<void(const unique_ptr<int>&)> body) { //const unique_ptr<int>&
		Node *cur = head.get(); 
		while (cur != NULL) {
			std::unique_ptr<int> d(new int);
			*d = (*cur).val;
			body(d);
			cur = (cur->next.get());
		}
	}
};

#endif
