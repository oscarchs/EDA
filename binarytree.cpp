#include <iostream>
using namespace std;

template <class T>
struct BNode{
	BNode(T n);
	T data;
	BNode<T>* leaf[2];
};


template <class T>
struct BTree{

  BNode<T>* root;
  bool find(t n,BTNode<t>** &p,stack<BTNode<t>**> &nodes);
  bool insert(t n);

}