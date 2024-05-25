#include <sstream>

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

std::string CGraph::GetEdgesList()
{
    if (_matrix == nullptr)
    {
        return "Graph empty";
    }
    std::ostringstream SS;
    SS << _vertexes << " " << getEdgesCount() << '\n';
    for (int i = 0; i < _vertexes; ++i)
    {
        for (int j = 0; j < _vertexes; ++j)
        {
            if (_matrix[i][j] != 0)
            {
                SS << i + 1 << " " << j + 1 << '\n';
            }
        }
    }
    std::string outputString;
    outputString = SS.str();
    return outputString;
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
    if (isEmpty())
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

int CGraph::getISN()
{
    if (_IntStabList.isEmpty())
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
    if (_ExtStabList.isEmpty())
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

int CGraph::getEdgesCount()
{
    if (_matrix == nullptr)
    {
        return 0;
    }
    int n = 0;
    for (int i = 0; i < _vertexes; ++i)
    {
        for (int j = 0; j < _vertexes; ++j)
        {
            if (_matrix[i][j] != 0)
            {
                n++;
            }
        }
    }
    return n;
}

void CGraph::initKernelList()
{
    if (_IntStabList.isEmpty() || _ExtStabList.isEmpty())
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
        if (i >= 0 && i < (int)str.length())
        {
            str.replace(i, 1, " ");
        }
    }
    while (str.find(":") != str.npos)
    {
        int i = 0;
        i = (unsigned)str.find(":");
        if (i >= 0 && i < (int)str.length())
        {
            str.replace(i, 1, " ");
        }
    }
    while (str.find("-1") != str.npos)
    {
        int i = 0;
        i = (unsigned)str.find("-1");
        if (i >= 0 && i < (int)str.length())
        {
            str.replace(i, 2, "2");
        }
    }
    while (str.find("  ") != str.npos)
    {
        int i = 0;
        i = (unsigned)str.find("  ");
        if (i >= 0 && i < (int)str.length())
        {
            str.replace(i, 1, "");
        }
    }
}

std::string CGraph::ReadMatrix(std::string& inputStr)
{
    dispose();
    clearString(inputStr);
    int n = 0;
    std::istringstream SS(inputStr);
    if (inputStr.empty() || !(SS >> n))
    {
        return "Ввод содержит символы или ввод пуст";
    }
    if (n <= 0 || n > 100)
    {
        return "Число вершин должно быть от 1 до 100";
    }
    _vertexes = n;
    initMatrix();
	for (int i = 0; i < _vertexes; ++i)
    {
        for (int j = 0; j < _vertexes; ++j)
        {
            if (SS >> n)
            {
                _matrix[i][j] = n;
            }
            else
            {
                dispose();
                return "Слишком мало элементов";
            }
        }
    }
    if (SS >> n)
    {
        dispose();
        return "Слишком много элементов";
    }
    return "Accepted";
}

std::string CGraph::ReadEdges(std::string& inputStr)
{
    dispose();
    clearString(inputStr);
    int vertexes = 0;
    int edges = 0;
    std::istringstream SS(inputStr);
    if (inputStr.empty() || !(SS >> vertexes))
    {
        return "Ввод содержит символы или ввод пуст";
    }
    SS >> edges;
    if (vertexes <= 0 || vertexes > 100 || edges < 0)
    {
        return "Число вершин должно быть от 1 до 100, число дуг от 0";
    }
    _vertexes = vertexes;
    initMatrix();
	int source = 0;
    int dest = 0;
    int counter = 0;
    while (SS >> source >> dest)
    {
        if (vertexIsValid(source) && vertexIsValid(dest))
        {
            _matrix[source - 1][dest - 1] = 1;
            counter++;
        }
        else
        {
            dispose();
            return "Одна из введенных дуг не может существовать";
        }
    }
    if (SS >> source || counter != edges)
    {
        dispose();
        return "Число дуг не совпадает с объявленным числом";
    }
    return "Accepted";
}

std::string CGraph::ReadAdjacences(std::string& inputStr)
{
    dispose();
    clearString(inputStr);
    int vertexes = 0;
    std::istringstream SS(inputStr);
    if (inputStr.empty() || !(SS >> vertexes))
    {
        return "Ввод содержит символы или ввод пуст";
    }
    if (vertexes <= 0 || vertexes > 100)
    {
        return "Число вершин должно быть от 1 до 100";
    }
    _vertexes = vertexes;
    initMatrix();
	int source = 0;
    int dest = 0;
    for (int i = 0; i < _vertexes; ++i)
    {
        if (SS >> source)
        {
            if (vertexIsValid(source))
            {
                std::string tmpLine;
                std::getline(SS, tmpLine);
                for (auto i = tmpLine.begin(); i != tmpLine.end(); i++)
                {
                    if (*i >= 48 && *i <= 57)
                    {
                        dest = *i - 48;
                        if (vertexIsValid(dest))
                        {
                            _matrix[source - 1][dest - 1] = 1;
                        }
                        else
                        {
                            dispose();
                            return "Одна из введенных дуг не может существовать";
                        }
                    }
                }
            }
            else
            {
                dispose();
                return "Одна из вершин введена неверно";
            }
        }
        else
        {
            dispose();
            return "Нужна информация про все вершины";
        }
    }
    if (SS >> source)
    {
        dispose();
        return "Слишком много элементов";
    }
    return "Accepted";
}

std::string CGraph::ReadIncidenceMatrix(std::string& inputStr)
{
    dispose();
    clearString(inputStr);
    int vertexes = 0;
    int edges = 0;
    std::istringstream SS(inputStr);
    if (inputStr.empty() || !(SS >> vertexes))
    {
        return "Ввод содержит символы или ввод пуст";
    }
    SS >> edges;
    if (vertexes <= 0 || vertexes > 100 || edges < 0)
    {
        return "Число вершин должно быть от 1 до 100, число дуг от 0";
    }
    _vertexes = vertexes;
    initMatrix();
    std::string string = "";
    int n = 0;
    while (SS >> n)
    {
        string += (char)n + 48;
    }
    if ((int)string.length() != vertexes * edges)
    {
        dispose();
        return "Число элементов матрицы не совпадает с объявленным";
    }
    for (int i = 0; i < edges; ++i)
    {
        int k = 0;
        std::string tmp1 = "0";
        while (tmp1 == "0" && i + k < (int)string.length() && i + k >= 0)
        {
            tmp1 = string[i + k];
            k += edges;
        }
        int tmp1i = k / edges - 1;
        std::string tmp2 = "0";
        while (tmp2 == "0" && i + k < (int)string.length() && i + k >= 0)
        {
            tmp2 = string[i + k];
            k += edges;
        }
        int tmp2i = k / edges - 1;
        if (tmp1 < tmp2)
        {
            std::swap(tmp1i, tmp2i);
        }
        if (indexIsValid(tmp1i) && indexIsValid(tmp2i))
        {
            _matrix[tmp1i][tmp2i] = 1;
        }
    }
    return "Accepted";
}

bool CGraph::isEmpty()
{
    return _matrix == nullptr;
}

bool CGraph::isConnected()
{
    if (_matrix == nullptr)
    {
        return false;
    }
    int counter =  0;
    for (int i = 0; i < _vertexes; ++i)
    {
        for (int j = 0; j < _vertexes; ++j)
        {
            if (_matrix[i][j] != 0 || _matrix[j][i] != 0)
            {
                counter++;
                break;
            }
        }
    }
    return counter == _vertexes;
}

void CGraph::initStabilityLists()
{
    initISList();
    initESList();
    initKernelList();
}

LinkedList CGraph::NeiboursList(int v)
{
    if (_matrix == nullptr || !vertexIsValid(v))
    {
        return LinkedList();
    }
    LinkedList list;
    for (int i = 0; i < _vertexes; ++i)
    {
        if (_matrix[v - 1][i] > 0 || _matrix[i][v - 1] > 0)
        {
            list.pushtail(i + 1);
        }
    }
    return list;
}

LinkedList CGraph::InputVertexesList(int v)
{
    if (_matrix == nullptr || _vertexes == 0 || !vertexIsValid(v))
    {
        return LinkedList();
    }
    LinkedList list;
    for (int i = 0; i < _vertexes; ++i)
    {
        if (_matrix[i][v - 1] > 0)
        {
            list.pushtail(i + 1);
        }
    }
    return list;
}

void CGraph::initISList()
{
    if (_matrix == nullptr || _vertexes == 0 || !isConnected())
    {
        return;
    }
    LinkedList list;
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
        graph.ISList(i, intList, list, tmp);
    }
    _IntStabList = intList;
}

