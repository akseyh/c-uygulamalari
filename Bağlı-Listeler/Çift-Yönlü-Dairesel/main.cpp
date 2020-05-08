#include <stdio.h>
#include <stdlib.h>
 
typedef struct KUYRUK {
    int sayi;
    struct KUYRUK *onceki, *sonraki;
} kuyruk;
 
kuyruk *ilk;
 
void menu();
void CYDBL_basaelemanekle(int sayi);
void CYDBL_sonaelemanekle(int sayi);
void CYDBL_siralielemanekle(int sayi);
void CYDBL_bastanelemansilme();
void CYDBL_sondanelemansilme();
void CYDBL_belirlielemansilme(int sayi);
void listele();

int main() {
 
    while (1) {
        menu();
    }
    return 0;
}

void menu() {
  int sayi;
  printf("1- Basa Ekle\n");
  printf("2- Sona Ekle\n");
  printf("3- Sirali Ekle\n");
  printf("4- Bastan Sil\n");
  printf("5- Sondan Sil\n");
  printf("6- Belirli Sil\n");
  printf("7- Listele\n");
  int secenek;
  printf("Tercih: ");
  scanf("%d", &secenek);
  switch (secenek) {
    case 1:
      printf("Sayi giriniz: ");
      scanf("%d", &sayi);
      CYDBL_basaelemanekle(sayi);
      listele();
      break;
    case 2:
      printf("Sayi giriniz: ");
      scanf("%d", &sayi);
      CYDBL_sonaelemanekle(sayi);
      listele();
      break;
    case 3:
      printf("Sayi giriniz: ");
      scanf("%d", &sayi);
      CYDBL_siralielemanekle(sayi);
      listele();
      break;
    case 4:
      CYDBL_bastanelemansilme();
      listele();
      break;
    case 5:
      CYDBL_sondanelemansilme();
      listele();
      break;
    case 6:
      printf("Sayi giriniz: ");
      scanf("%d", &sayi);
      CYDBL_belirlielemansilme(sayi);
      listele();
      break;
    case 7:
      listele();    
      break;
    default:
      printf("Hatali Secim!\n");
  }
}

void CYDBL_basaelemanekle(int sayi) {
 
    if (ilk == NULL) {
      kuyruk *yeni = (kuyruk*) malloc(sizeof (kuyruk));
      yeni->sonraki= yeni;
      yeni->onceki = yeni;
      yeni->sayi = sayi;
      ilk = yeni;
      return;
    } else {
      kuyruk *yeni = (kuyruk*) malloc(sizeof (kuyruk));
      yeni->sayi = sayi;
      kuyruk *gecici;
      gecici = ilk;
      while(gecici->sonraki != ilk){
        gecici = gecici->sonraki;
      }
      gecici->sonraki = yeni;
      yeni->onceki = gecici;
      ilk->onceki = yeni;
      yeni->sonraki = ilk;
      ilk = yeni;
    }
}

void CYDBL_sonaelemanekle(int sayi) {
    
    if (ilk == NULL) {
      kuyruk *yeni = (kuyruk*) malloc(sizeof (kuyruk));
      yeni->sonraki= yeni;
      yeni->onceki = yeni;
      yeni->sayi = sayi;
      ilk = yeni;
      return;
    } else {
        kuyruk *yeni = (kuyruk*) malloc(sizeof (kuyruk));
        yeni->sonraki = ilk;
        yeni->sayi = sayi;
        kuyruk *gecici;
        gecici = ilk;
        while(gecici->sonraki != ilk){
          gecici = gecici->sonraki;
        }
        gecici->sonraki = yeni;
        yeni->onceki = gecici;
        ilk->onceki = yeni;
    }
}

void CYDBL_siralielemanekle(int sayi){

  if (ilk == NULL) {
    kuyruk *yeni = (kuyruk*) malloc(sizeof (kuyruk));
     yeni->sonraki= yeni;
     yeni->onceki = yeni;
     yeni->sayi = sayi;
     ilk = yeni;
     return;
  }
  if ( (ilk->sayi) > sayi ){
    kuyruk *yeni = (kuyruk*) malloc(sizeof (kuyruk));
    yeni->sayi = sayi;
    kuyruk *gecici;
    gecici = ilk;
    while(gecici->sonraki != ilk){
      gecici = gecici->sonraki;
    }
    gecici->sonraki = yeni;
    yeni->onceki = gecici;
    ilk->onceki = yeni;
    yeni->sonraki = ilk;
    ilk = yeni;
    return;
  }
  else{
    kuyruk *gecici = ilk;
    while(gecici->sonraki != ilk && (gecici->sonraki->sayi) < sayi) {
      gecici = gecici->sonraki;
    }
    kuyruk *yeni = (kuyruk*) malloc(sizeof (kuyruk));
    yeni->sayi = sayi;
    yeni->sonraki = gecici->sonraki;
    gecici->sonraki = yeni;
  }

}

void CYDBL_bastanelemansilme(){
   if (ilk == NULL) {
        printf("Kuyruk bos\n");
    } else {
      kuyruk * gecici = (kuyruk*) malloc(sizeof (kuyruk));
      kuyruk * sil = (kuyruk*) malloc(sizeof (kuyruk));
      gecici = ilk;
      sil = ilk->sonraki;

      while(gecici->sonraki != ilk){
        gecici = gecici->sonraki;
      }
      if(ilk->sonraki == ilk){
        free(ilk);
        return;
      }
      gecici->sonraki = sil;
      sil->onceki = gecici;
      ilk = sil;	
      }
}

void CYDBL_sondanelemansilme(){
   if (ilk == NULL) {
        printf("Kuyruk bos\n");
        return;
    } else {
      kuyruk * gecici = (kuyruk*) malloc(sizeof (kuyruk));
      if(ilk->onceki == ilk){
        free(ilk);
        return;
      }
      gecici = ilk;
      gecici = gecici->onceki->onceki;
      gecici->sonraki = ilk;
      ilk->onceki = gecici;
    }
}

void CYDBL_belirlielemansilme(int sayi){
  if (ilk == NULL) {
    printf("Kuyruk bos\n");
    return;
  } 
  kuyruk * gecici = (kuyruk*) malloc(sizeof (kuyruk));
  kuyruk * sil = (kuyruk*) malloc(sizeof (kuyruk));
  gecici = ilk;
  if(ilk->sayi == sayi){
    gecici = ilk;
    sil = ilk->sonraki;

    while(gecici->sonraki != ilk){
      gecici = gecici->sonraki;
    }
    if(ilk->sonraki == ilk){
      free(ilk);
      return;
    }
    gecici->sonraki = sil;
    sil->onceki = gecici;
    ilk = sil;	
    return;
    }
    while(gecici->sonraki != ilk && gecici->sonraki->sayi != sayi){
      gecici = gecici->sonraki;
    }
    if(gecici->sonraki == ilk){
      printf("girilen eleman bagli listede bulunmamaktadir.");
      return;
    }
    sil = gecici->sonraki;
    gecici->sonraki = gecici->sonraki->sonraki;
    free(sil);
}

void listele() {
    if (ilk == NULL) {
        printf("Kuyruk Bos\n");
    } 
    if(ilk->sonraki == ilk){
      printf("%d\n", ilk->sayi);
    }
    else{
      kuyruk *gecici;
      gecici = ilk;

      while(gecici->sonraki != ilk){
        printf("%d - ", gecici->sayi);
        gecici= gecici->sonraki;
      } 
      printf("%d \n", gecici->sayi);
    }
}
