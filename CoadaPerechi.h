#include <iostream>
#include <ostream>
#include <string.h>
#include <vector>
using namespace std;
//Declararea cozii ce utilizeaza o lista simplu inalantuita.
struct Node {
	pair<int,int> data;
	Node* link;

	Node* front = NULL, * rear = NULL;

	/*
		Returneaza lungimea cozii
	*/
	int getSize()
	{	
		int size = 0;
		Node* ptr = front;
		while (ptr != NULL)
		{
			size++;
			ptr = ptr->link;
		}
		return size;
	}

	bool isEmpty()
	{
		return (front == NULL and rear == NULL);
	}
	//Adauga un element in coada.
	void push(pair<int, int> value)
	{
		Node* ptr = new Node();
		ptr->data = value;
		ptr->link = NULL;
		if (front == NULL)
		{
			front = ptr;
			rear = ptr;
		}
		else {
			rear->link = ptr;
			rear = ptr;
		}
	}
	void displayQueue()
	{
		if (!isEmpty())
		{
			Node* ptr = front;
			while (ptr != NULL)
			{
				cout << "(" << ptr->data.first << "," << ptr->data.second << ") ";
				ptr = ptr->link;
			}
		}
	}
};
