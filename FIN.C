#include <math.h>
#include <stdio.h>
#include <string.h>
#define TS printf("test")
#define N 10
int cont;
void m_p(float m[9][10],int n){						/*输出增广矩阵 */
	int i,j;
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++) {
			printf("%fx%d+",m[i][j],j);
			if (j==n-1) printf("\b");
		}
		printf("=%f\n",m[i][n]);
	}
	}

void m_2k4(float m[9][10],int l1,float k,int l2){	/*行相加*/
	int i;
	for(i=0;i<=9;i++)
		m[l1][i] += k*m[l2][i];
}

void m_xy(float m[9][10],int x,int y){				/*清零*/
	if(x!=y) m_2k4(m,x,-m[x][y]/m[y][y],y);
}

void m_solve(){										/*解方程**/
	int n,i,j;
	float m[9][10],temp;
	char tf;
	/*参数输入*/
	printf("请输入未知数x的个数\n");
	scanf("%d",&n);
	printf("输入方程对应参数\n如\t3x1+2x2=5\n\t2x1+3x2=5\n则输入\t3   2   5\n\t2   3   5\n");
	
	for(i=0;i<n;i++)
		for(j=0;j<=n;j++){
			scanf("%f",&temp);
			m[i][j]=temp;}
	/*添加 方程检查 无法完成
	printf("please check the equations");
	m_p(m,n);
	printf("please input <T/F> \n");
	tf=getchar();
	if(tf=='t'||tf=='T') 
	*/
	
	
	for(i=0;i<n;i++)/*主对角线非0化*/
		if(fabs(m[i][i])<1e-6)
			for(j=0;j<n;j++)
				if(fabs(m[i][j])>1e-6)
					m_2k4(m,i,1,j);
	for(j=0;j<n-1;j++){/*上三角化*/
		if(fabs(m[j][j])<1e-6)
			for(i=1;i<n;i++)
				if(fabs(m[i][j])>1e-6)
					{m_2k4(m,j,1,i);break;}/*缺秩检验*/
		if(fabs(m[j][j])<1e-6){printf("lack of ordo\npurse anykey to continue");i=getchar();return;}
		for(i=j+1;i<n;i++){
			m_xy(m,i,j);
		}
	
	}
	
	for(j=n-1;j>0;j--)/*对角线化*/
		for(i=0;i<j;i++)
			m_xy(m,i,j);

	for(i=0;i<n;i++){
		temp=m[i][n]/m[i][i];
		printf("x%d=%-4.2f\n",i+1,temp);
	}
}
/***************************************************************************************************/
void ipst(char *p1,char *p2){						/*输入字符*/
	printf("输入2个字符串 (不超过20字符)\n");
	scanf("%s",p1);
	scanf("%s",p2);
}

int stl(char *p){									/*计算长度 不包括\0*/
	int i=0;
	while(*(p+i)) i++;
	return i;
}

void add(char *og,char *nw){						/*连接*/
	int i;
	char *end=og+stl(og);
	for(i=0;;i++){
		*(end+i)=*(nw+i);
		if(!*(nw+i)) break;
	}
}

void cop(char *og,char *nw){						/*覆盖*/
	int i;
	for(i=0;;i++){
		*(og+i)=*(nw+i);
		
		if(!*(nw+i)) break;
	}
}

void str(int k){									/*字符串处理*/
	int i;
	char pa[20],pb[20];
	ipst(pa,pb);
	if(k==21) cop(pa,pb);
	if(k==22) add(pa,pb);
	printf("字符串1:");printf("%s\n",pa);
	printf("字符串2:");printf("%s\n",pb);
}
/***************************************************************************************************/
void u_input(int a[N]){
	int i;
	printf("输入%d个整数(绝对值不超过%d)\n",N,65536/2-1);
	for(i=0;i<N;i++)
		scanf("%d",&a[i]);
}

int u_sum(){
	int a[N],i,sum=0;
	u_input(a);
	for(i=0;i<N;i++){
		sum+=a[i];
	}
	printf("sum=%d\n",sum);
	return sum;
}

void u_pr(int base[N]){int i;for(i=0;i<N;i++) printf("%d\n",base[i]);}

void u_pl(int base[N]){								/*排列*/
	int i,j,*p,temp;
	u_input(base);
	for(i=0;i<N;i++){
		p=base+i;
		for(j=i+1;j<N;j++){
		if(*p>base[j]) p=base+j;
		}
		temp=base[i];base[i]=*p;*p=temp;
	}
	
}

void u_find(int num){									/*折半查找*/
	int p[N],tf,n=N;
	int max=n-1,min=0,mid,f=0;
	u_pl(p);
	if(num==31){u_pr(p);}
	
	if(num==32){
		printf("输入需要查找的整数\n");
		scanf("%d",&tf);
		while(min<=max){
			mid=(max+min)/2;
			if(*(p+mid)==tf){printf("存在数字%d\n",tf);f=1;break;}
			if(*(p+mid)<tf) min=mid+1;
			if(*(p+mid)>tf) max=mid-1;
			
		}
		if(f==0) printf("不存在数字%d\n",tf);
	}

}
/***************************************************************************************************/
void menu(int num){/*3 4 8*/
	int i=0;
	char temp;
	printf("=====================\n");
	printf("10.解方程.\n");
	printf("20.字符串操作(内含覆盖 连接)\n");
	if(num==20||num==21||num==22){
		printf("\t21.覆盖\n");
		printf("\t22.连接\n");
	}
	printf("30.数字操作(内含排列 查找 求和)\n");
	if(num==30||num==31||num==32||num==33){
	printf("\t31.排列\n");
	printf("\t32.查找\n");
	printf("\t33.求和\n");
	}
	printf("0.退出程序\n");
	printf("=====================\n");
	if(num==10) {m_solve();i=1;}
	if(num==21||num==22) {str(num);i=1;}
	if(num==31||num==32) {u_find(num);i=1;}
	if(num==33){u_sum();i=1;}
	cont=i;
	if(i){
		printf("输入任意数字以继续...\n");
		scanf("%d",&i);
	}
}

int main(){
	int k=1;
	while(k){
		cont=0;
		system("cls");
		menu(k);
		if(!cont)
			scanf("%d",&k);
		else
			k=1;
	}
	return 0;
}
