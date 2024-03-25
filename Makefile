tokenizer: tokenizer.cpp
	g++ -std=c++11 -c tokenizer.cpp -o tokenizer

main: main.cpp
	g++ main.cpp -o main

gpu_awk: awk.cu
	nvcc awk.cu -o awk

clean: 
	rm main

