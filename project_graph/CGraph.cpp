#include<string>

#include"CGraph.h"
#include"LinkedList.h"

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
		graph.ISList(i, intList, list, visited, tmp);
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
		graph.ESList(i, extList, list, visited, tmp);
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

bool CGraph::vertexIsValid(int v)
{
	return (v >= 1 && v <= _vertexes);
}

bool CGraph::indexIsValid(int i)
{
	return (i >= 0 && i < _vertexes);
}

void clearString(std::string& str)
{
	while (str.find(",") != str.npos)
	{
		int i = 0;
		i = (unsigned)str.find(",");
		if (i >= 0 && i < str.length())
		{
			str.replace(i, 1, "");
		}
	}
	while (str.find(" ") != str.npos)
	{
		int i = 0;
		i = (unsigned)str.find(" ");
		if (i >= 0 && i < str.length())
		{
			str.replace(i, 1, "");
		}
	}
	while (str.find(":") != str.npos)
	{
		int i = 0;
		i = (unsigned)str.find(":");
		if (i >= 0 && i < str.length())
		{
			str.replace(i, 1, "");
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
	clearString(str);
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
	clearString(str);
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
	clearString(str);
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
		if (vertexIsValid(v) && (int)str[i + 1] - 49 >= 0 && (int)str[i + 1] - 49 < _vertexes)
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
	clearString(str);
	while (str.find("-1") != str.npos)
	{
		int i = 0;
		i = (unsigned)str.find("-1");
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
		if (indexIsValid(tmp1i) && indexIsValid(tmp2i))
		{
			_matrix[tmp1i][tmp2i] = 1;
		}
	}
	initISList();
	initESList();
	initKernelList();
}

LinkedList& CGraph::NeiboursList(LinkedList& list, int v)
{
	if (_matrix == nullptr || !vertexIsValid(v))
	{
		return list;
	}
	list.dispose();
	for (int i = 0; i < _vertexes; ++i)
	{
		if (_matrix[v - 1][i] > 0 || _matrix[i][v - 1] > 0)
		{
			list.pushtail(i + 1);
		}
	}
	return list;
}

LinkedList& CGraph::InputVertexesList(LinkedList& list, int v)
{
	if (_matrix == nullptr || _vertexes == 0 || !vertexIsValid(v))
	{
		list.dispose();
		return list;
	}
	list.dispose();
	for (int i = 0; i < _vertexes; ++i)
	{
		if (_matrix[i][v - 1] > 0)
		{
			list.pushtail(i + 1);
		}
	}
	return list;
}

LinkedList& CGraph::ISList(int v, LinkedList& currentList, LinkedList list, LinkedList& visited, LinkedList tmp)
{
	if (_matrix == nullptr || _vertexes == 0 || !vertexIsValid(v))
	{
		currentList.dispose();
		return currentList;
	}
	list.ExtractFirst(v);
	visited.pushtail(v);
	tmp.pushtail(v);

	LinkedList neibours;
	NeiboursList(neibours, v);
	list.ExtractList(neibours);
	visited.addList(neibours);

	for (int i = 0; i < list.length(); ++i)
	{
		ISList(list.getElem(i), currentList, list, visited, tmp);
	}
	if (list.isEmpty())
	{
		tmp.sort();
		if (!tmp.ListInOtherList(currentList))
		{
			currentList.pushTailList(tmp);
			currentList.pushtail(0);
		}
	}
	return currentList;
}

LinkedList& CGraph::ESList(int v, LinkedList& currentList, LinkedList list, LinkedList& visited, LinkedList tmp)
{
	if (_matrix == nullptr || _vertexes == 0 || !vertexIsValid(v))
	{
		currentList.dispose();
		return currentList;
	}
	list.ExtractFirst(v);
	visited.pushtail(v);
	tmp.pushtail(v);

	LinkedList inputs;
	InputVertexesList(inputs, v);
	list.ExtractList(inputs);
	visited.addList(inputs);

	for (int i = 0; i < list.length(); ++i)
	{
		ESList(list.getElem(i), currentList, list, visited, tmp);
	}
	if (list.isEmpty())
	{
		tmp.sort();
		if (!tmp.ListInOtherList(currentList))
		{
			currentList.pushTailList(tmp);
			currentList.pushtail(0);
		}
	}
	return currentList;
}
