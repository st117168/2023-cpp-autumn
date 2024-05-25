#include"LinkedList.h"

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
	return;
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