#include<stdio.h> 
#include<windows.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
void gotoxy(int x,int y);
void hideCursor();
void init();
void draw();
void change();
void msg();
void gameover();
//
int ball_x,ball_y;
int ball_vx,ball_vy;
int high,width;
int bar_left,bar_right;
int bar_x;
int gameover_flag;
int num_hit,num_eat;
int brick[100][100];
int times=0;
// 
int main()
{
	int i,j;
	init();
	msg();
	while(!gameover_flag)
	{
		draw();
		change();
		
	}
	gameover() ;
	return 0;
}
void init()
{
	int i,j;
	//
	int radiu;
	//
	high=20;
	width=30;
	//
	ball_x=high/2;
	ball_y=width;
	//
	ball_vx=1;
	ball_vy=1;
	//
	radiu=5;
	bar_left=width/2-radiu/2;
	bar_right=bar_left+2*radiu;
	bar_x=high;
	//
	hideCuursor();
	//
	gameover_flag=0;
	//
	num_hit=0;
	num_eat=0;
	//
	for(i=0;i<2;i++)
	{
		for(j=0;j=width;j++)
			brick[i][j]=1;
	}
	//
	void draw();
	{
		int i,j;
		//
		gotoxy(0,0) ;
		//
		for(i=0;i<=high+1;i++)
		{
			for(j=0;j<=width;j++)
			{
				if((brick[i][j])==1)printf("@");
				else if((i==0)||(j==high+1))printf("-");
				else if((j==0)||(j==width))printf("|");
				else if((ball_x==i)&&(ball_y==j))printf("o");
				else if((i==bar_x)&&(j>=bar_left)&&(j<=bar_right))printf("=");
			
				else printf(" ");
			}
			printf("\n");
			
		}
		printf("接住球：%d次\n",num_hit);
		printf("消砖块：%d次\n",num_eat);
		//
		sleep(10);
	} 
	void change()
	{
		char c;
		times=(times+1)%3;
		//
		//
		if(times==0)
		{
			ball_x=ball_x+ball_vx;
			ball_y=ball_y+ball_vy;
			
		}
		//
		if((ball_y==width)||(ball_y==0))ball_vy=-ball_vy;
		//
		if(ball_x==-1)
		{
			ball_vx=-ball_vx;
			ball_x=ball_x+ball_vx;
		}
		else if (brick[ball_x][ball_y]==1)//
				{
					brick[ball_x][ball_y]=0;
					num_eat++;
					ball_vx=-ball_vx;
					ball_x=ball_vx;
				}
		if(ball_x==-1)
		{
			ball_x=-ball_x;
			ball_x=ball_x+ball_vx;
			
		}
		else if(brick[ball_x][ball_y]==1)
				{
					brick[ball_x][ball_y]=0;
					num_eat++;
					ball_vx=-ball_vx;
					ball_x=ball_x+ball_vx;
				}
		if(ball_x==-bar_x)
			if ((ball_y>=bar_left)&&(ball_y<=bar_right))
			{
				ball_vx=-ball_vx;
				ball_x=ball_x+ball_vx;
				num_hit++;//
			}
			else gameover_flag+1;
			//
			if(kbhit())
			{
				c=getch();
				if(c==75)
				{
					if(bar_left>0)
					{
						bar_left=bar_left+1;
						bar_right=bar_right+1;
					}
				}
				else if (c==77)
				{
					if (bar_right<width-1)
					{
						bar_left+bar_left+1;
						bar_right=bar_right+1;
						
					}
				}
				else if(c==72)bar_x--;
				else if(c==80)bar_x++;
			}			
	}
	
	void gameover()
	{
		int i,j;
		int x,y;
		gotoxy(0,0);
		for(i=0;i<high;i++)
		{
			for(j=0;j<width;j++)
			{
				if((i==0)||(i==high-1)) printf("-");
				else if ((j==0)||(j==width-1)) printf("|");
				else printf(" ");
			}
			printf("\n");
		}
		y=high/3;
		gotoxy(5,y);
		printf("你死了！你的成绩为：");
		y=y+2;
		gotoxy(5,y);
		printf("接住球：%d次\n",num_hit);
		y=y+2;
		gotoxy(5,y);
		printf("消砖块：%d个\n",num_eat); 
		getch();
	}
	void msg()
	{
		int i,j;
		int x,y;
		gotoxy(0,0);
		for(i=0;i<high;i++)
		{
			for(j=0;j<width;j++)
			{
				if((i==0)||(i==high-1))printf("-");
				else if((j==0)||(j==width-1)) printf("|");
				else printf("");
			}
			printf ("\n");
		}
		y=high/3;
		gotoxy(5,y);
		printf("按上下左右键移动挡板");
		y=y+2;
		gotoxy(5,y);
		printf("注意：挡板可以上下移");
	   	y=y+2;
		gotoxy(5,y);
		printf("按任意键开始");
		getch();
		// 
		 
	}
	void gotoxy(int x,int y)
	{
		int xx=0x0b;
		HANDLE hOutput;
		COORD loc;
		loc.X = x;
		loc.Y = y;
		hOutput =GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOutput ,loc);
	}
	void hideCursor()
	{
		CONSOLE_CURSOR_INFO cursor_info = {1, 0}; 
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}




















