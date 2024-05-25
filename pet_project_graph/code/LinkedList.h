#pragma once

#include<iostream>

struct Node {
	int data;
	Node* next;
	Node(int data, Node* next = nullptr) : data(data), next(next) {}
	Node(const Node& node) : data(node.data), next(nullptr) {}
	~Node() { data = 0; next = nullptr; }
	friend std::ostream& operator<<(std::ostream& stream, Node*& node)
	{
		stream << node->data;
		return stream;
	}
};

class LinkedList {
public:
	friend class CGraph;
	LinkedList() : head(nullptr) {}
	LinkedList(const LinkedList& that) : head(nullptr)
	{
		if (that.head == nullptr)
		{
			return;
		}
		Node* tmp = that.head;
		while (tmp != nullptr)
		{
			pushtail(tmp->data);
			tmp = tmp->next;
		}
	}
	~LinkedList() { dispose(); }
	void pushhead(int data);
	void pushtail(int data);
    void pushTailList(LinkedList& list);
    void addList(LinkedList& add);
	void sort();
	void printList();
	int pophead();
	int poptail();
	int length();
    bool isEmpty() { return head == nullptr; }
    friend std::ostream& operator<<(std::ostream& stream, const LinkedList& list)
	{
		Node* tmp = list.head;
		while (tmp != nullptr)
		{
			stream << tmp << " ";
			tmp = tmp->next;
		}
		return stream;
	}
    LinkedList& operator=(LinkedList other)
	{
		if (other.head == nullptr)
		{
			return *this;
		}
		if (head != nullptr)
		{
			dispose();
		}
		Node* tmp = other.head;
		while (tmp != nullptr)
		{
			pushtail(tmp->data);
			tmp = tmp->next;
		}
		return *this;
	}
private:
	Node* head;
	void dispose();
	void insert(int index, int data);
	void ExtractFirst(int d);
    void ExtractList(LinkedList& list);
	void swap(int ia, int ib);
    void getSubset(LinkedList& other, int n);
    LinkedList getSubsetByLength(int length);
    void absorption(LinkedList& other);
	bool indexValid(int index);
	bool inList(int n);
    bool ListInOtherList(LinkedList& other, bool fullList = 1);
	int getElem(int index);
	int Extract(int data);
	int countElem(int data);
};
