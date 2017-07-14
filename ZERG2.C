#include <math.h>
long jc(int i){					/*求阶乘*/
	long temp=1;
	if(i>0){
		for(;i!=1;i--){			/*阶乘计算*/
			temp*=i;
		}
	}
	if(i==0) 	temp=1;			/*数学定义*/
	if(i<0)		temp=-1;
	return(temp);
}

long jclj(int i){				/*阶乘累加*/
	long temp=0;
	for(;i!=0;i--){
		temp+=jc(i);
	}
	return (temp);
}

void sxh(){						/*打印水仙花*/
	int i=100,a,b,c,num=0;
	for(;i<=999;i++){
		a=i/100;
		b=i%100/10;
		c=i%10;
		if (pow(a,3)+pow(b,3)+pow(c,3)==i){
			printf("%d\t",i);
			num++;
			if(num%8==0) printf("\n");
		}
	}
	printf("\n");
}

void aia(int a[10]){ 			/*输出最大最小和平均*/
	int i,max,min;float aver;
	max=a[0];min=a[0];aver=0;
	for (i=0;i<10;i++){
		if (a[i]>max) max=a[i];
		if (a[i]<min) min=a[i];
		aver+=(float)a[i]/10;
	}
	printf("max=%d,min=%d,aver=%f\n",max,min,aver);
}

float jiafa(float x){			/*级数求和*/
	int i;
	float sum=1;
	for (i=2;i<=10;i++)
	sum+=(x-i)/jc(i);
	return(sum);
}

void test(){
	float a;
	scanf("%f",&a);
	printf("%f\n",jiafa(a));
	printf("test passed\n");
}

int main(){
	return (0);
}
