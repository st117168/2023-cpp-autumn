#include<iostream>
#include<string>

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
	//записать в ReadMatrix и т.д
	void initISList();
	void initESList();
	void initKernelList();

private:
	void initMatrix();
	void disopseLists();
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

int main(int argc, char* argv[])
{
	CGraph g;
	g.ReadIncidenceMatrix();

	g.PrintMatrix();


	//std::cout << "----IntStabList-----" << std::endl;
	//g.printIntStabilityList();
	//std::cout << "IntStab Number: " << g.getISN() << std::endl;
	//std::cout << "----ExtStabList-----" << std::endl;
	//g.printExtStabilityList();
	//std::cout << "ExtStab Number: " << g.getESN() << std::endl;
	//std::cout << "----KernelList------" << std::endl;
	//g.printKernelList();

	return EXIT_SUCCESS;
}

CGraph::CGraph()
	: _vertexes(0), _matrix(nullptr), _IntStabList(), _ExtStabList(), _KernelList() {}

CGraph::CGraph(int vertexes)
	: _vertexes(vertexes), _IntStabList(), _ExtStabList(), _KernelList()
{
	initMatrix();
}

CGraph::CGraph(const CGraph& that)
	: _vertexes(that._vertexes)
{
	if (that._matrix != nullptr)
	{
		_matrix = new int* [_vertexes];
		for (int i = 0; i < _vertexes; ++i)
		{
			_matrix[i] = new int[_vertexes] { 0 };
		}
		for (int i = 0; i < _vertexes; ++i)
		{
			for (int j = 0; j < _vertexes; ++j)
			{
				_matrix[i][j] = that._matrix[i][j];
			}
		}
	}
	else
	{
		initMatrix();
	}
	if (that._IntStabList.head != nullptr)
	{
		_IntStabList.dispose();
		LinkedList tmpList(that._IntStabList);
		for (int i = 0; i < tmpList.length(); ++i)
		{
			_IntStabList.pushtail(tmpList.getElem(i));
		}
	}
	else
	{
		LinkedList _IntStabList;
	}
	if (that._ExtStabList.head != nullptr)
	{
		_ExtStabList.dispose();
		LinkedList tmpList(that._ExtStabList);
		for (int i = 0; i < tmpList.length(); ++i)
		{
			_ExtStabList.pushtail(tmpList.getElem(i));
		}
	}
	else
	{
		LinkedList _ExtStabList;
	}
	if (that._KernelList.head != nullptr)
	{
		_KernelList.dispose();
		LinkedList tmpList(that._KernelList);
		for (int i = 0; i < tmpList.length(); ++i)
		{
			_KernelList.pushtail(tmpList.getElem(i));
		}
	}
	else
	{
		LinkedList _KernelList;
	}
}

CGraph::~CGraph()
{
	dispose();
}

void CGraph::initMatrix()
{
	if (_vertexes == 0)
	{
		return;
	}
	_matrix = new int* [_vertexes];
	for (int i = 0; i < _vertexes; ++i)
	{
		_matrix[i] = new int[_vertexes] { 0 };
	}
}

void CGraph::dispose()
{
	disposeMatrix();
	_vertexes = 0;
}

void CGraph::disposeMatrix()
{
	if (_matrix != nullptr)
	{
		for (int i = 0; i < _vertexes; ++i)
		{
			delete[] _matrix[i];
		}
		delete[] _matrix;
		_matrix = nullptr;
	}
}

