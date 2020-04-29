#include<iostream>
//#include<string.h>//memset
//#include<cstring>
//#include<stdio.h>//NULL
#define n 15
//#include<error.h> 
using namespace std;

class matrixchain
{
	int* p;
	int (* m)[n + 1];//��ά
	int (* s)[n + 1];
public:
	matrixchain() {
	p = new int[n + 1];
	m = new int[n + 1] [n + 1];
	s = new int[n + 1] [n + 1];
	for(int i = 0; i < n + 1; i++) p[i] = 0;
	for(int i = 0; i < n + 1; i++)
	for(int j = 0; j < n + 1; j++)
	{
		m[i][j] = 0;
	}
	for(int i = 0; i < n + 1; i++)
	for(int j = 0; j < n + 1; j++)
	{
		s[i][j] = 0;
	}

/*	memset(p,NULL,sizeof(p));
	memset(m,NULL,sizeof(m));
	memset(s,NULL,sizeof(s));
*/
	} 
	void Input(){
	cout<<"������"<<n<<"������ĸ��ԵĹ�ģ��p0��p1��p"<<n<<": ";
	for(int i = 0; i < n + 1; i++)
	cin>>p[i];
	}
	void p_disp(){
		cout<<n<<"������Ĺ�ģ����Ϊ��";
	for(int i = 0; i <= n; i++)
		cout<<p[i]<<" ";
	cout<<endl<<endl;		
	}
	void m_disp(){	
	cout<<"����ֵ����m��"<<endl;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++)
			cout<<m[i][j]<<"\t";
		cout<<endl;
	}
	cout<<endl;
	} 
	void s_disp(){
		cout<<"��¼����ֵ�Ͽ�λ�õ�����s��"<<endl;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++)
			cout<<s[i][j]<<"\t";
		cout<<endl;
	}
	cout<<endl;
	}
	void MatrixChain();
	void Traceback(int i, int j);
	~matrixchain(){
	delete p;
	delete []m;
	delete []s;
	}
};

//������������˻����㷨
/*void matrixMultiply(int* a, int* b, int* c, int ra, int ca, int rb, int cb)
{
	if(ca != rb) error("���󲻿ɳ�");
	for(int i = 0; i < ra; i++)
		for(int j = 0; j < cb; j++) {
			int sum = a[i][0] * b[0][j];
			for(int k = 1; k < ca; k++)
				sum += a[i][k] * b[k][j];
			c[i][j] = sum;
		}
} 
 */ 

 //��������ֵ������
 void matrixchain::MatrixChain() 
 //p���ڴ洢��������Ĺ�ģ��nΪ����ĸ�������ά����洢����ֵ����ά����s�洢ȡ����ֵʱ�Ӿ���ָ��λ��k 
 //Ϊ���о����㣬����m�� i = 1 ��j = 1 ��ʼ�洢��p�� k = 0 ��ʼ�洢 
 {
 	for(int i = 1; i <= n; i++) m[i][i] = 0;
 	for(int r = 2; r <= n; r++)
 		for(int i = 1; i <= n - r + 1; i++){
 			int j = i + r - 1;
 			m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
 			s[i][j] = i;
 			for(int k = i + 1; k < j; k++){
 				int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
 				if(t < m[i][j]) {
 					m[i][j] = t;
 					s[i][j] = k;
				 }
			}
  } 
}
  
//�����ʼ�����������ڽ�����ά����m����ά����s��һά����p���ڴ洢�����ģ��������Ҫʵ�ʼ��������˻����ֵ������ʼ������a��b��c �� 
//�������뺯�����������ݰ��� p���飨ÿ������Ĺ�ģ�����������n����������������a��b�� 
//������ʾdisp������������ʾ����ֵ����m������ֵ����λ�þ���s������ʾ����a��b��c�� ������

//�����㷨Traceback�����ڸ���ԭ���⣨һ���������⡪�����������ģ��n���Ѿ�����õ�����λ�þ��󣩣������ż������ �����ﲻ��Ҫ��ʹ������ֵ����͹�ģ����p 
void matrixchain::Traceback(int i, int j)
//ֻ��Ҫ�õ�����λ�ã�������Ҫ�õ�����ֵ 
{
	if(i == j) return;
	Traceback(i, s[i][j]);
	Traceback(s[i][j] + 1, j);
	cout<<"Multiply A"<<i<<","<<s[i][j]<<" and A"<<(s[i][j] + 1)<<","<<j<<endl;	
  }  
  
int main()
{
//	cout<<"������������˵ľ���ĸ�����";
//	cin>>n;
	matrixchain chain;
	
	chain.Input();
	chain.p_disp();
	
	chain.MatrixChain();
	chain.m_disp();
	chain.s_disp();
	
	chain.Traceback(1, n);
	return 0;
}
  
