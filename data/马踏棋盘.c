#include <stdio.h>

int chess[12][12]={
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,0,0,0,0,0,0,0,0,-1,-1},
	{-1,-1,0,0,0,0,0,0,0,0,-1,-1},
	{-1,-1,0,0,0,0,0,0,0,0,-1,-1},
	{-1,-1,0,0,0,0,0,0,0,0,-1,-1},
	{-1,-1,0,0,0,0,0,0,0,0,-1,-1},
	{-1,-1,0,0,0,0,0,0,0,0,-1,-1},
	{-1,-1,0,0,0,0,0,0,0,0,-1,-1},
	{-1,-1,0,0,0,0,0,0,0,0,-1,-1},
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
}; 
int Move[8][2]={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
int H[64][3];
int top=-1,cnt=0;


void Horse();

void Print();

int main (void)
{
	int x,y;
	printf("��������ʼλ�ã�");
	scanf("%d%d",&x,&y);
	chess[x][y]=++cnt;
	top++;
	H[top][0]=x;
	H[top][1]=y;
	H[top][2]=0;
	Horse();
	Print();
	return 0;
}

void Horse()
{
	int a,b,i=0;
	while(cnt<64){
		for(;i<8;i++){
			a=H[top][0]+Move[i][0];
			b=H[top][1]+Move[i][1];
			if(chess[a][b]==0)	break;
		}
		if(i<8){
			chess[a][b]=++cnt;
			top++;
			H[top][0]=a;
			H[top][1]=b;
			H[top][2]=i;
			i=0;
		}
		else{
			chess[H[top][0]][H[top][1]]=0;
			i=H[top][2];
			i++;
			top--;cnt--;
		}
	}
}

void Print()
{
	int i,j;
	for(i=2;i<10;i++){
		for(j=2;j<10;j++)
			printf("%-3d",chess[i][j]);
		printf("\n");
	}
}


