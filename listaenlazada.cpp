#include <iostream>
#include <stack>
using namespace std;

// class LNODE
template <class T>
struct LNode{
	LNode();
	LNode(T x);
	LNode<T> * next;
	T data;
};

template <class T>
LNode<T>::LNode(T x){
	data = x;
	next = NULL;
}



//class LIST
template <class T>
struct List{
	List();
	LNode<T> * head;
	bool find(T x,LNode<T> ** &p);
	void insert(T x);
	void remove(T x);
	void invert();
	void reverse();
	void print();
};

template <class T>
List<T>::List(){
	head = NULL;
}

template <class T>
bool List<T>::find(T x,LNode<T> ** &p){
	for(p=&head; *p!=NULL; p=&(*p)->next){
		if ((*p)->data == x) return 1;
	}
	return 0;	
}

template <class T>
void List<T>::insert(T x){
	LNode<T> ** p;
	if(find(x,p)) return;
	*p = new LNode<T>(x);

	return;	
}

template <class T>
void List<T>::remove(T x){
	LNode<T>** p;
	if(!find(x,p)) return;
	LNode<T>* q = *p;
	*p = q->next;
	delete q;
}

template <class T>
void List<T>::invert(){
	stack< LNode<T>* > tmp;
	LNode<T> ** p;
	for(p=&head; *p!=NULL; p=&(*p)->next){
		tmp.push(*p);
	}

	head = tmp.top();
	while(!tmp.empty()){
		*p = tmp.top();
		tmp.pop();
		if(tmp.empty()){
			(*p)->next = NULL;
			break;
		}
	    p=&(*p)->next;
		*p = tmp.top();

	}

	return;
	
}

template <class T>
void List<T>::reverse(){
    LNode<T>* tmp = head;
    LNode<T>* prev = NULL;
    LNode<T>* next = NULL;
    while(tmp){
    	next = tmp->next;
        tmp->next = prev;
        prev = tmp;
        tmp = next;
    }
    head = prev;
}

template <class T>
void List<T>::print(){
	LNode<T> ** p;
	for(p=&head; *p!=NULL; p=&(*p)->next){
		cout << (*p)->data<<"  ";
	}	
}

int main(){
	List<int> lista;
	lista.insert(9);
	lista.insert(10);
	lista.insert(11);
	lista.insert(12);
	lista.insert(13);
	lista.insert(14);
	lista.insert(15);
	lista.insert(16);
	lista.insert(17);
	lista.insert(18);
	lista.insert(19);
	lista.print();
	cout << endl;
	lista.reverse();
lista.print();
	lista.remove(19);
	cout << endl;
	lista.print();
	return 0;
}