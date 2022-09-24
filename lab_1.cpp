#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <chrono>
#include <cstdlib>
#include <cmath>
#include <list>
#include <set>

using namespace std;

std::vector<int> gen_random_array(int size) { // сделать рандомный массив
	std::vector<int> result(size);
	for (int i = 0; i < size; i++) {
		result[i] = rand();
	}
	return result;
}
auto t1 = std::chrono::high_resolution_clock::now();
auto t2 = std::chrono::high_resolution_clock::now();

void measure(int size) {  // сортировочка
	std::vector<int> data = gen_random_array(size);

	t1 = std::chrono::high_resolution_clock::now();
	std::sort(data.begin(), data.end()); 
	t2 = std::chrono::high_resolution_clock::now();

	double time_1 = std::chrono::duration<double>(t2 - t1).count();

	std::cout << "N: " << size << ", time: " << time_1 << std::endl;
	//-------------------------------------------------------------------------
	
	t3 = std::chrono::high_resolution_clock::now();
	data.push_back(rand());
	t4 = std::chrono::high_resolution_clock::now();

	double time = std::chrono::duration<double>(t2 - t1).count();

	std::cout << "N: " << size << ", time: " << time << std::endl;

	//-------------------------------------------------------------------------
	 t1 = std::chrono::high_resolution_clock::now();
	data.insert(data.begin(), rand());
	 t2 = std::chrono::high_resolution_clock::now();

	double time = std::chrono::duration<double>(t2 - t1).count();

	std::cout << "N: " << size << ", time: " << time << std::endl;
	
}



int main(int argc, char** argv) {
	int max_pow = argc > 1 ? std::stoi(argv[1]) : 6;

	for (int i = 1; i <= max_pow; i++) {
		measure(pow(10, i));
	}
	return 0;
}