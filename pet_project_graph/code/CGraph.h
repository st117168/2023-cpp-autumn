#pragma once

#include"LinkedList.h"

class CGraph {
public:
	friend class LinkedList;
	CGraph()
		: _vertexes(0), _matrix(nullptr), _IntStabList(), _ExtStabList(), _KernelList() {}
	CGraph(int vertexes)
		: _vertexes(vertexes), _IntStabList(), _ExtStabList(), _KernelList()
	{
		initMatrix();
	}
	CGraph(const CGraph& that)
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
	~CGraph()
	{
		dispose();
	}
	CGraph& operator=(CGraph& that);
    std::string ReadMatrix(std::string& inputStr);
    std::string ReadEdges(std::string &inputStr);
    std::string ReadAdjacences(std::string &inputStr);
    std::string ReadIncidenceMatrix(std::string &inputStr);
    std::string GetEdgesList();
    std::string getIntStabilityList(bool word = 0);
    std::string getExtStabilityList(bool word = 0);
    std::string getKernelList(bool word = 0);
    std::string getMaxIntStList(bool word = 0);
    std::string getMinExtStList(bool word = 0);
	bool vertexIsValid(int v);
	bool indexIsValid(int i);
	int getISN();
	int getESN();
    int getEdgesCount();
    bool isEmpty();
    bool isConnected();
    void initStabilityLists();

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
    LinkedList NeiboursList(int v);
    LinkedList InputVertexesList(int v);
    void ISList(int v, LinkedList& currentList, LinkedList list, LinkedList tmp);
    void ESList(int v, LinkedList& currentList, LinkedList list, LinkedList tmp);

	int _vertexes;
	int** _matrix;
	LinkedList _IntStabList;
	LinkedList _ExtStabList;
    LinkedList _KernelList;
};
