#include<stdio.h>
#include<mpi.h>
#include<stdlib.h>

void Get_input(int myrank, int comm_sz, double* a_p, double* b_p, int* n_p);

int main(int argc, char *argv[]) {
	
	MPI_Init(&argc, &argv);
	int myrank;
	int nprocs;
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
	MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
	double a_p, b_p;
	int n_p;	
	
	Get_input(myrank, nprocs, &a_p, &b_p, &n_p);

	printf("CPU: %d, a_p: %lf, b_p: %lf, n_p: %d\n", myrank, a_p, b_p, n_p);

	
	MPI_Finalize();
	
}

void Get_input (
		int	myrank	/* in  */,
		int	comm_sz	/* in  */,
		double*	a_p	/* out */,
		double*	b_p	/* out */,
		int*	n_p	/* out */) {

	if(myrank == 0) {
		printf("Enter a, b, and n\n");
		scanf("%lf %lf %d", a_p, b_p, n_p);	
	}
	MPI_Bcast(a_p, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
	MPI_Bcast(b_p, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
	MPI_Bcast(n_p, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);

	
	
}
