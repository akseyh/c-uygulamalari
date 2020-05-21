#include "Header.hpp"
#include <iostream>
#define UZUNLUK 9
using namespace std;

int main() {
	S S1;
	int veriler[] = {7,3,5,8,2,9,4,15,6};
	S1.kabarcik(veriler);
	S1.arayaSokma(veriler);
	S1.secmeli(veriler);
     S1.birlesmeli(veriler,UZUNLUK);
}