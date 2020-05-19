#include "Header.hpp"
#include <iostream>
using namespace std;

bool BST::ara(struct dugum* root, int x)
{
    if(root == NULL)
    {
        return false;
    }
    else if(x < root->veri)
    {
        return ara(root->sol, x);
    }
    else if(root->veri < x)
    {
        return ara(root->sag,x);
    }
    else
    {
        return true;
    }
}

dugum* BST::ekle(struct dugum* root, int x) {

	if (root == NULL) {
		struct dugum* eklenecek = (struct dugum*)malloc(sizeof(dugum));
		eklenecek->veri = x;
		eklenecek->sag = NULL;
		eklenecek->sol = NULL;
		return eklenecek;
	}
	else
	{
		if (x < root->veri) {
			root->sol = BST::ekle(root->sol, x);
		}
		else if (x > root->veri) {
			root->sag = BST::ekle(root->sag, x);
		}
	}

	return root;
}

dugum* BST::min(struct dugum* root) {
	struct dugum* gecici = root;

	while (gecici && gecici->sol != NULL)
		gecici = gecici->sol;
	cout << "en kucuk deger:" << gecici->veri << endl;
	return gecici;
}

dugum* BST::max(struct dugum* root) {
	struct dugum* gecici = root;

	while (gecici && gecici->sag != NULL)
		gecici = gecici->sag;
	cout << "en kucuk deger:" << gecici->veri << endl;
	return gecici;
}

dugum* BST::sil(struct dugum* root, int x) {
	if (root == NULL) {
		cout << "Silinecek node yok" << endl;
		return root;
	}
	else if (x < root->veri)
	{
		root->sol = BST::sil(root->sol, x);
	}
	else if (x > root->veri)
	{
		root->sag = BST::sil(root->sag, x);
	}
	else {
		if (root->sol == NULL) {
			struct dugum* gecici = root->sag;
			free(root);
			return gecici;
		}
		else if (root->sag == NULL) {
			struct dugum* gecici = root->sol;
			free(root);
			return gecici;
		}
		else{
			struct dugum* varis = BST::min(root->sag);
			int deger = varis->veri;

			BST::sil(root, varis->veri);
			root->veri = deger;
		}

	}

	return root;
}

void BST::inOrder(struct dugum* root) {
	if (root != NULL) {
		BST::inOrder(root->sol);
		cout << root->veri << " ";
		BST::inOrder(root->sag);
	}
}

void BST::preOrder(struct dugum* root) {
	if (root != NULL) {
		cout << root->veri << " ";
		BST::preOrder(root->sol);
		BST::preOrder(root->sag);
	}
}

void BST::postOrder(struct dugum* root) {
	if (root != NULL) {
		postOrder(root->sol);
		postOrder(root->sag);
		cout << root->veri << " ";
	}
}