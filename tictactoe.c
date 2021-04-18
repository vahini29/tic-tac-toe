#include<stdio.h>
#include<conio.h>

#define SIZE 3
int X,O;
char userinput;
int flag;
char player1[10],player2[10];
struct game
{
	char board[SIZE][SIZE];
    int  tindicator;
	int tcount;
	int  checkwin;
};
typedef struct game game_t;
game_t game796;
void display()
{
	
printf("\n\n");
printf("\t\t\t %c | %c | %c \n", game796.board[0][0],game796.board[0][1],game796.board[0][2]);
printf("\t\t\t------------\n");
printf("\t\t\t %c | %c | %c \n", game796.board[1][0],game796.board[1][1],game796.board[1][2]);
printf("\t\t\t------------\n");
printf("\t\t\t %c | %c | %c \n", game796.board[2][0],game796.board[2][1],game796.board[2][2]);
}
void inti(){
	int index1,index2;
//printf("\t\t\t---------------\n");
for(index1=0;index1<3;index1++)
{
	for(index2=0;index2<3;index2++)
	{
		game796.board[index1][index2]=' ';
	}
}
}
int checkwin()
{   if(game796.board[0][0]==game796.board[0][1] &&
	game796.board[0][1]==game796.board[0][2]&&(game796.board[0][0]=='X'||game796.board[0][0]=='O'))
	return 1;
	
	if(game796.board[1][0]==game796.board[1][1] &&
	game796.board[1][1]==game796.board[1][2]&&(game796.board[1][0]=='X'||game796.board[1][0]=='O'))
	return 1;
	
	 if(game796.board[2][0]==game796.board[2][1] &&
	game796.board[2][1]==game796.board[2][2]&&(game796.board[2][0]=='X'||game796.board[2][0]=='O'))
	return 1;
	
	if(game796.board[0][0]==game796.board[1][0] &&
	game796.board[1][0]==game796.board[2][0]&&(game796.board[0][0]=='X'||game796.board[0][0]=='O'))
	return 1;
	
	if(game796.board[0][1]==game796.board[1][1] &&
	game796.board[1][1]==game796.board[2][1]&&(game796.board[0][1]=='X'||game796.board[0][1]=='O'))
	return 1;
	
	if(game796.board[0][2]==game796.board[1][2] &&
	game796.board[1][2]==game796.board[2][2]&&(game796.board[0][2]=='X'||game796.board[0][2]=='O'))
	return 1;
	
	if(game796.board[0][0]==game796.board[1][1] &&
	game796.board[1][1]==game796.board[2][2]&&(game796.board[0][0]=='X'||game796.board[0][0]=='O'))
	return 1;
	
	if(game796.board[0][2]==game796.board[1][1] &&
	game796.board[1][1]==game796.board[2][0]&&(game796.board[0][2]=='X'||game796.board[0][2]=='O'))
	return 1;
	else 
	return 0;
	 
}  
          
	

int main()
{
	game796.tcount=1;
	char mark;
	printf("enter the name of player1:");
	gets(player1);
	printf("Welcome %s",player1);
	printf("\nenter the name of player 2:");
	gets(player2);;
	printf("Welcome %s",player2);
	printf("\ndo you want to play the game y for yes q for quit\n");
	userinput=getch();
	printf("%c",userinput);
	display();
	while(1)
	{
		
		if(userinput=='Y'|| userinput=='y')
		{
		if(game796.tcount%2==0)
		game796.tindicator=2;
		else
		game796.tindicator=1;
		if(game796.tindicator==1)
		mark='X';
		else
		mark='O';
		printf("\nplayer %d,enter the positions:",game796.tindicator);
		scanf("%d%d",&X,&O);
		if(game796.board[X][O]!='X'&&game796.board[X][O]!='O')
		{
			game796.board[X][O]=mark;
		}
		else
		{
			printf("placement not avaliable");
			game796.tcount--;
		}
	
		
		game796.tcount++;
		display();
		game796.checkwin=checkwin();
		if(game796.checkwin==1 && game796.tindicator==1)
		{
			printf("CONGRALUATIONS!!!!!");
			printf("\nPlayer 1 ,%s you won this game",player1);
			inti();
			display();
			printf("\n Would you like to continue playing y for yes q for quit\n");
	        userinput=getch();
			
		}
		else if(game796.checkwin==1 && game796.tindicator==2)
		{
			printf("CONGRALUATIONS!!!!!");
			printf("\nPlayer 2 ,%s you won this game",player2);
			inti();
			display();
		    printf("\n Would you like to continue playing y for yes q for quit\n");
	        userinput=getch();
			
		}
		if(game796.tcount>9)
		{
			printf("game ends \n do you want to play the game from beginning");
			userinput=getch();
			inti();
			display();
			game796.tcount=0;
		}
		
	}
	else
	break;
		
}
}
	

		
		
