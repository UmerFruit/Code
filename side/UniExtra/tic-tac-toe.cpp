/*
	16-December-2022
	Made by Umer Farooq
	Game of Tic-Tac-Toe
*/
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
void fill(int board[][3]);
void end (char winner);
bool checkwin(int board[][3],char &winner);
void input(int board[][3]);
void displayBoard(int board[][3]);
void displayBoardend(int board[][3]);
void game();
int main()
{
	int choice;
	int count=0;
	srand(time(0));

	cout<<setw(30)<<setfill('*')<<" "<<endl;
	cout<<"WELCOME TO TIC-TAC TOE GAME\n";
	cout<<setw(30)<<setfill('*')<<" "<<endl;
	cout<<"Enter 1 to Play\n\tOR\nEnter 0 to Exit\n";
	cin>>choice;
	
	
	
	do
	{
		if(count>0)
		{
			cout<<"Would you like to Play Another Game?"<<endl;
			cin>>choice;
			while(choice != 1 && choice != 0)
			{
				cout<<"Invalid Input\nPlease Enter Again"<<endl;
				cin>>choice;
			}
		}
		system("clear");
		if(choice)
		{
			game();
			count++;
		}
		else
		{
			cout<<"THANK YOU FOR PLAYING"<<endl;
			cout<<"Made by Umer Barood"<<endl;
		}
	}while(choice!= 0);
	
	
	

}
void end (char winner)
{
	
	if(winner== 'P')
	{
		cout<<"The winner is Player."<<endl;
	}
	else
	{
		cout<<"The winner is Computer."<<endl;
	}
	
}
void fill(int board[][3])
{
	for(int i=0;i<3;i++)
	{
		for (int j=0; j < 3; j++)
		{
			board[i][j] = ((i+1) *10) + (j+1);
		}
		
	}
}
bool checkwin(int board[][3],char &winner)
{
	bool r[3]={0},c[3]={0},diagonal[2]={0};
	int j=2,k=0;
		for(int i=0;i<3;i+=2)
		{
			diagonal[k] = (board[0][i] == board [1][1]) && board[0][i] == board [2][j];
			j -= 2;
			k++;
		}
	for(int i=0;i<3;i++)
	{
		
		for (int j = 1; j<= 1; j++)
		{
			if(board[i][0] == board [i][j] && board[i][0] == board [i][j+1])
			{
				r[i] = true;
			}
			else
			{
				r[i] = false;
			}
			if(board[0][i] == board [j][i] && board[0][i] == board [j+1][i])
			{
				c[i] = true;
			}
			else
			{
				c[i] = false;
			}
		}
	}	
	for(int i=0;i<3;i+=1)
	{
		if(r[i])
		{
			if(board[i][0] == 'X')
				winner = 'P';
			else
				winner = 'C';
			
			return true;
		}
		if(c[i])
		{
			if(board[0][i] == 'X')
				winner = 'P';
			else
				winner = 'C';
			
			return true;
		}
		for(int j=0;j<2;j++)
		{
			if(diagonal[j])
			{
				if(board[1][1] == 'X')
					winner = 'P';
				else
					winner = 'C';
				
				return true;
			}
		}
			
	}
	return false;
}
void input(int board[][3])
{
	int userr,userc,compc,compr,userin,compin;
	cout<<"Which square would you like to choose?\n";
	cin>>userin;
	userr= userin/10; 
	userc= userin%10; 
	while (!((userr>0 && userr<4) || (userc>0 && userc<4)))
	{
		cout<<"Invalid. Enter again"<<endl;
		cin>>userin;
		userr= userin/10; userr--;
		userc= userin%10; userc--;
	}
	userr--;
	userc--;
	if(board[userr][userc] != 79 && board[userr][userc] != 88)
	{
		board[userr][userc] = 88;
	}
	else
	{
		while (board[userr][userc] == 79 || board[userr][userc] == 88)
		{
			cout<<"Invalid. Enter again"<<endl;
			cin>>userin;
			userr= userin/10; userr--;
			userc= userin%10; userc--;
		}
		board[userr][userc] = 88;
		
	}
	do
	{
		compc = rand() % 3;
		compr = rand() % 3;
	}while(board[compr][compc] == 79 || board[compr][compc] == 88);
	board[compr][compc] = 79;
	
}
void displayBoard(int board[][3])
{
	int rnum,cnum;
	
	for(int i=0;i<3;i++)
	{
		for (int j=0; j < 3; j++)
		{
			if(board[i][j] != 79 && board[i][j] != 88)
			{
				rnum = board[i][j]/10;
				cnum = board[i][j]%10;
				cout<<rnum<<","<<cnum<<"\t";
			}
			else
			{
				if(board[i][j] == 79)
					cout<<"O\t";
				else
					cout<<"X\t";
			}
		}
		cout<<endl;
	}
}
void displayBoardend(int board[][3])
{
	cout<<setw(20)<<setfill('*')<<" "<<endl;
	cout<<"Final Board : "<<endl;
	cout<<setw(20)<<setfill('*')<<" "<<endl;
	displayBoard(board);
}
void game()
{
	int board[3][3]={0},counter=0;
	char winner;
	fill(board);
	bool check=false;
	while(!check && counter < 8)
	{
		cout<<setw(20)<<setfill('*')<<" "<<endl;
		cout<<"Current Board : "<<endl;
		cout<<setw(20)<<setfill('*')<<" "<<endl;
		displayBoard(board);
		input(board);
		system("clear");
		check = checkwin(board,winner);
		counter++;
	}
	displayBoardend(board);
	end(winner);
	
}