#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;
	char cell[5][7]{{'.', '.','.','.','.','.','.'},
					{'.', '.','.','.','.','.','.'},
					{'.', '.','.','.','.','.','.'},
					{'.', '.','.','.','.','.','.'},
					{'.', '.','.','.','.','.','.'}};
bool CheckRow(char player)
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if(cell[i][0]==player && cell[i][1]==player && cell[i][2]==player && cell[i][3]==player) return true;
			else {
			if(cell[i][1]==player && cell[i][2]==player && cell[i][3]==player && cell[i][4]==player) return true;	
			
			else {
			if(cell[i][2]==player && cell[i][3]==player && cell[i][4]==player && cell[i][5]==player) return true;	
			
			else {
			if(cell[i][3]==player && cell[i][4]==player && cell[i][5]==player && cell[i][6]==player) return true;	
			
			else {
			if(cell[i][4]==player && cell[i][5]==player && cell[i][6]==player && cell[i][7]==player) return true;	
			
			}
			}
			}
			}
		}
	}
	return false;
}
bool CheckCollumns(char player)
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if(cell[0][j]==player && cell[1][j]==player && cell[2][j]==player && cell[3][j]==player) return true;
			else {
			if(cell[1][j]==player && cell[2][j]==player && cell[3][j]==player && cell[4][j]==player) return true;	
			
			else {
			if(cell[2][j]==player && cell[3][j]==player && cell[4][j]==player && cell[5][j]==player) return true;	
			
			}
			}
		}
	}
	return false;
}
bool CheckDiagRight(char player)
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if(cell[0][0]==player && cell[1][1]==player && cell[2][2]==player && cell[3][3]==player) return true;
			else {
			if(cell[0][1]==player && cell[1][2]==player && cell[2][3]==player && cell[3][4]==player) return true;
			else {
			if(cell[0][3]==player && cell[1][4]==player && cell[2][5]==player && cell[3][6]==player) return true;
			else {
			if(cell[0][4]==player && cell[1][5]==player && cell[2][6]==player && cell[3][7]==player) return true;//
			else {
			if(cell[1][0]==player && cell[2][1]==player && cell[3][2]==player && cell[4][3]==player) return true;
			else {
			if(cell[1][1]==player && cell[2][2]==player && cell[3][3]==player && cell[4][4]==player) return true;
			else {
			if(cell[1][2]==player && cell[2][3]==player && cell[3][4]==player && cell[4][5]==player) return true;
			else {
			if(cell[1][3]==player && cell[2][4]==player && cell[3][5]==player && cell[4][6]==player) return true;
			}
			}
			}
			}
			}
			}
			}
		}
		
	}
	return false;
}
bool CheckDiagLeft(char player)
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if(cell[0][6]==player && cell[1][5]==player && cell[2][4]==player && cell[3][3]==player) return true;
			else {
			if(cell[0][5]==player && cell[1][4]==player && cell[2][3]==player && cell[3][2]==player) return true;
			else {
			if(cell[0][4]==player && cell[1][3]==player && cell[2][2]==player && cell[3][1]==player) return true;
			else {
			if(cell[0][3]==player && cell[1][2]==player && cell[2][1]==player && cell[3][0]==player) return true;//
			else {
			if(cell[1][6]==player && cell[2][5]==player && cell[3][4]==player && cell[4][3]==player) return true;
			else {
			if(cell[1][5]==player && cell[2][4]==player && cell[3][3]==player && cell[4][2]==player) return true;
			else {
			if(cell[1][4]==player && cell[2][3]==player && cell[3][2]==player && cell[4][1]==player) return true;
			else {
			if(cell[1][3]==player && cell[2][2]==player && cell[3][1]==player && cell[4][0]==player) return true;
			}
			}
			}
			}
			}
			}
			}
		}
		
	}
	return false;
}
bool CheckVictory(char player){
	return CheckRow(player) || CheckCollumns(player) || CheckDiagRight(player) || CheckDiagLeft(player);
}
/*bool CheckColumns(char *cell)
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if(cell[i+j-1]=='X' && cell[i+j+6]=='X' && cell[i+j+13]=='X' && cell[i+j+20]=='X') return true;
		}
	}
	return false;
}
bool CheckDiag(char *cell)
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if(cell[i+j-1]=='X' && cell[i+j+7]=='X' && cell[i+j+15]=='X' && cell[i+j+23]=='X') return true;
		}
	}
	return false;
}*/


int main(int argc, char** argv) {
	srand(time(NULL));	
	bool playerWin=false, botWin=false, draw=false;
	int x,y,turn;				
	do{
					
	for (int i = 0;i<5;i++){
		for(int j = 0; j<7;j++){
			cout<<cell[i][j];
		}
		cout<<endl;
		}
		do {
		cout<<"You turn to place: ";
		cin>>x>>y;}
		while(cell[x-1][y-1]!='.');
		cell[x-1][y-1] = 'X';
		turn+1;	
		do{	
		x= rand()%5;
		y=rand()%7;
	}while(cell[x][y]!='.');
	cell[x][y]='O';
	turn+1;
	if(CheckVictory('X')){
		playerWin=true;
	}
	if(CheckVictory('O')){
		botWin=true;
	}

	if (botWin==false && playerWin==false && turn==35) draw = true;
	
	
system("CLS");
}while(playerWin == false && botWin == false && draw == false);
for (int i = 0;i<5;i++){
		for(int j = 0; j<7;j++){
			cout<<cell[i][j];
		}
		cout<<endl;
		}
		if (botWin==true) cout<<"BOT WIN";
		else if(playerWin == true) cout<<"PLAYER WIN";
		else cout<<"DRAW";

	return 0;
}
