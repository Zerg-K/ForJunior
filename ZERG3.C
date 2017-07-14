#define BEG printf("\n#############it\'s the beginning of the program#############\n")
#define END printf("################it\'s the end of the program################\n")
#define G 3
#define M 2
#include "math.h"
void _9x9(){
	int i,j;
	for(i=0;i<=9;i++){
		for(j=0;j<=9;j++){
			if(i==0){
				if(j==0) printf("*");
				else printf("   %d    ",j);
				if(j==9) printf("\n");}
			else
				if(j==0) printf("%d",i);
				else
					if(j<=i) printf("%2d*%d=%2d ",j,i,j*i);
					else{printf("\n");break;}
		}
	}
	printf("\n");
}

void _4(int n){
	int i,j;
	for(i=1-n;i<=n-1;i++){
		for(j=1-n;j<=n-1;j++)
			if(abs(i)+abs(j)<=n-1) printf("*");
			else printf(" ");
	printf("\n");
	}
	printf("\n");
}

int _buy(int money,int num){
	int g,m,_3x,time=0;
	for(g=1;g<=money/G;g++)
		for(m=1;m<=(money-G*g)/M;m++){
			_3x=money-G*g-M*m;
			if(g+m+3*_3x==num) {time++;printf("%d %d %d\n",g,m,3*_3x);}
		}
		return time;
}

void test(){
	printf("%d\n",_buy(100,100));
}

int main(){
	return 0;
}
