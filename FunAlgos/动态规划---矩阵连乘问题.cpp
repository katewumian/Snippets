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
	int (* m)[n + 1];//二维
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
	cout<<"请输入"<<n<<"个矩阵的各自的规模，p0、p1…p"<<n<<": ";
	for(int i = 0; i < n + 1; i++)
	cin>>p[i];
	}
	void p_disp(){
		cout<<n<<"个矩阵的规模数组为：";
	for(int i = 0; i <= n; i++)
		cout<<p[i]<<" ";
	cout<<endl<<endl;		
	}
	void m_disp(){	
	cout<<"最优值数组m："<<endl;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++)
			cout<<m[i][j]<<"\t";
		cout<<endl;
	}
	cout<<endl;
	} 
	void s_disp(){
		cout<<"记录最优值断开位置的数组s："<<endl;
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

//计算两个矩阵乘积的算法
/*void matrixMultiply(int* a, int* b, int* c, int ra, int ca, int rb, int cb)
{
	if(ca != rb) error("矩阵不可乘");
	for(int i = 0; i < ra; i++)
		for(int j = 0; j < cb; j++) {
			int sum = a[i][0] * b[0][j];
			for(int k = 1; k < ca; k++)
				sum += a[i][k] * b[k][j];
			c[i][j] = sum;
		}
} 
 */ 

 //计算最优值并保存
 void matrixchain::MatrixChain() 
 //p用于存储各个矩阵的规模，n为矩阵的个数，二维矩阵存储最优值，二维矩阵s存储取最优值时子矩阵分割的位置k 
 //为了研究方便，矩阵m从 i = 1 和j = 1 开始存储，p从 k = 0 开始存储 
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
  
//定义初始化函数，用于建立二维数组m，二维数组s，一维数组p用于存储矩阵规模，而不需要实际计算出矩阵乘积后的值（，初始化矩阵a、b、c ） 
//定义输入函数，输入内容包括 p数组（每个矩阵的规模），矩阵个数n（，输入两个矩阵a、b） 
//定义显示disp函数，用于显示最优值矩阵m，最优值最优位置矩阵s（，显示数组a、b、c） ？？？

//定义算法Traceback，用于给出原问题（一个具体问题——给出问题规模（n，已经计算好的最优位置矩阵））的最优计算次序 ，这里不需要再使用最优值矩阵和规模数组p 
void matrixchain::Traceback(int i, int j)
//只需要用到最优位置，而不需要用到最优值 
{
	if(i == j) return;
	Traceback(i, s[i][j]);
	Traceback(s[i][j] + 1, j);
	cout<<"Multiply A"<<i<<","<<s[i][j]<<" and A"<<(s[i][j] + 1)<<","<<j<<endl;	
  }  
  
int main()
{
//	cout<<"请输入进行连乘的矩阵的个数：";
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
  
