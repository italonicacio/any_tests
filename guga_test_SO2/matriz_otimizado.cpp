#include <stdio.h>
#include <omp.h>
#include <math.h>
#include <ctime>

#include <chrono>
#include <iostream>

static long N = 1000;
static long M = 10000;
double step;

int PosColumnMajor(int M, int i, int j)
{
    return ((M*j) +i);
}

int original_column_major(){

	double* a, *b, *c, *d;
	a = new double[N];
	b = new double[N];
	c = new double[N*N];
	d = new double[N];
	
	int i, j;
	
	/* Inicialização */
	for (i=0; i<N; i++){
		a[i] = i*5.3;
		b[i] = 0.8+i;
		d[i] = 0.1*i;
	}

	/* Inicialização */
	for (j=0; j<N; j++)
		for (i=0; i<N; i++)
			c[PosColumnMajor(N, i, j)] = i*0.3;
	
	
	for (int k=0; k<M; k++)
	for (j=0; j<N; j++)
		for (i=0; i<N; i++)
			c[PosColumnMajor(N, i, j)] += k + (b[i] * a[i])/(j+1);
	
	for (i=0; i<N; i++)
		d[i] = 1.0/a[i];

	
	delete a, b, c, d;

	return 1;	
}

int permuta_loops_columns_major(){

		
	double* a, *b, *c, *d;
	a = new double[N];
	b = new double[N];
	c = new double[N*N];
	d = new double[N];

	int i, j;
	
	/* Inicialização */
	for (i=0; i<N; i++){
		a[i] = i*5.3;
		b[i] = 0.8+i;
		d[i] = 0.1*i;
	}

	/* Inicialização */
	for (i=0; i<N; i++)
		for (j=0; j<N; j++)
			c[PosColumnMajor(N, i, j)] = i*0.3;
	
	
	for (int k=0; k<M; k++)
	for (i=0; i<N; i++)
		for (j=0; j<N; j++)
			c[PosColumnMajor(N, i, j)] += k + (b[i] * a[i])/(j+1);
	
	for (i=0; i<N; i++)
		d[i] = 1.0/a[i];


	delete a, b, c, d;

	return 1;	
}


int main (){
	

  	auto t1 = std::chrono::high_resolution_clock::now();
	original_column_major();
	auto t2 = std::chrono::high_resolution_clock::now();

    duration = (std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count());
    time = (float)duration/1000000;
    std::cout << "Versao após aplicar o método de acesso column major = " << time << " segundos." << std::endl;

	t1 = std::chrono::high_resolution_clock::now();
	permuta_loops_columns_major();
	t2 = std::chrono::high_resolution_clock::now();

    duration = (std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count());
    time = (float)duration/1000000;
    std::cout << "Permuta column major = " << time << " segundos." << std::endl;


	return 1;
}
  

  

  
  