#include <math.h>
#include <stdio.h>
#include <string.h>
#define TS printf("test")
#define N 10
int cont;
void m_p(float m[9][10],int n){						/*���������� */
	int i,j;
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++) {
			printf("%fx%d+",m[i][j],j);
			if (j==n-1) printf("\b");
		}
		printf("=%f\n",m[i][n]);
	}
	}

void m_2k4(float m[9][10],int l1,float k,int l2){	/*�����*/
	int i;
	for(i=0;i<=9;i++)
		m[l1][i] += k*m[l2][i];
}

void m_xy(float m[9][10],int x,int y){				/*����*/
	if(x!=y) m_2k4(m,x,-m[x][y]/m[y][y],y);
}

void m_solve(){										/*�ⷽ��**/
	int n,i,j;
	float m[9][10],temp;
	char tf;
	/*��������*/
	printf("������δ֪��x�ĸ���\n");
	scanf("%d",&n);
	printf("���뷽�̶�Ӧ����\n��\t3x1+2x2=5\n\t2x1+3x2=5\n������\t3   2   5\n\t2   3   5\n");
	
	for(i=0;i<n;i++)
		for(j=0;j<=n;j++){
			scanf("%f",&temp);
			m[i][j]=temp;}
	/*���� ���̼�� �޷����
	printf("please check the equations");
	m_p(m,n);
	printf("please input <T/F> \n");
	tf=getchar();
	if(tf=='t'||tf=='T') 
	*/
	
	
	for(i=0;i<n;i++)/*���Խ��߷�0��*/
		if(fabs(m[i][i])<1e-6)
			for(j=0;j<n;j++)
				if(fabs(m[i][j])>1e-6)
					m_2k4(m,i,1,j);
	for(j=0;j<n-1;j++){/*�����ǻ�*/
		if(fabs(m[j][j])<1e-6)
			for(i=1;i<n;i++)
				if(fabs(m[i][j])>1e-6)
					{m_2k4(m,j,1,i);break;}/*ȱ�ȼ���*/
		if(fabs(m[j][j])<1e-6){printf("lack of ordo\npurse anykey to continue");i=getchar();return;}
		for(i=j+1;i<n;i++){
			m_xy(m,i,j);
		}
	
	}
	
	for(j=n-1;j>0;j--)/*�Խ��߻�*/
		for(i=0;i<j;i++)
			m_xy(m,i,j);

	for(i=0;i<n;i++){
		temp=m[i][n]/m[i][i];
		printf("x%d=%-4.2f\n",i+1,temp);
	}
}
/***************************************************************************************************/
void ipst(char *p1,char *p2){						/*�����ַ�*/
	printf("����2���ַ��� (������20�ַ�)\n");
	scanf("%s",p1);
	scanf("%s",p2);
}

int stl(char *p){									/*���㳤�� ������\0*/
	int i=0;
	while(*(p+i)) i++;
	return i;
}

void add(char *og,char *nw){						/*����*/
	int i;
	char *end=og+stl(og);
	for(i=0;;i++){
		*(end+i)=*(nw+i);
		if(!*(nw+i)) break;
	}
}

void cop(char *og,char *nw){						/*����*/
	int i;
	for(i=0;;i++){
		*(og+i)=*(nw+i);
		
		if(!*(nw+i)) break;
	}
}

void str(int k){									/*�ַ�������*/
	int i;
	char pa[20],pb[20];
	ipst(pa,pb);
	if(k==21) cop(pa,pb);
	if(k==22) add(pa,pb);
	printf("�ַ���1:");printf("%s\n",pa);
	printf("�ַ���2:");printf("%s\n",pb);
}
/***************************************************************************************************/
void u_input(int a[N]){
	int i;
	printf("����%d������(����ֵ������%d)\n",N,65536/2-1);
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

void u_pl(int base[N]){								/*����*/
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

void u_find(int num){									/*�۰����*/
	int p[N],tf,n=N;
	int max=n-1,min=0,mid,f=0;
	u_pl(p);
	if(num==31){u_pr(p);}
	
	if(num==32){
		printf("������Ҫ���ҵ�����\n");
		scanf("%d",&tf);
		while(min<=max){
			mid=(max+min)/2;
			if(*(p+mid)==tf){printf("��������%d\n",tf);f=1;break;}
			if(*(p+mid)<tf) min=mid+1;
			if(*(p+mid)>tf) max=mid-1;
			
		}
		if(f==0) printf("����������%d\n",tf);
	}

}
/***************************************************************************************************/
void menu(int num){/*3 4 8*/
	int i=0;
	char temp;
	printf("=====================\n");
	printf("10.�ⷽ��.\n");
	printf("20.�ַ�������(�ں����� ����)\n");
	if(num==20||num==21||num==22){
		printf("\t21.����\n");
		printf("\t22.����\n");
	}
	printf("30.���ֲ���(�ں����� ���� ���)\n");
	if(num==30||num==31||num==32||num==33){
	printf("\t31.����\n");
	printf("\t32.����\n");
	printf("\t33.���\n");
	}
	printf("0.�˳�����\n");
	printf("=====================\n");
	if(num==10) {m_solve();i=1;}
	if(num==21||num==22) {str(num);i=1;}
	if(num==31||num==32) {u_find(num);i=1;}
	if(num==33){u_sum();i=1;}
	cont=i;
	if(i){
		printf("�������������Լ���...\n");
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