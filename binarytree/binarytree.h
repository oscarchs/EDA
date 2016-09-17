#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include "bnode.h"
#include "trait.h"
#include <mutex>
#include <thread>
#include <chrono>
using namespace std;


template<class Tr>
struct BTree{

    typedef typename Tr::t_data T;
    typedef typename Tr::ord O;

	BTree();
	BNode<T> * root_;
	mutex m_root;
	O cmp;

	bool find(T n, BNode<T>** &p, BNode<T>** &q, bool &side);
	bool insert(T n);	
	thread p_insert(T n);

	void inorder(BNode<T>* p);
	void mostrar();

};

template <class Tr>
BTree<Tr>::BTree(){
	root_ = NULL;
}

template <class Tr>
bool BTree<Tr>::find(T n, BNode<T>** &p, BNode<T>** &q, bool &side){
  p = &this->root_;
  q = p;
  for(p = &root_; *p ; p = &(*p)->leaf_[cmp((*p)->data_,n)]){
    q = p;
    side = cmp((*p)->data_,n);
    if((*p)->data_ == n){
        return 1;
    }
  }
  return 0;
}

template <class Tr>
bool BTree<Tr>::insert(T n){
  BNode<T>** p;
  BNode<T>** q;
  
  //if root null try lock and insert
  if(this->root_ == NULL){
  	if(this->m_root.try_lock()){
  		this->root_ = new BNode<T>(n);
  		m_root.unlock();
  		return 1;
  	}
  }
  else{
  	bool side;
  	if(find(n,p,q,side)){return 0;}
  	while(true){
	  	if((*q)->m_[side].try_lock()){
	  		*p = new BNode<T>(n);	
		   	(*q)->m_[side].unlock();
		   	//cout << "unblocked";
	  		return 1;
	  	}
	  	this_thread::sleep_for(chrono::milliseconds(10000));
	  	cout << " nunca entra aquí, no entiendo me duele la cabeza :("<<endl;
	 }
  }
}

template <class Tr>
void BTree<Tr>::inorder(BNode<T>* p){
  if(!p){
    return;
  }
  inorder(p->leaf_[0]);
  cout << p->data_ << endl;
  inorder(p->leaf_[1]);

}

template <class Tr>
void BTree<Tr>::mostrar(){
  BNode<T>* p = this->root_;
  inorder(p);
}


template <class Tr>
thread BTree<Tr>::p_insert(T n){
	return thread ([=] { insert(n); });
} 

#endif 