all:
	g++ -std=c++11 -fopenmp -O3 keras_model.cc example_main.cc -o test
