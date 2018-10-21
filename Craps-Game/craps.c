#include <stdio.h>
#include <conio.h>

int zar(void);

int main(){
	int	i,dice[2];
	srand(time(NULL));
	
	printf("press enter for come out");
	getchar();
	printf("first dice:");
	dice[0] = zar();
	printf("%d\n",dice[0]);
	
	
	printf("press enter again for second dice");
	getchar();
	printf("second dice:");
	dice[1] = zar();
	printf("%d\n",dice[1]);
	
	
	int sum = dice[0] + dice[1];
	
	switch(sum){
		case 7:
			printf("\nsum:%d You Win!",sum);
			break;
		case 11:
			printf("\nsum:%d You Win!",sum);
			break;
		case 2:
			printf("\nsum:%d You Lose!",sum);
			break;
		case 3:
			printf("\nsum:%d You Lose!",sum);
			break;
		case 12:
			printf("\nsum:%d You Lose!",sum);
			break;
		default:
			do{
				printf("\nsum:%d you should to dice %d again",sum,sum);
				getchar();
				printf("first dice:");
				dice[0] = zar();
				printf("%d\n",dice[0]);
				printf("second dice is cominggg!!");
				getchar();
				printf("second dice:");
				dice[1] = zar();
				printf("%d\n",dice[1]);
				if( dice[0] + dice[1] == 7 ){
					printf("\nsum:7 You Lose!");
					break;
				}
				else if( dice[0] + dice[1] == sum)
					printf("\nsum:%d You Win!",dice[0]+dice[1]);
					else printf("\nNot %d Try Again!!\n",dice[0]+dice[1]);
			}
			while( sum != dice[0]+dice[1] );
			break;			
	}

	getchar();
	return 0;
}

int zar(){
	
	int time,n,dice;
	
	for(n=0; n<10000; n++){
		dice = rand()%6+1;
		printf("%d",dice);
		
		while(time<250)
			time = clock();
		
		printf("%c",8);
	}
	return dice;
}
