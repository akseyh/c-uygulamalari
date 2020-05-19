#include "Header.hpp"
#include <iostream>
using namespace std; 
  
void H::hanoiGonder(int n, char A, char C, char B)  {  
  if (n == 1){
    cout << "1. disk : " << A <<" -> " << C<<endl;  
    return;  
  }  
  hanoiGonder(n - 1, A, B, C);  
  cout  << n << ". disk : " << A << " -> " << C << endl;  
  hanoiGonder(n - 1, B, C, A);  
}  