void CGraph::PrintMatrix()
{
	if (_matrix == nullptr)
	{
		std::cout << "Graph empty" << std::endl;
		return;
	}
	std::cout << std::endl;
	for (int i = 0; i < _vertexes; ++i)
	{
		for (int j = 0; j < _vertexes; ++j)
		{
			std::cout << _matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

CGraph& CGraph::operator=(CGraph& that)
{
	if (that._matrix != nullptr)
	{
		disposeMatrix();
		_vertexes = that._vertexes;
		_matrix = new int* [_vertexes];
		for (int i = 0; i < _vertexes; ++i)
		{
			_matrix[i] = new int[_vertexes] { 0 };
		}
		for (int i = 0; i < _vertexes; ++i)
		{
			for (int j = 0; j < _vertexes; ++j)
			{
				_matrix[i][j] = that._matrix[i][j];
			}
		}
	}
	else
	{
		initMatrix();
	}
	return *this;
}

void CGraph::doReflexive(bool t)
{
	if (_matrix == nullptr)
	{
		return;
	}
	for (int i = 0; i < _vertexes; ++i)
	{
		for (int j = 0; j < _vertexes; ++j)
		{
			if (i == j)
			{
				_matrix[i][j] = t;
			}
		}
	}
}

void CGraph::weightUnimportant()
{
	if (_matrix == nullptr || _vertexes == 0)
	{
		return;
	}
	for (int i = 0; i < _vertexes; ++i)
	{
		for (int j = 0; j < _vertexes; ++j)
		{
			if (_matrix[i][j] != 0)
			{
				_matrix[i][j] = 1;
			}
		}
	}
}

void CGraph::printIntStabilityList()
{
	if (_IntStabList.head == nullptr)
	{
		std::cout << "Internal stability set is empty" << std::endl;
		return;
	}
	Node* tmp = _IntStabList.head;
	while (tmp != nullptr)
	{
		if (tmp->data == 0)
		{
			std::cout << std::endl;
			tmp = tmp->next;
		}
		else
		{
			//std::cout << tmp->data << " ";
			//tmp = tmp->next;
			char c = tmp->data + 64;
			std::cout << c << " ";
			tmp = tmp->next;
		}
	}
}

void CGraph::printExtStabilityList()
{
	if (_ExtStabList.head == nullptr)
	{
		std::cout << "External stability set is empty" << std::endl;
		return;
	}
	Node* tmp = _ExtStabList.head;
	while (tmp != nullptr)
	{
		if (tmp->data == 0)
		{
			std::cout << std::endl;
			tmp = tmp->next;
		}
		else
		{
			//std::cout << tmp->data << " ";
			//tmp = tmp->next;
			char c = tmp->data + 64;
			std::cout << c << " ";
			tmp = tmp->next;
		}
	}
}

void CGraph::doSymmetric()
{
	if (_matrix == nullptr)
	{
		return;
	}
	for (int i = 0; i < _vertexes; ++i)
	{
		for (int j = 0; j < _vertexes; ++j)
		{
			if (_matrix[i][j] > 0)
			{
				_matrix[j][i] = _matrix[i][j];
			}
		}
	}
}

void CGraph::initISList()
{
	if (_matrix == nullptr || _vertexes == 0)
	{
		return;
	}
	LinkedList list;
	LinkedList visited;
	LinkedList tmp;
	LinkedList intList;
	CGraph graph(*this);
	graph.doReflexive(0);
	graph.doSymmetric();
	graph.weightUnimportant();
	for (int i = 1; i <= _vertexes; ++i)
	{
		list.pushtail(i);
	}
	for (int i = 1; i <= _vertexes; ++i)
	{
		intList.ISList(i, graph, list, visited, tmp);
	}
	_IntStabList = intList;
}

void CGraph::initESList()
{
	if (_matrix == nullptr || _vertexes == 0)
	{
		return;
	}
	LinkedList list;
	LinkedList visited;
	LinkedList tmp;
	LinkedList extList;
	CGraph graph(*this);
	graph.doReflexive(1);
	graph.weightUnimportant();
	for (int i = 1; i <= _vertexes; ++i)
	{
		list.pushtail(i);
	}
	for (int i = 1; i <= _vertexes; ++i)
	{
		extList.ESList(i, graph, list, visited, tmp);
	}
	// Поглощение
	list = extList;
	for (int i = 1; i <= list.countElem(0); ++i)
	{
		tmp.getSubset(list, i);
		extList.absorption(tmp);
	}
	_ExtStabList = extList;
}

LinkedList& LinkedList::NeiboursList(CGraph& graph, int v)
{
	if (graph._matrix == nullptr || v < 1 || v > graph._vertexes)
	{
		return *this;
	}
	dispose();
	for (int i = 0; i < graph._vertexes; ++i)
	{
		if (graph._matrix[v - 1][i] > 0 || graph._matrix[i][v - 1] > 0)
		{
			pushtail(i + 1);
		}
	}
	return *this;
}

LinkedList& LinkedList::InputVertexesList(CGraph& graph, int v)
{
	if (graph._matrix == nullptr || graph._vertexes == 0 || v > graph._vertexes || v < 1)
	{
		dispose();
		return *this;
	}
	dispose();
	for (int i = 0; i < graph._vertexes; ++i)
	{
		if (graph._matrix[i][v - 1] > 0)
		{
			pushtail(i + 1);
		}
	}
	return *this;
}

int LinkedList::getElem(int index)
{
	if (head == nullptr || !indexValid(index))
	{
		return -1;
	}
	Node* tmp = head;
	for (int i = 0; i < index; ++i)
	{
		tmp = tmp->next;
	}
	return tmp->data;
}

int LinkedList::poptail()
{
	if (isEmpty())
	{
		return -1;
	}
	if (head->next == nullptr)
	{
		return pophead();
	}
	Node* tmp = head;
	while (tmp->next->next != nullptr)
	{
		tmp = tmp->next;
	}
	int res = tmp->next->data;
	delete tmp->next;
	tmp->next = nullptr;
	return res;
}

int LinkedList::Extract(int index)
{
	if (index == 0)
	{
		return pophead();
	}
	if (index == length() - 1)
	{
		return poptail();
	}
	if (!indexValid(index))
	{
		return -1;
	}
	Node* tmp = head;
	for (int i = 0; i < index - 1; ++i)
	{
		tmp = tmp->next;
	}
	Node* nres = tmp->next;
	tmp->next = tmp->next->next;
	int res = nres->data;
	delete nres;
	return res;
}

void LinkedList::ExtractFirst(int d)
{
	if (head == nullptr)
	{
		return;
	}
	Node* tmp = head;
	int i = 0;
	while (tmp != nullptr)
	{
		if (tmp->data == d)
		{
			break;
		}
		tmp = tmp->next;
		i++;
	}
	if (tmp == nullptr)
	{
		return;
	}
	Extract(i);
}

void LinkedList::printList()
{
	if (head == nullptr)
	{
		std::cout << "list is empty" << std::endl;
		return;
	}
	Node* tmp = head;
	while (tmp != nullptr)
	{
		std::cout << tmp->data << " ";
		tmp = tmp->next;
	}
	std::cout << std::endl;
}

void LinkedList::ExtractList(LinkedList& list)
{
	if (list.head == nullptr || head == nullptr)
	{
		return;
	}
	Node* tmp = list.head;
	while (tmp != nullptr)
	{
		if (inList(tmp->data))
		{
			ExtractFirst(tmp->data);
		}
		tmp = tmp->next;
	}
}

LinkedList& LinkedList::ISList(int v, CGraph& graph, LinkedList list, LinkedList& visited, LinkedList tmp)
{
	if (graph._matrix == nullptr || graph._vertexes == 0 || v < 1 || v > graph._vertexes)
	{
		dispose();
		return *this;
	}
	list.ExtractFirst(v);
	visited.pushtail(v);
	tmp.pushtail(v);

	LinkedList neibours;
	neibours.NeiboursList(graph, v);
	list.ExtractList(neibours);
	visited.addList(neibours);

	for (int i = 0; i < list.length(); ++i)
	{
		ISList(list.getElem(i), graph, list, visited, tmp);
	}
	if (list.isEmpty())
	{
		tmp.sort();
		if (!tmp.ListInOtherList(*this))
		{
			pushTailList(tmp);
			pushtail(0);
		}
	}
	return *this;
}

LinkedList& LinkedList::ESList(int v, CGraph& graph, LinkedList list, LinkedList& visited, LinkedList tmp)
{
	if (graph._matrix == nullptr || graph._vertexes == 0 || v < 1 || v > graph._vertexes)
	{
		dispose();
		return *this;
	}
	list.ExtractFirst(v);
	visited.pushtail(v);
	tmp.pushtail(v);

	LinkedList inputs;
	inputs.InputVertexesList(graph, v);
	list.ExtractList(inputs);
	visited.addList(inputs);

	for (int i = 0; i < list.length(); ++i)
	{
		ESList(list.getElem(i), graph, list, visited, tmp);
	}
	if (list.isEmpty())
	{
		tmp.sort();
		if (!tmp.ListInOtherList(*this))
		{
			pushTailList(tmp);
			pushtail(0);
		}
	}
	return *this;
}

void LinkedList::sort()
{
	if (head == nullptr || length() == 1)
	{
		return;
	}
	for (int i = 0; i < length(); ++i)
	{
		for (int j = 0; j < length() - 1 - i; ++j)
		{
			if (getElem(j) > getElem(j + 1))
			{
				swap(j, j + 1);
			}
		}
	}
}

void LinkedList::swap(int ia, int ib)
{
	if (head == nullptr || !indexValid(ia) || !indexValid(ib))
	{
		return;
	}
	if (ia > ib)
	{
		return swap(ib, ia);
	}
	int data_b = Extract(ib);
	int data_a = Extract(ia);
	insert(ia, data_b);
	insert(ib, data_a);
}

void LinkedList::addList(LinkedList& add)
{
	if (add.head == nullptr)
	{
		return;
	}
	Node* tmp = add.head;
	while (tmp != nullptr)
	{
		if (!inList(tmp->data))
		{
			pushtail(tmp->data);
		}
		tmp = tmp->next;
	}
}

void LinkedList::dispose()
{
	while (!isEmpty())
	{
		pophead();
	}
}

LinkedList::LinkedList(const LinkedList& that) : head(nullptr)
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

void LinkedList::pushhead(int data)
{
	Node* newHead = new Node(data, head);
	head = newHead;
}

int LinkedList::pophead()
{
	if (head == nullptr)
	{
		return -1;
	}
	Node* tmp = head;
	head = head->next;
	int res = tmp->data;
	delete tmp;
	return res;
}

std::ostream& operator<<(std::ostream& stream, const LinkedList& list)
{
	Node* tmp = list.head;
	while (tmp != nullptr)
	{
		stream << tmp << " ";
		tmp = tmp->next;
	}
	return stream;
}

int LinkedList::length()
{
	Node* tmp = head;
	int len = 0;
	while (tmp != nullptr)
	{
		tmp = tmp->next;
		++len;
	}
	return len;
}

bool LinkedList::ListInOtherList(LinkedList& other, bool fullList)
{
	if (head == nullptr)
	{
		return true;
	}
	if (other.head == nullptr)
	{
		return false;
	}
	Node* main = other.head;
begin:
	Node* tmp = head;
	int tmpindex = 0;
	while (tmp != nullptr && main != nullptr)
	{
		if (main->data == 0)
		{
			main = main->next;
			goto begin;
		}
		else if (tmp->data == main->data)
		{
			tmp = tmp->next;
		}
		tmpindex++;
		main = main->next;
	}
	if (tmp == nullptr)
	{
		if (fullList == 1)
		{
			if (main != nullptr)
			{
				if (main->data == 0 && length() == tmpindex)
				{
					return true;
				}
				else
				{
					goto begin;
				}
			}
		}
		else
		{
			return true;
		}
	}
	return false;
}

void LinkedList::absorption(LinkedList& other)
{
	if (head == nullptr || other.head == nullptr)
	{
		return;
	}
	int index = 0;
	Node* main = head;
	while (other.ListInOtherList(*this, 0) && main != nullptr)
	{
		Node* tmp = other.head;
		int tmpindex = 0;
		while (tmp != nullptr && main != nullptr)
		{
			if (main->data == 0)
			{
				break;
			}
			if (tmp->data == main->data)
			{
				tmp = tmp->next;
			}
			main = main->next;
			index++;
			tmpindex++;
		}
		if (main != nullptr)
		{
			if (main->data == 0 && other.length() == tmpindex)
			{
				index++;
				tmpindex++;
				main = main->next;
				continue;
			}
			while (main->data != 0)
			{
				main = main->next;
				index++;
				tmpindex++;
				if (main == nullptr)
				{
					break;
				}
			}
			index++;
			tmpindex++;
			main = main->next;
		}
		if (tmp == nullptr)
		{
			int c = tmpindex;
			while (c != 0)
			{
				Extract(index - tmpindex);
				c--;
			}
			index -= tmpindex;
		}
	}
}

bool LinkedList::inList(int n)
{
	if (head == nullptr)
	{
		return false;
	}
	Node* tmp = head;
	while (tmp != nullptr)
	{
		if (tmp->data == n)
		{
			return true;
		}
		tmp = tmp->next;
	}
	return false;
}

bool LinkedList::indexValid(int index)
{
	return (0 <= index && index < length());
}

void LinkedList::pushtail(int data)
{
	if (isEmpty())
	{
		return pushhead(data);
	}
	Node* tmp = head;
	while (tmp->next != nullptr)
	{
		tmp = tmp->next;
	}
	tmp->next = new Node(data);
}

void LinkedList::insert(int index, int data)
{
	if (index == 0)
	{
		return pushhead(data);
	}
	if (index == length())
	{
		return pushtail(data);
	}
	if (indexValid(index))
	{
		Node* tmp = head;
		for (int i = 0; i < index - 1; ++i)
		{
			tmp = tmp->next;
		}
		tmp->next = new Node(data, tmp->next);
	}
}

int LinkedList::countElem(int data)
{
	if (head == nullptr)
	{
		return 0;
	}
	int count = 0;
	Node* tmp = head;
	while (tmp != nullptr)
	{
		if (tmp->data == data)
		{
			count++;
		}
		tmp = tmp->next;
	}
	return count;
}

void LinkedList::pushTailList(LinkedList& list)
{
	if (list.head == nullptr)
	{
		return;
	}
	Node* tmp = list.head;
	while (tmp != nullptr)
	{
		pushtail(tmp->data);
		tmp = tmp->next;
	}
}

int CGraph::getISN()
{
	if (_IntStabList.head == nullptr)
	{
		return 0;
	}
	int count = 0;
	int tmpCount = 0;
	Node* tmp = _IntStabList.head;
	while (tmp != nullptr)
	{
		if (tmp->data == 0)
		{
			count = (tmpCount > count ? tmpCount : count);
			tmpCount = 0;
		}
		else
		{
			tmpCount++;
		}
		tmp = tmp->next;
	}
	return count;
}

int CGraph::getESN()
{
	if (_ExtStabList.head == nullptr)
	{
		return 0;
	}
	int count = 0;
	int tmpCount = 0;
	Node* tmp = _ExtStabList.head;
	while (tmp != nullptr)
	{
		if (tmp->data == 0)
		{
			if (count == 0)
			{
				count = tmpCount;
			}
			else
			{
				count = (tmpCount < count ? tmpCount : count);
			}
			tmpCount = 0;
		}
		else
		{
			tmpCount++;
		}
		tmp = tmp->next;
	}
	return count;
}

void CGraph::initKernelList()
{
	if (_IntStabList.head == nullptr || _ExtStabList.head == nullptr)
	{
		return;
	}
	Node* tmp = _IntStabList.head;
	LinkedList tmpList;
	while (tmp != nullptr)
	{
		while (tmp->data != 0 && tmp->next != nullptr)
		{
			tmpList.pushtail(tmp->data);
			if (tmp->next != nullptr)
			{
				tmp = tmp->next;
			}
		}
		tmp = tmp->next;
		if (tmpList.ListInOtherList(_ExtStabList))
		{
			_KernelList.pushTailList(tmpList);
			_KernelList.pushtail(0);
		}
		tmpList.dispose();
	}
}

void CGraph::printKernelList()
{
	if (_KernelList.head == nullptr)
	{
		std::cout << "Kernel is empty" << std::endl;
		return;
	}
	Node* tmp = _KernelList.head;
	while (tmp != nullptr)
	{
		if (tmp->data == 0)
		{
			std::cout << std::endl;
			tmp = tmp->next;
		}
		else
		{
			//std::cout << tmp->data << " ";
			//tmp = tmp->next;
			char c = tmp->data + 64;
			std::cout << c << " ";
			tmp = tmp->next;
		}
	}
}

void LinkedList::getSubset(LinkedList& other, int n)
{
	if (other.head == nullptr || n < 1 || n > other.countElem(0))
	{
		return;
	}
	if (head != nullptr)
	{
		dispose();
	}
	Node* tmp = other.head;
	while (n != 1)
	{
		if (tmp != nullptr)
		{
			while (tmp->data != 0)
			{
				tmp = tmp->next;
				if (tmp == nullptr)
				{
					break;
				}
			}
		}
		if (tmp != nullptr)
		{
			tmp = tmp->next;
		}
		n--;
	}
	if (tmp != nullptr)
	{
		while (tmp->data != 0)
		{
			pushtail(tmp->data);
			tmp = tmp->next;
			if (tmp == nullptr)
			{
				return;
			}
		}
	}
}

void CGraph::ReadMatrix()
{
	dispose();
	int vertexes = 0;
	std::cin >> vertexes;
	if (vertexes <= 0 || vertexes > 100)
	{
		return;
	}
	_vertexes = vertexes;
	initMatrix();
	std::string str;
	while (vertexes + 1 != 0)
	{
		std::string tmp;
		getline(std::cin, tmp);
		str.append(tmp);
		vertexes--;
	}
	while (str.find(",") != str.npos)
	{
		int i = 0;
		i = str.find(",");
		if (i >= 0 && i < str.length())
		{
			str.replace(i, 1, "");
		}
	}
	while (str.find(" ") != str.npos)
	{
		int i = 0;
		i = str.find(" ");
		if (i >= 0 && i < str.length())
		{
			str.replace(i, 1, "");
		}
	}
	for (int i = 0; i < _vertexes; ++i)
	{
		for (int j = 0; j < _vertexes; ++j)
		{
			if (((i * _vertexes + j) >= 0) && ((i * _vertexes + j) < str.length()))
			{
				_matrix[i][j] = (int)str[i * _vertexes + j] - 48;
			}
		}
	}
	initISList();
	initESList();
	initKernelList();
}

void CGraph::ReadEdges()
{
	dispose();
	int vertexes = 0;
	int edges = 0;
	std::cin >> vertexes >> edges;
	if (vertexes <= 0 || edges <= 0 || vertexes > 100)
	{
		return;
	}
	_vertexes = vertexes;
	initMatrix();
	std::string str;
	while (edges + 1 != 0)
	{
		std::string tmp;
		getline(std::cin, tmp);
		str.append(tmp);
		edges--;
	}
	while (str.find(",") != str.npos)
	{
		int i = 0;
		i = str.find(",");
		if (i >= 0 && i < str.length())
		{
			str.replace(i, 1, "");
		}
	}
	while (str.find(" ") != str.npos)
	{
		int i = 0;
		i = str.find(" ");
		if (i >= 0 && i < str.length())
		{
			str.replace(i, 1, "");
		}
	}
	for (int i = 0; i < str.length(); i += 2)
	{
		int j = (int)str[i] - 48;
		int k = (int)str[i + 1] - 48;
		if ((j - 1 >= 0) && (j - 1 < _vertexes) && (k - 1 >= 0) && (k - 1 < _vertexes))
		{
			_matrix[j - 1][k - 1] = 1;
		}
	}
	initISList();
	initESList();
	initKernelList();
}

void CGraph::ReadAdjacences()
{
	dispose();
	int vertexes = 0;
	std::cin >> vertexes;
	if (vertexes <= 0 || vertexes > 100)
	{
		return;
	}
	_vertexes = vertexes;
	initMatrix();
	std::string str;
	while (vertexes + 1 != 0)
	{
		std::string tmp;
		getline(std::cin, tmp);
		str.append(tmp);
		str.append("0");
		vertexes--;
	}
	while (str.find(",") != str.npos)
	{
		int i = 0;
		i = str.find(",");
		if (i >= 0 && i < str.length())
		{
			str.replace(i, 1, "");
		}
	}
	while (str.find(" ") != str.npos)
	{
		int i = 0;
		i = str.find(" ");
		if (i >= 0 && i < str.length())
		{
			str.replace(i, 1, "");
		}
	}
	while (str.find(":") != str.npos)
	{
		int i = 0;
		i = str.find(":");
		if (i >= 0 && i < str.length())
		{
			str.replace(i, 1, "");
		}
	}
	int v = 0;
	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] == '0')
		{
			if ((i + 1) >= 0 && ((i + 1) < str.length()))
			{
				v = (int)str[i + 1] - 48;
				continue;
			}
			else
			{
				break;
			}
		}
		if (v > 0 && v <= _vertexes && (int)str[i + 1] - 49 >= 0 && (int)str[i + 1] - 49 < _vertexes)
		{
			_matrix[v - 1][(int)str[i + 1] - 49] = 1;
		}
	}
	initISList();
	initESList();
	initKernelList();
}

