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
	LinkedList(const LinkedList& that);
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
	friend std::ostream& operator<<(std::ostream& stream, const LinkedList& list);
	LinkedList& operator=(LinkedList& other)
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
	void absorption(LinkedList& other);
	bool indexValid(int index);
	bool isEmpty() { return head == nullptr; };
	bool inList(int n);
	bool ListInOtherList(LinkedList& other, bool fullList = 1);
	int getElem(int index);
	int Extract(int data);
	int countElem(int data);
	LinkedList& NeiboursList(CGraph& graph, int v);
	LinkedList& InputVertexesList(CGraph& graph, int v);
	LinkedList& ISList(int v, CGraph& graph, LinkedList list, LinkedList& visited, LinkedList tmp);
	LinkedList& ESList(int v, CGraph& graph, LinkedList list, LinkedList& visited, LinkedList tmp);
};

class CGraph {
public:
	friend class LinkedList;
	CGraph();
	CGraph(int vertexes);
	CGraph(const CGraph& that);
	~CGraph();
	CGraph& operator=(CGraph& that);
	void ReadMatrix();
	void ReadEdges();
	void ReadAdjacences();
	void ReadIncidenceMatrix();
	void PrintMatrix();
	void printIntStabilityList();
	void printExtStabilityList();
	void printKernelList();
	int getISN();
	int getESN();

private:
	void initMatrix();
	void initISList();
	void initESList();
	void initKernelList();
	void disposeMatrix();
	void dispose();
	void doSymmetric();
	void doReflexive(bool t);
	void weightUnimportant();

	int _vertexes;
	int** _matrix;
	LinkedList _KernelList;
	LinkedList _IntStabList;
	LinkedList _ExtStabList;
};
