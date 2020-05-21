#include "Header.hpp"
#include <iostream>
using namespace std;

void S::birlesmeliIslem(int dizi[], int lo, int  mi, int hi){
    int *gecici = new int[hi-lo+1];
    int i = lo, j = mi + 1;
    int k = 0;
    while(i <= mi && j <=hi){
        if(dizi[i] <= dizi[j])
            gecici[k++] = dizi[i++];
        else
            gecici[k++] = dizi[j++];
    }
    while(i <= mi)
        gecici[k++] = dizi[i++];
    while(j <= hi)
        gecici[k++] = dizi[j++];
    for(k = 0, i = lo; i <= hi; ++i, ++k)
        dizi[i] = gecici[k];
 
    delete []gecici;
}

void S::birlesmeliDagit(int dizi[], int lo, int hi){
    int orta;
    if(lo < hi){
        orta = (lo + hi) >> 1;
        birlesmeliDagit(dizi, lo, orta);
        birlesmeliDagit(dizi, orta+1, hi);
        birlesmeliIslem(dizi, lo, orta, hi);
    }
}

void S::birlesmeli(int dizi[], int diziUzunluk){
    birlesmeliDagit(dizi, 0, diziUzunluk-1);
    cout << "\nBirleşmeli:\n";
    for (int i = 0; i < 8; ++i)
      cout << dizi[i] << " - ";
    cout << dizi[8];
}

void S::kabarcik(int dizi[]) {
	int gecici;
	int kontrol;
	while(kontrol){
		kontrol = 0;
		for (int i = 0; i < 8; i++) {
			if (dizi[i + 1] <dizi[i]) {
				gecici = dizi[i];
				dizi[i] = dizi[i + 1];
				dizi[i + 1] = gecici;
				kontrol = 1;
			}
		}
	}
	cout <<"Kabarcık:" << endl;
	for (int i = 0; i <= 7; i++) {
		cout << dizi[i] << " - ";
	}
	cout << dizi[8];
}

void S::arayaSokma(int dizi[]) {
	int gecici;
	int kontrol;
	for (int i = 1; i < 8; i++) {
		kontrol = i;
		while (kontrol > 0 && dizi[kontrol] < dizi[kontrol - 1]) {
			gecici = dizi[kontrol];
			dizi[kontrol] = dizi[kontrol - 1];
			dizi[kontrol - 1] = gecici;
			kontrol--;
		}
	}
	cout <<endl<< "Araya Ekleme:" << endl;
	for (int i = 0; i <= 7; i++) {
		cout << dizi[i] << " - ";
	}
	cout << dizi[8];
}

void S::secmeli(int dizi[]) {
	int enkucuk, gecici;
	for (int i = 0; i < 8; i++) {
		enkucuk = i;
		for (int k = i + 1; k < 5; k++) {
			if (dizi[k] < dizi[enkucuk]) {
				enkucuk = k;
			}
		}
		gecici = dizi[i];
		dizi[i] = dizi[enkucuk];
		dizi[enkucuk] = gecici;
	}
	cout << endl << "Secme:" << endl;
	for (int i = 0; i <= 7; i++) {
		cout << dizi[i] << " - ";
	}
	cout << dizi[8];
}
