#ifndef SORUUC
#define SORUUC

struct dugum {
    int veri;
    struct dugum* sol, * sag;
};
class BST
{
public:
    bool ara(dugum*, int);
    dugum* ekle(dugum*, int);
    dugum* max(dugum*);
    dugum* min(dugum*);
    dugum* sil(dugum*,int);
    void inOrder(dugum*);
    void preOrder(dugum*);
    void postOrder(dugum*);

};

#endif