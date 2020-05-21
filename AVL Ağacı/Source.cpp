#include "Header.hpp"
#include <iostream>

int main()
{
  AVL AVL1;
  node* root = NULL;
  root = AVL1.ekle(root, 60);
  root = AVL1.ekle(root, 45);
  root = AVL1.ekle(root, 30);
  root = AVL1.ekle(root, 90);
  root = AVL1.ekle(root, 120);
  AVL1.preOrderYazdir(root);
}