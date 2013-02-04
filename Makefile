mid: MPIuse.c 
	mpicc -o mid MPIUSE.c -lm

clean: 
	rm *.o
	rm mid

