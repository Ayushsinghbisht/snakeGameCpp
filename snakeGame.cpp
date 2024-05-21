
#include<iostream>
using namespace std;
#include<conio.h>

 bool gameOver;
 const int width=40;
 const int height=20;
 enum edirection {STOP=0,LEFT,RIGHT,UP,DOWN};
 edirection dir;
 int x,y,fruitX,fruitY,score,tail=0;
 int tailX[100],tailY[200];



void setUp(){
    system("cls");
 gameOver=false;
 dir=STOP;
 x=width/2;
 y=height/2;
 fruitX=rand()%width;
 fruitY=rand()%height;
 score=0;
 

}
void border(){

	system("cls");
    for(int i=0;i<width;i++)
    {
        cout<<"#";
    }
    cout<<endl;
    for(int i=0;i<height;i++)
    {
    	for(int j=0;j<width;j++)
    	{
			
    		if(j==0 || j==width-1) cout<<"#";
            else if(i==y && j==x) cout<<"O";
            else if(j==fruitX && i==fruitY) cout<<"F";
       		else 
			{
				bool print=true;
				for(int k=0;k<tail;k++)
				{
					if(tailX[k]==j && tailY[k]==i)
					{
						cout<<"o";
						print=false;
					}
					
				}
				if(print)
					cout<<" ";


			}
            
		}
		cout<<endl;
	}
 for(int i=0;i<width;i++)
    {
        cout<<"#";
    }
	cout<<"\n"<<"score: "<<score;
}
void input(){

if(_kbhit())
{
	switch(_getch())
	{
		case 'a':
			dir=LEFT;
			break;
		case 'd':
			dir=RIGHT;
			break;
		case 'w':
			dir=UP;
			break;
		case 's':
			dir=DOWN;
			break;
		case 'x':
			gameOver=true;
			break;
		
		
	}

}
}

void logic(){
int prevX,prevPrevX,prevY,prevPrevY;
	prevX=tailX[0];
	tailX[0]=x;
	prevY=tailY[0];
	tailY[0]=y;
	for(int k=1;k<tail;k++)
	{
		prevPrevX=tailX[k];
		tailX[k]=prevX;
		prevX=prevPrevX;
		prevPrevY=tailY[k];
		tailY[k]=prevY;
		prevY=prevPrevY;

	}
	
	switch (dir)
	{
	
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
		
	}
	if(x==fruitX && y==fruitY)
	{
		score+=10;
		tail++;
		fruitX=rand()%width;
 fruitY=rand()%height;
	}
	for(int u=0;u<tail;u++)
	{
		if(x==tailX[u] && y==tailY[u])
		{
			gameOver=true;
		}
	}
	if(x<=0 || x> width-1 ||y<0||y>height-1)
	{
		
		gameOver=true;
	}

}

int main(){
  setUp();
while(!gameOver)
{
  
    border();
    input();
    logic();
}

}