void CGraph::ReadIncidenceMatrix()
{
	dispose();
	int vertexes = 0;
	int edges = 0;
	std::cin >> vertexes >> edges;
	if (vertexes <= 0 || edges <= 0 || vertexes > 100)
	{
		return;
	}
	_vertexes = vertexes;
	initMatrix();
	std::string str;
	while (vertexes + 1 != 0)
	{
		std::string tmp;
		getline(std::cin, tmp);
		str.append(tmp);
		vertexes--;
	}
	while (str.find(",") != str.npos)
	{
		int i = 0;
		i = str.find(",");
		if (i >= 0 && i < str.length())
		{
			str.replace(i, 1, "");
		}
	}
	while (str.find(" ") != str.npos)
	{
		int i = 0;
		i = str.find(" ");
		if (i >= 0 && i < str.length())
		{
			str.replace(i, 1, "");
		}
	}
	while (str.find("-1") != str.npos)
	{
		int i = 0;
		i = str.find("-1");
		if (i >= 0 && i < str.length())
		{
			str.replace(i, 2, "2");
		}
	}
	for (int i = 0; i < edges; ++i)
	{
		int k = 0;
		std::string tmp1 = "0";
		while (tmp1 == "0" && i + k < str.length() && i + k >= 0)
		{
			tmp1 = str[i + k];
			k += edges;
		}
		int tmp1i = k / edges - 1;
		std::string tmp2 = "0";
		while (tmp2 == "0" && i + k < str.length() && i + k >= 0)
		{
			tmp2 = str[i + k];
			k += edges;
		}
		int tmp2i = k / edges - 1;
		if (tmp1 > tmp2)
		{
			std::swap(tmp1i, tmp2i);
		}
		if (tmp1i >= 0 && tmp1i < _vertexes && tmp2i >= 0 && tmp2i < _vertexes)
		{
			_matrix[tmp1i][tmp2i] = 1;
		}
	}
	initISList();
	initESList();
	initKernelList();
}