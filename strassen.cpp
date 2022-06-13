#include <iostream.h>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

#define randomize() (srand((unsigned)time(NULL)))
#define random(x) (rand()%x)

typedef int* intp;
typedef int** intpp;
typedef char* String ;

void partition(int , intpp,intpp,intpp,intpp,intpp);
intpp combine(int , intpp,intpp,intpp,intpp);
intpp strassen(int , intpp ,intpp);
intpp Add(int,intpp,intpp);
intpp Mult(int ,int ,intpp );
void CoutA(intpp,int,String);
intpp MakeArray(int);
int flag=0;

int Random(int xmin=0,int xmax=1)//generate a random number between 1 too 10
{
	int out=0;
	out=random(10)+1;
	return out;
}

void main()
{
	randomize();
	intpp A,B,C;
	int n;
	cout<<"Enter n , (n=2^K)\n";
	cin>>n;
	A=MakeArray(n);
	B=MakeArray(n);
	CoutA(A,n,"A");
	CoutA(B,n,"B");
	C=strassen(n,A,B);
	CoutA(C,n,"C");
}

//the main algorithm for strassen
intpp strassen(int n ,intpp A,intpp B)
{
	intpp C;
	C=new intp;
	for(int i=0;i<n;i++)
		C[i]=new int(n);
	intpp A11,A12,A21,A22,B11,B12,B21,B22,M1,M2,M3,M4,M5,M6,M7,C11,C12,C21,C22;
	A11=new intp;A12=new intp;A21=new intp;A22=new intp;
	B11=new intp;B12=new intp;B21=new intp;B22=new intp;
	C11=new intp;C12=new intp;C21=new intp;C22=new intp;
	M1=new intp;M2=new intp;M3=new intp;M4=new intp;M5=new intp;M6=new intp;M7=new intp;
	for(i=0;i<n/2;i++)
	{
		A11[i]=new int(n);A12[i]=new int(n);A21[i]=new int(n);A22[i]=new int(n);
		B11[i]=new int(n);B12[i]=new int(n);B21[i]=new int(n);B22[i]=new int(n);
		C11[i]=new int(n);C12[i]=new int(n);C21[i]=new int(n);C22[i]=new int(n);
		M1[i]=new int(n);M2[i]=new int(n);M3[i]=new int(n);M4[i]=new int(n);
		M5[i]=new int(n);M6[i]=new int(n);M7[i]=new int(n);
	}
	partition(n,A,A11,A12,A21,A22);
	partition(n,B,B11,B12,B21,B22);
	if (n==2 ) // we take a treshhold number 2 here.
	{
		int a11=A11[0][0],a12=A12[0][0],a21=A21[0][0],a22=A22[0][0];
		int b11=B11[0][0],b12=B12[0][0],b21=B21[0][0],b22=B22[0][0];
		M1[0][0]=(a11+a22)*(b11+b22);
		M2[0][0]=(a21+a22)*(b11);
		M3[0][0]=(a11)*(b12-b22);
		M4[0][0]=(a22)*(b21-b11);
		M5[0][0]=(a11+a12)*(b22);
		M6[0][0]=(a21-a11)*(b11+b12);
		M7[0][0]=(a12-a22)*(b21+b22);
	}
	else
	{
		M1=strassen(n/2,Add(n/2,A11,A22),Add(n/2,B11,B22));
		M2=strassen(n/2,Add(n/2,A21,A22),B11);
		M3=strassen(n/2,A11,Add(n/2,B12,Mult(n/2,-1,B22)));
		M4=strassen(n/2,A22,Add(n/2,B21,Mult(n/2,-1,B11)));
		M5=strassen(n/2,Add(n/2,A11,A12),B22);
		M6=strassen(n/2,Add(n/2,A21,Mult(n/2,-1,A11)),Add(n/2,B11,B12));
		M7=strassen(n/2,Add(n/2,A12,Mult(n/2,-1,A22)),Add(n/2,B21,B22));
	}
	C11=Add(n/2,Add(n/2,Add(n/2,M1,M4),Mult(n/2,-1,M5)),M7);
	C12=Add(n/2,M3,M5);
	C21=Add(n/2,M2,M4);
	C22=Add(n/2,Add(n/2,Add(n/2,M1,M3),Mult(n/2,-1,M2)),M6);
	C=combine(n,C11,C12,C21,C22);
//	CoutA(C,n,"c");
	return C;
}

//combine
intpp combine(int n, intpp A11,intpp A12,intpp A21,intpp A22)
{
	intpp A;
	A=new intp;
	int k=n/2;
	for(int g=0;g<n;g++)
		A[g]=new int(n);

	for(int i=0;i<k;i++)
	{
		for(int j=0;j<k;j++)
		{
			A[i][j]=  A11[i][j];
			A[i][j+k]=A12[i][j];
			A[i+k][j]=A21[i][j];
			A[i+k][j+k]=A22[i][j];
		}
	}
	return A;
}

//partitionning .. . 
void partition(int n, intpp A,intpp A11,intpp A12,intpp A21,intpp A22)
{
	int k=n/2;
	for(int i=0;i<k;i++)
		for(int j=0;j<k;j++)
		{
			A11[i][j]=A[i][j];
			A12[i][j]=A[i][j+k];
			A21[i][j]=A[i+k][j];
			A22[i][j]=A[i+k][j+k];
		}
}

//Add two array
intpp Add(int n,intpp A,intpp B)
{
	intpp out;
	out=new intp;
	for(int i=0;i<n;i++)
	{
		out[i]=new int(n);
		for(int j=0;j<n;j++)
			out[i][j]=A[i][j]+B[i][j];
	}
	return out;
}

//Compute -A
intpp Mult(int n,int x,intpp A)
{
	intpp out;
	out=new intp;
	for(int i=0;i<n;i++)
	{
		out[i]=new int(n);
		for(int j=0;j<n;j++)
			out[i][j]=-1*A[i][j];
	}
	return out;
}

//make a random array with size n
intpp MakeArray(int n)
{
	intpp out;
	out =new intp;
	for(int i=0;i<n;i++)
	{
		out[i]=new int(n);
		for(int j=0;j<n;j++)
			out[i][j]=Random();
	}
	return(out);
}
//cout an array 
void CoutA(intpp A,int n,String x)
{
	cout<<"\nThe "<<x<<" Array is :\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<A[i][j];
			if(j!=n-1)
				cout<<" , ";
		}
		cout<<endl;
	}
//	if(x[0]=='c' || x[0]=='C')
//		getch();
}