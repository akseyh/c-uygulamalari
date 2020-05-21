#include "Header.hpp"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
	BST BST1;
	struct dugum* root = NULL;
	root = BST1.ekle(root, 40);
	BST1.ekle(root, 20);
	BST1.ekle(root, 30);
	BST1.ekle(root, 60);
	BST1.ekle(root, 80);
	BST1.ekle(root, 100);
	BST1.ekle(root, 120);
	BST1.ekle(root, 140);
	BST1.ekle(root, 136);
	BST1.ekle(root, 130);

	cout << "inorder: ";
	BST1.inOrder(root);
	cout << endl;

	cout << "postorder: ";
	BST1.postOrder(root);
	cout << endl;

	cout << "preorder: ";
	BST1.preOrder(root);
	cout << endl;

	BST1.sil(root,60);

  cout << "60 elemanını silindi. Listelendi: " << endl;
	BST1.inOrder(root);
	cout << endl;

	cout << "60'ı ara (varsa: 1, yoksa: 0):" << endl;
  cout << BST1.ara(root, 60) <<endl;

	cout << "En küçük eleman:";
	BST1.min(root);
	cout << endl;

	cout << "En büyük eleman:";
	BST1.max(root);
	cout << endl;
}