#include <assert.h>
#include <time.h> 
#include <stdio.h>   
#include <memory.h>
#include <stdlib.h>
 
void swap_int(int* a,int* b)
{    
	int c;    
	c = *a;    
	*a = *b;    
	*b = c;
}
 
//插入排序
void InsertionSort(int A[],int N)
{    
	int j,p;    
	int tmp;   
	for(p = 1; p < N; p++)    
	{       
		tmp = A[p];
		for(j = p;j > 0 && A[j - 1] >tmp;j--)        
		{            
			A[j] = A[j - 1];        
		}       
		
		A[j] = tmp;   
	}
}
 
//三数取中分割法
int Median3(int A[],int Left,int Right)
{
	int Center = (Left + Right) / 2;
	if (A[Left] > A[Center])
		swap_int(&A[Left],&A[Center]);
	if (A[Left] > A[Right])
		swap_int(&A[Left],&A[Right]);
	if (A[Center] > A[Right])
		swap_int(&A[Center],&A[Right]);
	swap_int(&A[Center],&A[Right - 1]);
	return A[Right - 1];
}
 
//快速排序
void QuickSort(int A[],int Left,int Right)
{
	int i,j;
	int Pivot;
	const int Cutoff = 3;
	if (Left + Cutoff <= Right)
	{
		Pivot = Median3(A,Left,Right);
		i = Left;
		j = Right - 1;
		while (1)
		{
			while(A[++i] < Pivot){;}
			while(A[--j] > Pivot){;}
			if (i < j)
				swap_int(&A[i],&A[j]);
			else
				break;
		}
		swap_int(&A[i],&A[Right - 1]); 
		
		QuickSort(A,Left,i - 1);
		QuickSort(A,i + 1,Right);
	}
	else
	{
		InsertionSort(A+Left,Right - Left + 1);
	}
}
        
//分块数
const int  NUMBER = 1000000000; 
//输入文件最大读取的整数的个数
const int  KNUM  = 4000;      
const char *in_file = "data.txt";
const char *out_file = "outfile.txt";

int  read_data(FILE *f,int a[],int n)
{
	int i = 0;
	while ((i < n) && (fscanf(f,"%d",&a[i]) != EOF))  
		i++;
	return i;
}
 
void  write_data(FILE *f,int a[],int n)
{
	int i;for(i = 0; i< n;i++)
		fprintf(f,"%d ",a[i]);
}
 
char* temp_filename(int index)
{
	char *tempfile = (char*) malloc(64*sizeof(char));
	assert(tempfile);
	sprintf(tempfile, "temp%d.txt", index);
	return tempfile;
}
 
//K路串行读取
void k_num_read(void)
{
	char* filename;
	int i,cnt,*array;
	FILE* fin;
	FILE* tmpfile;
	//计算knum,每路应读取的整数个数
	int n = NUMBER/KNUM;
	if (n * KNUM < NUMBER)n++;
 
	//建立存储分块读取的数据的数组
	array = (int*)malloc(n * sizeof(int));assert(array);
	//打开输入文件
	fin = fopen(in_file,"rt");
	i = 0;
	
	//分块循环读取数据,并写入硬盘上的临时文件
	while ( (cnt = read_data(fin,array,n))>0)
	{
		//对每次读取的数据,先进行快速排序,然后写入硬盘上的临时文件
		QuickSort(array,0,cnt - 1);
		filename = temp_filename(i++);
		tmpfile = fopen(filename,"w");
		free(filename);
		write_data(tmpfile,array,cnt);
		fclose(tmpfile);
	}
	assert(i == KNUM);
	//没有生成K路文件时进行诊断
	//关闭输入文件句柄和临时存储数组
	fclose(fin);
	free(array);
}
 
//k路合并(败者树)
void k_num_merge(void)
{
	FILE *fout;
	FILE **farray;
	char *filename;
	int  *data;
	char *hasNext;
	int i,j,m,min;
#ifdef OUTPUT_OUT_FILE_DATAint id;
#endif
	//打开输出文件
	fout = fopen(out_file,"wt");
	//打开各路临时分块文件
	farray = (FILE**)malloc(KNUM*sizeof(FILE*));
	assert(farray);
	for(i = 0; i< KNUM;i++)
	{
		filename = temp_filename(i);
		farray[i] = fopen(filename,"rt");
		free(filename);
	}
	
	//建立KNUM个元素的data,hasNext数组,存储K路文件的临时数组和读取结束状态
	data = (int*)malloc(KNUM*sizeof(int));
	assert(data);
	hasNext = (char*)malloc(sizeof(char)*KNUM);
	assert(hasNext);
	memset(data, 0, sizeof(int) * KNUM);
	memset(hasNext, 1, sizeof(char) * KNUM);
	
	//读K路文件先读取第一组数据,并对读取结束的各路文件设置不可再读状态
	for(i = 0; i < KNUM; i++)
	{
		if(fscanf(farray[i], "%d", &data[i]) == EOF)
		{
			hasNext[i] = 0;
		}
	}
	
	//读取各路文件,利用败者树从小到大输出到输出文件
#ifdef OUTPUT_OUT_FILE_DATAid = 0;
#endif
	
	j  = 0;F_LOOP:
	if (j < KNUM)    
	{
		while(1==1)
		{
			min = data[j];
			m = j;
			for(i = j+1; i < KNUM; i++)
			{
				if(hasNext[i] == 1  && min > data[i])
				{
					min = data[i];m = i;
				}
			}
 
			if(fscanf(farray[m], "%d", &data[m]) == EOF) 
			{
				hasNext[m] = 0;
			}
			fprintf(fout, "%d ", min);
#ifdef OUTPUT_OUT_FILE_DATAprintf("fout :%d  %d/n",++id,min);
#endif
			if (m == j && hasNext[m] == 0)
			{
				for (i = j+1; i < KNUM; i++)
				{
					if (hasNext[m] != hasNext[i])
					{
						m = i;
						//第i个文件未读完,从第i个继续往下读
						break;
					}
				}
				if (m != j)
				{
					j = m;
					goto F_LOOP;
				}
				break;
			}
		}
	}
	
	//关闭分配的数据和数组    
	free(hasNext);   
	free(data);       
	for(i = 0; i < KNUM; ++i)   
	{        
		fclose(farray[i]);   
	}   
	free(farray);    
	fclose(fout);
}
 
int main()    
{   
	time_t end,start_read,end_read,start_merge,end_merge;  
	printf("Start\n");
	start_read = time(NULL);k_num_read();    
	end_read = time(NULL);   
	printf("k_num_read time:%f\n", (end_read - start_read) * 1000.0/ CLOCKS_PER_SEC);
	start_merge = time(NULL);
	k_num_merge();    
	end_merge = time(NULL);    
	printf("k_num_merge time:%f\n", (end_merge - start_merge) * 1000.0/ CLOCKS_PER_SEC);   
	end = time(NULL);   
	printf("total time:%f\n", (end - start_read) * 1000.0/ CLOCKS_PER_SEC);    
	return 0;  
} 
