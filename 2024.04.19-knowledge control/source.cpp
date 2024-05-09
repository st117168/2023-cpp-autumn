#include <iostream>

struct Node
{
	int data;
	Node* next;
	Node() : data(0), next(nullptr) {}
	Node(int data, Node* next = nullptr) : data(data), next(next) {}
	Node(const Node& node) : data(node.data), next(nullptr) {}
	Node(Node&& node) noexcept : data(node.data), next(node.next) 
	{
		node.data = 0;
		node.next = nullptr;
	}
	~Node() { data = 0; next = nullptr; }
	friend std::ostream& operator<<(std::ostream& stream, Node*& node)
	{
		stream << node->data;
		return stream;
	}
	//конструкторы(2), деструктор, оператор вывода
};

class LinkedList
{
public:
	LinkedList() : head(nullptr) {};
	LinkedList(int data) : head(new Node(data)) {};
	LinkedList(const LinkedList& list)
	{
		Node* tmp = list.head;
		while (tmp != nullptr)
		{
			Insert(Length(), tmp->data);
			tmp = tmp->next;
		}
	};
	LinkedList(LinkedList&& list) noexcept : head(list.head) { list.head = nullptr; };
	~LinkedList() 
	{
		while (head != nullptr)
		{
			Node* tmp = head;
			head = head->next;
			delete tmp;
		}
	};
	int Length();
	bool IsEmpty();
	void PushHead(int data);

	//вставляет элемент data на позицию index
	void Insert(int index, int data);
	void PushTail(int data);

	//извлекает головной элемент
	int PopHead();

	//извлекает данные из позиции index
	//и удаляет элемент из списка
	int Extract(int index);
	int PopTail();

	//получает данные из позиции index
	//без удаления из списка
	int Data(int index);
	void swap(int ia, int ib);
	void sort();
	friend std::ostream& operator<<(std::ostream& stream, const LinkedList& list)
	{
		if (list.head == nullptr)
		{
			stream << "list empty";
			return stream;
		}
		Node* tmp = list.head;
		while (tmp != nullptr)
		{
			stream << tmp << " ";
			tmp = tmp->next;
		}
		return stream;
	}
	//оператор вывода в поток
private:
	void dispose();

	//извлекает данные из ноды и удаляет саму ноду
	int PopData(Node* node); //!
	void InsertNode(int index, Node* node); //!
	Node* ExtractNode(int index); //!
	bool IndexValid(int index);
	Node* head;
};

int main(int argc, char* argv[])
{
	LinkedList list;
	std::cout << list << std::endl;
	list.PushHead(1);
	std::cout << list << std::endl;
	list.PushTail(3);
	std::cout << list << std::endl;
	list.Insert(1, 2);
	std::cout << list << std::endl;
	list.Insert(3, 4);
	std::cout << list << std::endl << std::endl;
	std::cout << list << std::endl;
	std::cout << list.PopHead() << " ";
	std::cout << list.Extract(1) << " ";
	std::cout << list.PopTail() << " ";
	std::cout << list.Extract(0) << std::endl;
	std::cout << list << std::endl << std::endl;

	list.PushHead(3); list.PushHead(4); list.PushHead(1); list.PushHead(2);
	list.PushHead(7); list.PushHead(5); list.PushHead(8); list.PushHead(6);
	std::cout << list << std::endl;
	list.sort();
	std::cout << list << std::endl;
	return EXIT_SUCCESS;
}

void LinkedList::dispose()
{
	while (head != nullptr)
	{
		Node* tmp = head;
		head = head->next;
		delete tmp;
	}
}

int LinkedList::PopData(Node* node)
{
	if (node == nullptr)
	{
		return -1;
	}
	int res = node->data;
	delete node;
	return res;
}

void LinkedList::InsertNode(int index, Node* node)
{
	if ((head == nullptr || !IndexValid(index)) && index != Length() && index != 0)
	{
		return;
	}
	if (index == 0)
	{
		if (head != nullptr)
		{
			node->next = head;
		}
		head = node;
		return;
	}
	if (index == Length())
	{
		Node* tmp = head;
		while (tmp->next != nullptr)
		{
			tmp = tmp->next;
		}
		tmp->next = node;
		return;
	}
	Node* tmp = head;
	while (index > 1)
	{
		tmp = tmp->next;
		--index;
	}
	node->next = tmp->next;
	tmp->next = node;
}

Node* LinkedList::ExtractNode(int index)
{
	if (!IndexValid(index) || head == nullptr)
	{
		return nullptr;
	}
	Node* tmp = head;
	if (index == 0)
	{
		Node* res = head;
		head = head->next;
		return res;
	}
	while (index > 1)
	{
		tmp = tmp->next;
		--index;
	}
	Node* res = tmp->next;
	tmp->next = tmp->next->next;
	return res;
}

bool LinkedList::IndexValid(int index)
{
	return (index >= 0 && index < Length());
}

int LinkedList::Length()
{
	int len = 0;
	Node* tmp = head;
	while (tmp != nullptr)
	{
		tmp = tmp->next;
		++len;
	}
	return len;
}

bool LinkedList::IsEmpty()
{
	return head == nullptr;
}

void LinkedList::PushHead(int data)
{
	Insert(0, data);
}

void LinkedList::Insert(int index, int data)
{
	if (!IndexValid(index) && index != Length())
	{
		return;
	}
	Node* node = new Node(data);
	InsertNode(index, node);
}

void LinkedList::PushTail(int data)
{
	Insert(Length(), data);
}

int LinkedList::PopHead()
{
	if (head == nullptr)
	{
		return -1;
	}
	Node* node = ExtractNode(0);
	return PopData(node);
}

int LinkedList::Extract(int index)
{
	if (!IndexValid(index) || head == nullptr)
	{
		return -1;
	}
	Node* node = ExtractNode(index);
	return PopData(node);
}

int LinkedList::PopTail()
{
	if (head == nullptr)
	{
		return -1;
	}
	Node* node = ExtractNode(Length() - 1);
	return PopData(node);
}

int LinkedList::Data(int index)
{
	if (!IndexValid(index) || head == nullptr)
	{
		return -1;
	}
	Node* tmp = head;
	while (index > 0)
	{
		tmp = tmp->next;
		--index;
	}
	return tmp->data;
}

void LinkedList::swap(int ia, int ib)
{
	if(head == nullptr || !IndexValid(ia) || !IndexValid(ib))
	{
		return;
	}
	if (ia > ib)
	{
		return swap(ib, ia);
	}
	Node* nodeb = ExtractNode(ib);
	Node* nodea = ExtractNode(ia);
	InsertNode(ia, nodeb);
	InsertNode(ib, nodea);
}

void LinkedList::sort()
{
	if (head == nullptr || Length() == 1)
	{
		return;
	}
	for (int i = 0; i < Length(); ++i)
	{
		for (int j = 0; j < Length() - 1 - i; ++j)
		{
			if (Data(j) > Data(j + 1))
			{
				swap(j, j + 1);
			}
		}
	}
}
