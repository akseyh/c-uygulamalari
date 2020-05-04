#include <iostream>
#include <stdlib.h>

typedef struct list {
    int sayi;
    struct list *sonraki;
} liste;
liste *ilk = NULL, *son = NULL, *yeni, *silGecici, *gecici;


void menu();
void TYBL_basaelemanekle();
void sil(int );
void listele();
void arama(int );

int main() {
    while (1) {
        menu();
    }
}

void yazdir(){
  gecici = ilk;
  while(gecici != NULL){
    printf("%d\n", gecici->sayi);
    gecici = gecici->sonraki;
  }
}

void TYBL_basaelemanekle(int veri){
  yeni = (liste *) malloc(sizeof (liste));
  yeni->sayi = veri;
  yeni->sonraki = NULL;
 
    if (ilk == NULL) {
      ilk = yeni;
      son = ilk;
    } else {
      son->sonraki = yeni;
      son = son->sonraki;
    }
}

void TYBL_sonaelemanekle(int veri){
  yeni = (liste *) malloc(sizeof (liste));
  yeni->sayi = veri;
  yeni->sonraki = NULL;

    if (ilk == NULL) {
        ilk = yeni;
        son = ilk;
    } else {
      gecici = ilk;
      while(gecici->sonraki != NULL){
        gecici = gecici->sonraki;
      }
      gecici->sonraki = yeni;
    }
}

void TYBL_siralielemanekle(int veri){

  if (ilk == NULL) {
    ilk = (liste*) malloc(sizeof (liste));
    ilk->sayi = veri;
    ilk->sonraki = NULL;
  } else {
    if ((ilk->sayi) > (veri)) {
      yeni = (liste*) malloc(sizeof (liste));
      yeni->sayi = veri;
      yeni->sonraki = ilk;
      ilk = yeni;
    } else {
      gecici = ilk;
      yeni = (liste*) malloc(sizeof (liste));
      yeni->sayi = veri;
      while (gecici != NULL) {
        if (gecici->sonraki == NULL && (gecici->sayi) <= (veri)) {
            yeni->sonraki = NULL;
            gecici->sonraki = yeni;
            break;
        }
        if ((gecici->sonraki->sayi) > (veri)) {
            yeni->sonraki = gecici->sonraki;
            gecici->sonraki = yeni;
            break;
        }
        gecici = gecici->sonraki;
        }
      }
    }
}

void TYBL_bastanelemansilme(){
  if(ilk != NULL){
    if(ilk->sonraki != NULL){
      silGecici = ilk;
      ilk = ilk->sonraki;
      free(gecici);
    }
    else{
      free(ilk);
      ilk = NULL;
    }
  }
  else{
    printf("\n Silinecek eleman bulunamadı\n");
  }
}

void TYBL_sondanelemansilme(){
  if(ilk != NULL){
    silGecici = ilk;
    if(ilk->sonraki != NULL){
      while(silGecici->sonraki->sonraki != NULL){
        silGecici = silGecici->sonraki;
      }
      free(silGecici->sonraki);
      silGecici->sonraki = NULL;
    }
    else{
      free(ilk);
      ilk = NULL;
    }
  }
  else{
    printf("\n Silinecek eleman bulunamadı\n");
  }
}

void TYBL_belirlielemansilme(int veri){
  int kontrol = 0;
  if (ilk->sayi == veri) {
    silGecici = ilk;
    ilk = ilk->sonraki;
    free(silGecici);
    kontrol = 1;
  } else {
    gecici = ilk;
    while (gecici->sonraki != NULL) {
      if (gecici->sonraki->sayi == veri) {
        kontrol = 1;
        silGecici = gecici->sonraki;
        if (silGecici == son){
          son = gecici;
        }
        gecici->sonraki = silGecici->sonraki;
        free(silGecici);
        break;
      }
      gecici = gecici->sonraki;
    }
  }
  if (kontrol == 0)
    printf("girilen eleman bağlı listede bulunmamaktadır\n");
  else
    printf("%d sayisi listeden silinmiştir...\n", veri);
}

void menu() {
  int secim, sayi;

  printf("1-Basa Ekle\n");
  printf("2-Sona Ekle\n");
  printf("3-Sirali Ekle\n");
  printf("4-Bastan Sil\n");
  printf("5-Sondan Sil\n");
  printf("6-Belirli Sil\n");
  printf("Lutfen Secim Yapiniz --> ");
  scanf("%d", &secim);

  switch (secim) {
    case 1:
      printf("Sayi Giriniz: ");
      scanf("%d", &sayi);
      TYBL_basaelemanekle(sayi);
      printf("%d sayisi listenin başına eklendi\n",sayi);
      yazdir();
      break;
    case 2:
      printf("Sayi Giriniz: ");
      scanf("%d", &sayi);
      TYBL_sonaelemanekle(sayi);
      printf("%d sayisi listenin sonuna eklendi\n",sayi);
      yazdir();
      break;
    case 3:
      printf("Sayi Giriniz: ");
      scanf("%d", &sayi);
      TYBL_siralielemanekle(sayi);
      printf("%d sayisi eklenip, sıralandı.\n",sayi);
      yazdir();
      break;
    case 4:
      if (ilk == NULL) {
          printf("Liste Bos\n");
          break;
      }
      TYBL_bastanelemansilme();
      yazdir();
      break;
    case 5:
      if (ilk == NULL) {
          printf("Liste Bos\n");
          break;
      }
      TYBL_sondanelemansilme();
      yazdir();
      break;
    case 6:
      if (ilk == NULL) {
          printf("Liste Bos\n");
          break;
      }
      printf("Sayi Giriniz: ");
      scanf("%d", &sayi);
      TYBL_belirlielemansilme(sayi);
      yazdir();
      break;
    default:
      printf("Hatali Secim\n");
  }
}