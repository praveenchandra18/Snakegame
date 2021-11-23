#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
using namespace std;
static int score=0;
string name;

//This function displays the game

void gameboard(char arr[20][20])
{
	cout<<name<<"\t\t";
	cout<<"score = "<<score<<endl;
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<20;j++)
		{
			cout<<arr[i][j];
		}
		cout<<"\n";
	}
}


int game(int sx=9,int sy=9,int fx=2,int fy=2)
{
	char graph[20][20];
	for (int  i=0;i<20;i++)
	{
		for(int j=0;j<20;j++)
		{
			if( i==0 || i==19 || j==0 || j==19 )
			{
				graph[i][j]='*';
			}
			else if(i==sx && j==sy)
			{
				graph[i][j]='+';
			}
			else if(i==fx && j==fy)
			{
				graph[i][j]='0';
			}
			else
			{
				graph[i][j]=' ';
			}
		}
	}
	gameboard(graph);
	return 0;
}


int main()
{
	static int sx=9,sy=9;
	int fx=2,fy=2;
	char m;
	cout<<"Enter the name";
	cin>>name;
	game();
	srand(time(0));
	while(1)
	{
		m=getch();
		if(m=='w')
		{
			sx=sx-1;
			sy=sy;
		}
		else if(m=='a')
		{
			sy=sy-1;
			sx=sx;
		}
		else if(m=='s')
		{
			sx++;
			sy=sy;
		}
		else if(m=='d')
		{
			sy++;
			sx=sx;
		}
		system("cls");
		if(fx==sx && fy==sy)
		{
			fx=(rand()%18)+1;
			fy=(rand()%18)+1;
			score++;
		}
		if(sx==0 || sy==0 || sx==19 || sy==19)
		{
			cout<<"game over";
			return 0;
		}
		game(sx,sy,fx,fy);
	}
	return 0;
}
