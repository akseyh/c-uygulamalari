#include "Header.hpp"
#include <iostream>

using namespace std;

int AVL::yukseklik(struct node* dugum)
{
	if (dugum == NULL)
		return 0;
  return dugum->yuksek;
}

int AVL::karsilastir(int x, int y)
{
	if (x >= y)
		return x;
	else
		return y;
}

node* AVL::dugumOlustur(int veri)
{
	struct node* yeniDugum = (struct node*)malloc(sizeof(struct node));
	yeniDugum->veri =veri;
	yeniDugum->sol = NULL;
	yeniDugum->sag = NULL;

	yeniDugum->yuksek = 1;

	return yeniDugum;
}

node* AVL::sagaDondur(struct node *y)
{
	struct node *x = y->sol;
	struct node *t = x->sag;
    
	x->sag = y;
	y->sol = t;

	y->yuksek = karsilastir(yukseklik(y->sol), yukseklik(y->sag)) + 1;
	x->yuksek = karsilastir(yukseklik(x->sol), yukseklik(x->sag)) + 1;

	return x;
}

node* AVL::solaDondur(struct node *x)
{
	struct node *y = x->sag;
	struct node *t2 = y->sol;

	y->sol = x;
	x->sag = t2;

	y->yuksek = karsilastir(yukseklik(y->sol), yukseklik(y->sag)) + 1;
	x->yuksek = karsilastir(yukseklik(x->sol), yukseklik(x->sag)) + 1;

	return y;
}

int AVL::kontrol(struct node* dugum)
{
	if (dugum == NULL)
		return 0;
	else
		return yukseklik(dugum->sol) - yukseklik(dugum->sag);

}

node* AVL::ekle(struct node* kokDugum, int veri)
{
	if (kokDugum == NULL)
		return dugumOlustur(veri);

	if (veri < kokDugum->veri){
		kokDugum->sol = ekle(kokDugum->sol, veri);
  }
	else if (veri > kokDugum->veri){
		kokDugum->sag = ekle(kokDugum->sag, veri);
	}else {
		return kokDugum;
  }

	kokDugum->yuksek = karsilastir(yukseklik(kokDugum->sol), yukseklik(kokDugum->sag)) + 1;
    
	int balance = kontrol(kokDugum);
  
	if (balance > 1 && veri < kokDugum->sol->veri){
		return sagaDondur(kokDugum);
  }
  
	if (balance < -1 && veri > kokDugum->sag->veri ){
		return solaDondur(kokDugum);
  }
  
  if (balance > 1 && veri > kokDugum->sol->veri){
		kokDugum->sol = solaDondur(kokDugum->sol);
		return sagaDondur(kokDugum);
	}

	if (balance < -1 && veri < kokDugum->sag->veri){
		kokDugum->sag = sagaDondur(kokDugum->sag);
		return solaDondur(kokDugum);
	}
	return kokDugum;
}

void AVL::preOrderYazdir(struct node* root)
{
	if (root != NULL)
	{
		printf(" %d ", root->veri);
		preOrderYazdir(root->sol);
		preOrderYazdir(root->sag);
	}
}