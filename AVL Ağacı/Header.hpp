#ifndef SORUDORT
#define SORUDORT

struct node {
  int veri;
  struct node *sag;
  struct node *sol;
  int yuksek;
};

class AVL{
  public:
    int yukseklik(node*);
    int karsilastir(int, int);
    node* dugumOlustur(int);
    node *sagaDondur(node*);
    node *solaDondur(node*);
    int kontrol(node*);
    node* ekle(node*, int);
    void preOrderYazdir(node*);
};

#endif