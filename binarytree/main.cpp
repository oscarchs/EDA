#include "binarytree.h"
#include "bnode.h"
#include <iostream>
#include <thread>
using namespace std;


int main(){

	typedef BTree< traitDesc<int> > tree;
	tree btree;

	//thread x = btree.p_insert(10);
	//x.join();

				thread a(&tree::insert,&btree,20);
	thread x(&tree::insert,&btree,10);
	thread y(&tree::insert,&btree,9);
		thread z(&tree::insert,&btree,8);
			thread w(&tree::insert,&btree,11);
					thread b(&tree::insert,&btree,0);

	a.join();
	
	x.join();
	y.join();
	z.join();
	w.join();
	b.join();

	btree.mostrar();
	return 0;
}