#include <stdio.h>
#include "mpi.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char **argv){
	int p;
	int n;
	int procent_wypelnienia;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &p);	//nr procesu
	MPI_Comm_size(MPI_COMM_WORLD, &n);
	MPI_Status status;
	srand (time(NULL)+p);
	procent_wypelnienia=rand()%100;
	printf("w szklance numer %d jest %d procent wypelnienia\n",p+1,procent_wypelnienia);
	while (procent_wypelnienia<=100)
        {
            if (procent_wypelnienia>=90)
            {
            	printf("szklanka %d jest prawie pelna\n",p+1);
               printf("wypito zawartosc szklanki nr: %d\n", p+1);
               procent_wypelnienia=0;
            }
            printf("dolewam do szklanki numer %d. Obecny stan wynosi %d procent\n",p+1,procent_wypelnienia);
            procent_wypelnienia+=rand()%25;
            if (procent_wypelnienia>100)
            {
            	printf("nalano zbyt duzo. Rozla³o siê w szklance nr %d\n",p+1);
            }
        }
	MPI_Finalize();
	return 0;
}
