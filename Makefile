mid: MPIuse.c 
	mpicc -o mid MPIuse.c -lm

clean: 
	rm *.o
	rm mid

