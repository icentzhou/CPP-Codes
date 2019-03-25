#include<iostream>
using namespace std;
bool check(int a[][9],int i,int j);
void tryij(int a[][9],int i,int j);
void init(int a[][9]);
void output(int a[][9]);
int sss=0;
int main(){
//	freopen("data.txt","w",stdout); 
	int a[9][9]={
		{0,5,6,0,0,0,0,0,0},
		{0,0,0,8,0,6,0,0,0},
		{0,0,4,0,3,0,9,0,0},
		{0,8,0,5,0,0,0,0,1},
		{0,0,0,0,1,0,0,6,0},
		{2,0,0,0,4,0,0,0,5},
		{5,6,0,7,0,0,0,0,4},
		{0,7,8,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,8}};
/*	int a[9][9]={
		{0,0,2,5,0,0,3,7,0},
		{0,7,0,0,3,2,0,0,5},
		{5,3,0,7,6,0,0,2,9},
		{0,0,3,4,2,7,0,5,8},
		{0,0,7,0,0,0,0,3,2},
		{2,5,0,0,0,3,9,0,7},
		{7,2,0,3,0,9,5,0,0},
		{8,9,0,2,0,0,7,0,3},
		{3,0,5,0,7,0,2,9,6}};*/
/*	int a[9][9]={
		{9,0,0,0,5,0,0,0,2},
		{0,0,5,0,0,7,6,0,0},
		{0,1,4,0,0,3,5,9,0},
		{0,4,1,0,3,0,0,0,0},
		{7,0,0,5,2,4,0,0,1},
		{0,0,0,0,6,0,9,5,0},
		{0,9,2,6,0,0,8,1,0},
		{0,0,8,3,0,0,2,0,0},
		{3,0,0,0,1,0,0,0,9}};*/
//	init(a);
	tryij(a,0,0);
	return 0;
}
void init(int a[][9])
{
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			a[i][j]=0;
	//初始化
	a[0][1]=5;
	a[0][2]=6;
	a[1][3]=8;
	a[1][5]=6;
}
void tryij(int a[][9],int i,int j)
{
//	cout<<i<<", "<<j<<endl;
	if(a[i][j]!=0)
	{
		if(i==8&&j==8)
		{
			if (check(a,i,j))
			{
				output(a);//成了
				return;
			}
			else
				cout<<"无解"<<endl;
		}
		else if(j==8)//下一行
		{
			tryij(a,i+1,0);
		}
		else
		{
			tryij(a,i,j+1);
		}
	}
	else
	{
		for(int k=1;k<=9;k++)
		{
			a[i][j]=k;
//			if(a[0][1]==8 && a[0][2]==7 && a[0][3]==4&&a[0][5]==6)
//				sss=1;
			if(check(a,i,j))
			{
				if(i==8&&j==8)
				{
					output(a);
					system("pause");
//					return;
				}
				else if(j==8)
					tryij(a,i+1,0);
				else
					tryij(a,i,j+1);
			}
			else
			{
				if(sss){
					cout<<"("<<i<<", "<<j<<")\n";
					output(a);
//					system("pause");
				}
			}
		}
		a[i][j]=0;
	}
}
void output(int a[][9])
{
	for (int i=0;i<9;i++)
	{
		for (int j=0;j<9;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
bool check(int a[][9],int i,int j)
{
	int x,y;
	//方块内
	if (i<3 && j<3)
	{
		for(x=0;x<3;x++)
			for(y=0;y<3;y++)
				if((x!=i||y!=j)&&a[x][y]==a[i][j])
					return false;
	}
	else if (i<3 && j>=3 && j<=5)
	{
		for(x=0;x<3;x++)
			for(y=3;y<6;y++)
				if((x!=i||y!=j)&&a[x][y]==a[i][j])
					return false;
	} 
	else if (i<3 && j>=6 && j<=8)
	{
		for(x=0;x<3;x++)
			for(y=6;y<9;y++)
				if((x!=i||y!=j)&&a[x][y]==a[i][j])
					return false;
	}
	else if (i>=3 && i<=5 && j<3)
	{
		for(x=3;x<6;x++)
			for(y=0;y<3;y++)
				if((x!=i||y!=j)&&a[x][y]==a[i][j])
					return false;
	}
	else if (i>=3 && i<=5 && j>=3 && j<=5)
	{
		for(x=3;x<6;x++)
			for(y=3;y<6;y++)
				if((x!=i||y!=j)&&a[x][y]==a[i][j])
					return false;
	} 
	else if (i>=3 && i<=5 && j>=6 && j<=8)
	{
		for(x=3;x<6;x++)
			for(y=6;y<9;y++)
				if((x!=i||y!=j)&&a[x][y]==a[i][j])
					return false;
	}
	else if (i>=6 && i<9 && j<3)
	{
		for(x=6;x<9;x++)
			for(y=0;y<3;y++)
				if((x!=i||y!=j)&&a[x][y]==a[i][j])
					return false;
	}
	else if (i>=6 && i<9 && j>=3 && j<=5)
	{
		for(x=6;x<9;x++)
			for(y=3;y<6;y++)
				if((x!=i||y!=j)&&a[x][y]==a[i][j])
					return false;
	} 
	else if (i>=6 && i<9 && j>=6 && j<=8)
	{
		for(x=6;x<9;x++)
			for(y=6;y<9;y++)
				if((x!=i||y!=j)&&a[x][y]==a[i][j])
					return false;
	}
	//横竖
	for (x=0;x<9;x++)
		if (x!=i && a[x][j]==a[i][j])
			return false;
	for (y=0;y<9;y++)
		if (y!=j && a[i][y]==a[i][j])
			return false;
	//斜
/*	if (i==j)
		for (x=0;x<9;x++)
			if (x!=i && a[x][x]==a[i][j])
				return false;
	if (i+j==8)
		for (x=0;x<9;x++)
			if (x!=i && a[x][8-x]==a[i][j])
				return false;*/
	return true;
}
