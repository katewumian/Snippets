#include<iostream>
using namespace std;

int user_input();

class traceBack{
	const int N;
	int begin_num;
	int **p;
public:
	traceBack(int n);
	void constructMatrix(int n, int first_num);
	void matrixDisp();
	int getBegin_num();
	~traceBack();
};

traceBack::traceBack(int n): N(n)
{
	p = new int *[N];		
	for(int i = 0; i < N; i++)
		p[i] = new int[N];	
	for(int i = 0; i < N; i++)
	for(int j = 0; j < N; j++){
		p[i][j] = 0;
	}	
	cout<<"Please enter the first number:";
	while(! (cin>>begin_num)){
		cin.clear();
		while (cin.get() != '\n')
		{
			continue;
		}//To skip the wrong input. 
		cout<<"It should be a number:";
	}
}

void traceBack::constructMatrix(int ss, int first_num)
{	
	int s = ss;
	int temp = first_num;
	int i = s,j = s;
	for(; i < N - 1 - s; i++){
		p[j][i] = temp++;
	}
	for(; j < N - 1 - s; j++){
		p[j][i] = temp++;
	}
	for(; i > s; i--){
		p[j][i] = temp++;	
	}
	for(; j > s; j-- ){
		p[j][i] = temp++;
	}
	if(temp == begin_num) {
		p[s][s] = begin_num;
		return;
	}
	if(temp - 1 == N * N + begin_num - 1) return;
	if(temp == first_num) {
		p[s][s] = N * N + begin_num - 1;
		return;
	}
	s++;
	constructMatrix(s,temp);
	return;
}

int traceBack::getBegin_num(){
	return begin_num;
}

void traceBack::matrixDisp(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++) cout<<p[i][j]<<"\t";
		cout<<"\n\n\n\n";	}
}

traceBack::~traceBack(){
	for(int i = 0; i < N; i++)
		delete []p[i];
	delete []p;
	p = 0;
//	delete []p;//没有全部释放掉 
}

int user_input()
{
	int n;
	cout<<"Please enter a positive number:";
	while(! (cin>>n)|| n <= 0){
		cin.clear();
		while (cin.get() != '\n')
		{
			continue;
		}//To skip the wrong input. 
		cout<<"It should be a positive number:";
	}
	return n;
}

int main()
{
	int n = user_input();
	traceBack dt(n);
	dt.constructMatrix(0,dt.getBegin_num());
	dt.matrixDisp();
	return 0;
}
