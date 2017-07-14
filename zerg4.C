#define N 10
#include <string.h>
#include <stdio.h>
void bulu(int *p){				/*冒泡排列*/
	int i,j,temp;int n=N;
	for (j=0;j<n-1;j++)
		for(i=j;i<n-1;i++){
			if (*(p+i)>*(p+i+1))
				temp=*(p+i);*(p+i)=*(p+i+1);*(p+i+1)=temp;
			}
}

void mj(int *p){				/*枚举排序*/
	int temp,i,j;int n=N;
	for(j=0;j>=0;j++)
		for(i=j;i<=n-1;i++){
			if(*(p+j)>*(p+i)){
				temp=*(p+j);*(p+j)=*(p+i);*(p+i)=temp;
			}
		}
		
}

void poi(int *p){				/*指针排序未完成*/
	int temp,i,j,*m;int n=N;
	for(j=0;j<n;j++){
		m=p+j;
		for(i=j;i<n;i++)
			if(*m>*(p+i))
				m=p+i;
		temp=*m;*m=*(p+j);*(p+j)=temp;
	}
}

void find(int *p,int tf){		/*折半查找*/
	int n=N;
	int max=n-1,min=0,mid,f=0;
	mj(p);
	while(min<=max){
		mid=(max+min)/2;
		if(*(p+mid)==tf){printf("exist\n");f=1;break;}
		if(*(p+mid)<tf) min=mid+1;
		if(*(p+mid)>tf) max=mid-1;
		
	}
	if(f==0)printf("error\n");
}

int stl(char *p){				/*计算长度 不包括\0*/
	int i=0;
	while(*(p+i)) i++;
	return i;
}

void add(char *og,char *nw){	/*连接*/
	int i;
	char *end=og+stl(og);
	for(i=0;;i++){
		*(end+i)=*(nw+i);
		if(!*(nw+i)) break;
	}
}

void cop(char *og,char *nw){	/*覆盖*/
	int i;
	for(i=0;;i++){
		*(og+i)=*(nw+i);
		
		if(!*(nw+i)) break;
	}
}

int main(){
	return 0;
}