void CGraph::initESList()
{
    if (_matrix == nullptr || _vertexes == 0 || !isConnected())
    {
        return;
    }
    LinkedList list;
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
        graph.ESList(i, extList, list, tmp);
    }
    list = extList;
    for (int i = 1; i <= list.countElem(0); ++i)
    {
        tmp.getSubset(list, i);
        extList.absorption(tmp);
    }
    _ExtStabList = extList;
}

void CGraph::ISList(int v, LinkedList& currentList, LinkedList list, LinkedList tmp)
{
    if (_matrix == nullptr || _vertexes == 0 || !vertexIsValid(v))
    {
        currentList.dispose();
        return;
    }
    list.ExtractFirst(v);
    tmp.pushtail(v);

    LinkedList neibours(NeiboursList(v));
    list.ExtractList(neibours);

    for (int i = 0; i < list.length(); ++i)
    {
        ISList(list.getElem(i), currentList, list, tmp);
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
    return;
}

void CGraph::ESList(int v, LinkedList& currentList, LinkedList list, LinkedList tmp)
{
    if (_matrix == nullptr || _vertexes == 0 || !vertexIsValid(v))
    {
        currentList.dispose();
        return;
    }
    list.ExtractFirst(v);
    tmp.pushtail(v);

    LinkedList inputs(InputVertexesList(v));
    list.ExtractList(inputs);

    for (int i = 0; i < list.length(); ++i)
    {
        ESList(list.getElem(i), currentList, list, tmp);
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
    return;
}

std::string CGraph::getIntStabilityList(bool word)
{
    if (_IntStabList.isEmpty())
    {
        return "Множество внутренней устойчивости пусто";
    }
    Node* tmp = _IntStabList.head;
    std::string outputStr = "";
    while (tmp != nullptr)
    {
        if (tmp->data == 0)
        {
            outputStr += "\n";
            tmp = tmp->next;
        }
        else
        {
            if (word)
            {
                char c = tmp->data + 64;
                outputStr += c;
                outputStr += " ";
                tmp = tmp->next;
            }
            else
            {
                outputStr += std::to_string(tmp->data) + " ";
                tmp = tmp->next;
            }
        }
    }
    return outputStr;
}

std::string CGraph::getExtStabilityList(bool word)
{
    if (_ExtStabList.isEmpty())
    {
        return "Множество внешней устойчивости пусто";
    }
    Node* tmp = _ExtStabList.head;
    std::string outputStr = "";
    while (tmp != nullptr)
    {
        if (tmp->data == 0)
        {
            outputStr += "\n";
            tmp = tmp->next;
        }
        else
        {
            if (word)
            {
                char c = tmp->data + 64;
                outputStr += c;
                outputStr += " ";
                tmp = tmp->next;
            }
            else
            {
                outputStr += std::to_string(tmp->data) + " ";
                tmp = tmp->next;
            }
        }
    }
    return outputStr;
}

std::string CGraph::getKernelList(bool word)
{
    if (_KernelList.isEmpty())
    {
        return "Ядро пусто";
    }
    Node* tmp = _KernelList.head;
    std::string outputStr = "";
    while (tmp != nullptr)
    {
        if (tmp->data == 0)
        {
            outputStr += "\n";
            tmp = tmp->next;
        }
        else
        {
            if (word)
            {
                char c = tmp->data + 64;
                outputStr += c;
                outputStr += " ";
                tmp = tmp->next;
            }
            else
            {
                outputStr += std::to_string(tmp->data) + " ";
                tmp = tmp->next;
            }
        }
    }
    return outputStr;
}

std::string CGraph::getMaxIntStList(bool word)
{
    if (_IntStabList.isEmpty())
    {
        return "Множество внутренней устойчивости пусто";
    }
    LinkedList MaxIntStList;
    MaxIntStList = _IntStabList.getSubsetByLength(getISN());
    std::string outputStr = "";
    Node* tmp = MaxIntStList.head;
    while (tmp != nullptr)
    {
        for (int i = 0; i < getISN(); ++i)
        {
            if (tmp == nullptr)
            {
                return outputStr;
            }
            if (word)
            {
                char c = tmp->data + 64;
                outputStr += c;
                outputStr += " ";
            }
            else
            {
                outputStr += std::to_string(tmp->data) + " ";
            }
            tmp = tmp->next;
        }
        outputStr += "\n";
    }
    return outputStr;
}

std::string CGraph::getMinExtStList(bool word)
{
    if (_IntStabList.isEmpty())
    {
        return "Множество внешней устойчивости пусто";
    }
    LinkedList MinExtStList;
    MinExtStList = _ExtStabList.getSubsetByLength(getESN());
    std::string outputStr = "";
    Node* tmp = MinExtStList.head;
    while (tmp != nullptr)
    {
        for (int i = 0; i < getESN(); ++i)
        {
            if (tmp == nullptr)
            {
                return outputStr;
            }
            if (word)
            {
                char c = tmp->data + 64;
                outputStr += c;
                outputStr += " ";
            }
            else
            {
                outputStr += std::to_string(tmp->data) + " ";
            }
            tmp = tmp->next;
        }
        outputStr += "\n";
    }
    return outputStr;
}
