#include "math.h"
#include "stdio.h"
void ZFLX(char chara){/*判断字符类型 ZFLX=字符类型*/
	if (chara==' '||chara=='\n') printf("the character \'%c\' is kongge or enter\nASCII is %d\n",chara,chara);
	else if (chara>='0'&&chara<='9') printf("the charaacter \'%c\' is number\nASCII is %d\n",chara,chara);
	else if ((chara>='a'&&chara<='z')||(chara>='A'&&chara<='Z')) printf("the charaacter \'%c\' is a letter\nASCII is %d\n",chara,chara);
	else printf("the chara \'%c\'  is another\nASCII is%d\n",chara,chara);
}

void ax2(float a,float b,float c){/*解方程*/
	float d,x1,x2;
	if(a==0&&b==0)printf("argument error\n");
	if(a==0&&b!=0)printf("x=%-4.2f\n",-c/b);
	if(a!=0)
		{d=b*b-4*a*c;
		if (d>0){
			x1=(-b+sqrt(d))/2./a;
			x2=(-b-sqrt(d))/2./a;
			printf("x1=%-.2f,x2=%-.2f\n",x1,x2);}
		else if(d==0){
			x1=(-b+sqrt(d))/2./a;
			printf("x1=x2=%-.2f\n",x1);}
		else{
			x1=-b/2./a;
			x2=sqrt(-d)/2./a;
			printf("x1=%-.2f+(%-.2f)i,x2=%-.2f-(%.2f)i\n",x1,x2,x1,x2);
			}
		}
}

void cac(float a,char ch,float b){/*计算器*/
	float result;
	if(ch=='+') printf("%-.2f%c%-.2f=%-.2f\n",a,ch,b,a+b);
	else if(ch=='-') printf("%-.2f%c%-.2f=%-.2f\n",a,ch,b,a-b);
	else if(ch=='*') printf("%-.2f%c%-.2f=%-.2f\n",a,ch,b,a*b);
	else if(ch=='/') if(b>1e-6)printf("%-.2f%c%-.2f=%-.2f\n",a,ch,b,a/b);
			        else printf("?/0\n");
	else printf("please input correct +,-,*,/\n");
}

int main(){
	return 0;
}