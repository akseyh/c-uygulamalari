#include "Header.hpp"
#include <iostream>
#define HANOISAY 4

using namespace std; 
  
int main()  
{  
    H h1; 
    h1.hanoiGonder(HANOISAY, 'A', 'C', 'B');
    return 0;  
}  