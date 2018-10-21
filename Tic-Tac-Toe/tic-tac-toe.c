#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(){
	
	int x,n,m,q,numx[9]={0,0,0,0,0,0,0,0,0};
	char num;
	char karakter[2]= { 'X','O' };
	char tablo[3][3];

	
	int sira = 0;
	for(n=0;n<3;n++){
		for(m=0;m<3;m++){
			tablo[n][m] = '#';
			printf("%c",tablo[n][m]);
		}
		printf("\n");
	}
	
	
	
	while(1){
	
	sira = sira % 2;
	
	num = getch();
	system("CLS");
	
	switch(num){
		case '0':
			return main();
		case '1':
			if(numx[0]==1)
				break;
			tablo[2][0]= karakter[sira];
			sira++;
			numx[0]=1;
			break;
		case '2':
			if(numx[1]==1)
				break;
			tablo[2][1]= karakter[sira];
			sira++;
			numx[1]=1;
			break;
		case '3':
			if(numx[2]==1)
				break;
			tablo[2][2]= karakter[sira];
			sira++;
			numx[2]=1;
			break;
		case '4':
			if(numx[3]==1)
				break;
			tablo[1][0]= karakter[sira];
			sira++;
			numx[3]=1;
			break;
		case '5':
			if(numx[4]==1)
				break;
			tablo[1][1]= karakter[sira];
			sira++;
			numx[4]=1;
			break;
		case '6':
			if(numx[5]==1)
				break;
			tablo[1][2]= karakter[sira];
			sira++;
			numx[5]=1;
			break;
		case '7':
			if(numx[6]==1)
				break;
			tablo[0][0]= karakter[sira];
			sira++;
			numx[6]=1;
			break;
		case '8':
			if(numx[7]==1)
				break;
			tablo[0][1]= karakter[sira];
			sira++;
			numx[7]=1;
			break;
		case '9':
			if(numx[8]==1)
				break;
			tablo[0][2]= karakter[sira];
			sira++;
			numx[8]=1;
			break;
		default:
			break;
	}
		
	
	for(n=0;n<3;n++){
		for(m=0;m<3;m++){
			printf("%c",tablo[n][m]);
		}
		printf("\n");
	}
	for(n=0;n<3;n++){
		if( tablo[n][0] == tablo[n][1] && tablo[n][1] == tablo[n][2] && tablo[n][0] == karakter[sira-1] ||
			tablo[0][n] == tablo[1][n] && tablo[1][n] == tablo[2][n] && tablo[0][n] == karakter[sira-1] ){
			printf("%c Kazandi!",karakter[sira-1]);
			getch();
			system("CLS");
			return main();
		}
	}
	n=0;
	if( tablo[n][n] == tablo[n+1][n+1] && tablo[n+1][n+1] == tablo[n+2][n+2] && tablo[n][n] == karakter[sira-1] ||
		tablo[n][n+2] == tablo[n+1][n+1] && tablo[n+1][n+1] == tablo[n+2][n] && tablo[n][n+2] == karakter[sira-1] ){
		printf("%c Kazandi!",karakter[sira-1]);
		getch();
		system("CLS");
		return main();
	}
	int berabere=0;
	for(n=0;n<3;n++){
		for(m=0;m<3;m++){
			if( tablo[n][m] != '#' )
				berabere++;
		}
		if(berabere == 9){
		printf("Berabere!");
		getch();
		system("CLS");
		return main();
		}
	}
}
	
	return 0;
}
