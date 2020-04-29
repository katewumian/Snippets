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
 
//��������
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
 
//����ȡ�зָ
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
 
//��������
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
        
//�ֿ���
const int  NUMBER = 1000000000; 
//�����ļ�����ȡ�������ĸ���
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
 
//K·���ж�ȡ
void k_num_read(void)
{
	char* filename;
	int i,cnt,*array;
	FILE* fin;
	FILE* tmpfile;
	//����knum,ÿ·Ӧ��ȡ����������
	int n = NUMBER/KNUM;
	if (n * KNUM < NUMBER)n++;
 
	//�����洢�ֿ��ȡ�����ݵ�����
	array = (int*)malloc(n * sizeof(int));assert(array);
	//�������ļ�
	fin = fopen(in_file,"rt");
	i = 0;
	
	//�ֿ�ѭ����ȡ����,��д��Ӳ���ϵ���ʱ�ļ�
	while ( (cnt = read_data(fin,array,n))>0)
	{
		//��ÿ�ζ�ȡ������,�Ƚ��п�������,Ȼ��д��Ӳ���ϵ���ʱ�ļ�
		QuickSort(array,0,cnt - 1);
		filename = temp_filename(i++);
		tmpfile = fopen(filename,"w");
		free(filename);
		write_data(tmpfile,array,cnt);
		fclose(tmpfile);
	}
	assert(i == KNUM);
	//û������K·�ļ�ʱ�������
	//�ر������ļ��������ʱ�洢����
	fclose(fin);
	free(array);
}
 
//k·�ϲ�(������)
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
	//������ļ�
	fout = fopen(out_file,"wt");
	//�򿪸�·��ʱ�ֿ��ļ�
	farray = (FILE**)malloc(KNUM*sizeof(FILE*));
	assert(farray);
	for(i = 0; i< KNUM;i++)
	{
		filename = temp_filename(i);
		farray[i] = fopen(filename,"rt");
		free(filename);
	}
	
	//����KNUM��Ԫ�ص�data,hasNext����,�洢K·�ļ�����ʱ����Ͷ�ȡ����״̬
	data = (int*)malloc(KNUM*sizeof(int));
	assert(data);
	hasNext = (char*)malloc(sizeof(char)*KNUM);
	assert(hasNext);
	memset(data, 0, sizeof(int) * KNUM);
	memset(hasNext, 1, sizeof(char) * KNUM);
	
	//��K·�ļ��ȶ�ȡ��һ������,���Զ�ȡ�����ĸ�·�ļ����ò����ٶ�״̬
	for(i = 0; i < KNUM; i++)
	{
		if(fscanf(farray[i], "%d", &data[i]) == EOF)
		{
			hasNext[i] = 0;
		}
	}
	
	//��ȡ��·�ļ�,���ð�������С�������������ļ�
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
						//��i���ļ�δ����,�ӵ�i���������¶�
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
	
	//�رշ�������ݺ�����    
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
