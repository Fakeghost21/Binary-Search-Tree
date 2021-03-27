#include<iostream>
#include <vector>
#include <string>
#include <fstream>
#include "CoadaPerechi.h"
using namespace std;
/*
	Declara datele unui nod din arbore
*/
struct BstNode {
	int key;
	Node data;
	BstNode* left;
	BstNode* right;
};

/*
	Creeaza un nou nod
*/
BstNode* GetNewNode(pair<int,int> p) {
	BstNode* newNode = new BstNode();
	newNode->data.push(p);
	newNode->left = newNode->right = 0;
	newNode->key = p.first + p.second;
	return newNode;
}

/*
	Insereaza un nod in arborele binar de cautare dupa valoarea cheii din nod
*/
BstNode* Insert(BstNode* root, pair<int,int> data) {

	if (root == 0) { 
		root = GetNewNode(data);
	}

	else if (data.first + data.second == root->key)
	{
		root->data.push(data);
	}

	else if (data.first + data.second < root->key) {
		root->left = Insert(root->left, data);
	}

	else {
		root->right = Insert(root->right, data);
	}

	return root;
}
/*
	Parcurge arborele in inordine,afisand totodata
*/
void Inorder(BstNode* root) {

	if (root == 0) return;

	Inorder(root->left);       
	if (root->data.getSize() >= 2)
	{
		cout << "Perechile : ";
		root->data.displayQueue();
		cout << "au suma " << root->key << endl;
	}

	Inorder(root->right);     

}

void creeazaArborele(int* v,int n)
{	
	BstNode* root = 0;
	for(int i = 0;i<n - 1;i++)
		for (int j = i + 1; j < n; j++)
		{
			pair <int, int> p = make_pair(v[i], v[j]);
			root = Insert(root,p);
		}
	Inorder(root);
}

/*
	Dubleaza capacitatea de memorie a unui array
*/
void res(int capacity,int *& vOld) {
	size_t newSize = capacity * 2;
	int* newArray = new int[newSize];

	for (int i = 0; i < capacity; i++)
		newArray[i] = vOld[i];
	capacity = newSize;
	delete[] vOld;
	vOld = newArray;
}

/*
	Verifica existenta unei valori intr-un array
*/
bool exista(int* v, int n,int nr)
{
	for (int i = 0; i < n; i++)
		if (v[i] == nr)
			return true;
	return false;

}

/*
	Tranforma un string de numere intregi despartite prin spatiu intr-un vector de intregi unici
*/
void conversieVector(string s,int*& v,int &n)
{
	int i = 0;
	string delim = " ";
	int pos = 0, nr = 0,length;
	pos = s.find(delim);
	int capacity = stoi(s.substr(0, pos));
	v = new int[capacity];
	s = s.erase(0, pos + 1);
	while (pos != string::npos)
	{
		pos = s.find(delim);
		nr = stoi(s.substr(0, pos));
		if (!exista(v, n, nr))
		{
			if (n == capacity - 1)
			{
				res(capacity, v);
				capacity *= 2;
			}
			v[n] = nr;
			n++;
		}
		s = s.erase(0, pos + 1);
	}
}

void app()
{
	ifstream f("Datele.txt");
	if (f.is_open())
	{
		string line;
		int n;
		getline(f, line);
		while (getline(f, line))
		{
			int* v;
			n = 0;
			conversieVector(line, v,n);
			creeazaArborele(v,n);
			cout << endl;
		}
	}
	f.close();
}

int main() {
	app(); 
}
