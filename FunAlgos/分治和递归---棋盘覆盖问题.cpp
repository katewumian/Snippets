// ���̸���.cpp : �������̨Ӧ�ó������ڵ㡣

//



//#include <stdafx.h>


#include<iostream>

#include<fstream>

using namespace std;

int tile=1; //L�͹��Ƶı��(����)

int board[100][100]; //����

int size_global;

/*****************************************************

* �ݹ鷽ʽʵ�����̸����㷨

* ���������

* tr:��ǰ�������Ͻǵ��к�

* tc:��ǰ�������Ͻǵ��к�

* dr:��ǰ���ⷽ�����ڵ��к�

* dc:��ǰ���ⷽ�����ڵ��к�

* size��size=2^k,���̹��Ϊ2^k*2^k

*****************************************************/

void chessBoard ( int tr, int tc, int dr, int dc, int size )

{

    if ( size==1 ) //���̷����СΪ1,˵���ݹ鵽�����

        return;

    int t=tile++; //ÿ�ε���1

    int s=size/2; //�����м���С��к�(��ȵ�)

    //������ⷽ���Ƿ������Ͻ���������

    if ( dr<tr+s && dc<tc+s ) //��

        chessBoard ( tr, tc, dr, dc, s );

    else //���ڣ��������������½ǵķ�����Ϊ���ⷽ��

    {

        board[tr+s-1][tc+s-1]=t;
 for ( int i=0; i<size_global; i++ )

    {

        for ( int j=0; j<size_global; j++ ){

 

            cout<<board[i][j]<<"\t";

        }

        cout<<endl<<endl;    

    }
        chessBoard ( tr, tc, tr+s-1, tc+s-1, s );

    }

    //������ⷽ���Ƿ������Ͻ���������

    if ( dr<tr+s && dc>=tc+s ) //��

        chessBoard ( tr, tc+s, dr, dc, s );

    else //���ڣ��������������½ǵķ�����Ϊ���ⷽ��

    {

        board[tr+s-1][tc+s]=t;
for ( int i=0; i<size_global; i++ )

    {

        for ( int j=0; j<size_global; j++ ){

 

            cout<<board[i][j]<<"\t";

        }

        cout<<endl<<endl;    

    }
        chessBoard ( tr, tc+s, tr+s-1, tc+s, s );

    }

    //������ⷽ���Ƿ������½���������

    if ( dr>=tr+s && dc<tc+s ) //��

        chessBoard ( tr+s, tc, dr, dc, s );

    else //���ڣ��������������Ͻǵķ�����Ϊ���ⷽ��

    {

        board[tr+s][tc+s-1]=t;
 for ( int i=0; i<size_global; i++ )

    {

        for ( int j=0; j<size_global; j++ ){

 

            cout<<board[i][j]<<"\t";

        }

        cout<<endl<<endl;    

    }
        chessBoard ( tr+s, tc, tr+s, tc+s-1, s );

    }

    //������ⷽ���Ƿ������½���������

    if ( dr>=tr+s && dc>=tc+s ) //��

        chessBoard ( tr+s, tc+s, dr, dc, s );

    else //���ڣ��������������Ͻǵķ�����Ϊ���ⷽ��

    {

        board[tr+s][tc+s]=t;
 for ( int i=0; i<size_global; i++ )

    {

        for ( int j=0; j<size_global; j++ ){

 

            cout<<board[i][j]<<"\t";

        }

        cout<<endl<<endl;    

    }
        chessBoard ( tr+s, tc+s, tr+s, tc+s, s );

    }

}

int fuc(int i)

{

int count = 0;

while(i)

{

count += i&0x01;

i >>= 1;

}

if(count < 2)

     return 1;

else

     return 0;

}

 

void menu();

 

void input()

{

    ofstream outfile;

    outfile.open("output.txt");

    int size;

    int index_x,index_y;

flag:

    cout<<"�������̵�size(��С������2��n����): ";

    cin>>size;

    if(fuc(size)!=1){

        cout<<"�������,";

        goto flag;

    }

flag2:

    cout<<"�������ⷽ��λ�õ��к����кţ���0��ʼ��: ";

    cin>>index_x>>index_y;

    if (index_x >= size||index_y>=size){

        cout<<"���ⷽ��λ�ó������̷�Χ,";

        goto flag2;

    }

    chessBoard ( 0,0,index_x,index_y,size );

    for ( int i=0; i<size; i++ )

    {

        for ( int j=0; j<size; j++ ){

 

            cout<<board[i][j]<<"\t";

        }
	
        cout<<endl<<endl;   
		size_global = size;  

    }

 

    //������ļ�

    for ( int i=0; i<size; i++ )

    {

        for ( int j=0; j<size; j++ ){

 

            outfile<<board[i][j]<<"\t";

        }

        outfile<<endl<<endl;    

    }

    cout<<"���һ�����̸��ǽ���������output.txt��"<<endl;

    outfile.close() ;

    menu();

}

void menu()

{

    char c;

    cout<<"�Ƿ�������루Y/N����";

    cin>>c;

    if( c == 'Y'||c == 'y')

        input();

}

int main()

{

    input();
    return 0;

}
