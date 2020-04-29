// 棋盘覆盖.cpp : 定义控制台应用程序的入口点。

//



//#include <stdafx.h>


#include<iostream>

#include<fstream>

using namespace std;

int tile=1; //L型骨牌的编号(递增)

int board[100][100]; //棋盘

int size_global;

/*****************************************************

* 递归方式实现棋盘覆盖算法

* 输入参数：

* tr:当前棋盘左上角的行号

* tc:当前棋盘左上角的列号

* dr:当前特殊方格所在的行号

* dc:当前特殊方格所在的列号

* size：size=2^k,棋盘规格为2^k*2^k

*****************************************************/

void chessBoard ( int tr, int tc, int dr, int dc, int size )

{

    if ( size==1 ) //棋盘方格大小为1,说明递归到最里层

        return;

    int t=tile++; //每次递增1

    int s=size/2; //棋盘中间的行、列号(相等的)

    //检查特殊方块是否在左上角子棋盘中

    if ( dr<tr+s && dc<tc+s ) //在

        chessBoard ( tr, tc, dr, dc, s );

    else //不在，将该子棋盘右下角的方块视为特殊方块

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

    //检查特殊方块是否在右上角子棋盘中

    if ( dr<tr+s && dc>=tc+s ) //在

        chessBoard ( tr, tc+s, dr, dc, s );

    else //不在，将该子棋盘左下角的方块视为特殊方块

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

    //检查特殊方块是否在左下角子棋盘中

    if ( dr>=tr+s && dc<tc+s ) //在

        chessBoard ( tr+s, tc, dr, dc, s );

    else //不在，将该子棋盘右上角的方块视为特殊方块

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

    //检查特殊方块是否在右下角子棋盘中

    if ( dr>=tr+s && dc>=tc+s ) //在

        chessBoard ( tr+s, tc+s, dr, dc, s );

    else //不在，将该子棋盘左上角的方块视为特殊方块

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

    cout<<"输入棋盘的size(大小必须是2的n次幂): ";

    cin>>size;

    if(fuc(size)!=1){

        cout<<"输入错误,";

        goto flag;

    }

flag2:

    cout<<"输入特殊方格位置的行号与列号（从0开始）: ";

    cin>>index_x>>index_y;

    if (index_x >= size||index_y>=size){

        cout<<"特殊方格位置超出棋盘范围,";

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

 

    //输出到文件

    for ( int i=0; i<size; i++ )

    {

        for ( int j=0; j<size; j++ ){

 

            outfile<<board[i][j]<<"\t";

        }

        outfile<<endl<<endl;    

    }

    cout<<"最后一次棋盘覆盖结果已输出到output.txt中"<<endl;

    outfile.close() ;

    menu();

}

void menu()

{

    char c;

    cout<<"是否继续输入（Y/N）？";

    cin>>c;

    if( c == 'Y'||c == 'y')

        input();

}

int main()

{

    input();
    return 0;

}
