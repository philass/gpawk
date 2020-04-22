main: main.cpp
	g++ main.cpp -o main

gpu_awk: awk.cu
	nvcc awk.cu -o awk
