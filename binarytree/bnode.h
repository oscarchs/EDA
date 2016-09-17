#ifndef BNODE_H
#define BNODE_H
#include <mutex>
#include <iostream>
using namespace std;

template<class T>
struct BNode{
    
	BNode(T x);
	T data_;
	BNode<T> * leaf_[2];

	mutex m_[2];

};

template <class T>
BNode<T>::BNode(T x){
	this->leaf_[0] = NULL;
	this->leaf_[1] = NULL;
	this->data_ = x;
}
#endif 