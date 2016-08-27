#include "List.h"

List::List()
{
	head = NULL;
}

void List::insertNode(int i, int j)
{	
	Node* cur = head;
	Node* node = new Node;	
	if (head == NULL)
	{
		head = node;
		head->inputNode(i, j);
	}
	else
	{
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = node;
		node->prev = cur;
		node->inputNode(i, j);
	}
}

void List::displayAllNodes()
{
	cout << "No.\tLocation   Solution    Universe\n";
	cout << "----------------------------------------\n";

	Node*cur = head;
	int n = 1;
	while (cur != NULL)
	{
		cout << n << "\t";
		cout << " (" << cur->data.loc_i + 1 << ",";
		cout << cur->data.loc_j +1 << ")        ";
		cout << cur->data.solution << "        ";
		for (unsigned int i = 0; i < cur->data.curUniverse.size(); i++)
			cout << cur->data.curUniverse[i] << " ";
		cout << endl;
		cur = cur->next;
		n++;
	}
}

void List::deleteAllNodes()
{
	Node*cur = head;
	while (cur != NULL)
	{
		Node*next = cur->next;
		delete cur;
		cur = next;
	}
	head = NULL;
}
