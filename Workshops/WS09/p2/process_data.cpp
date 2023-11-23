// Workshop 9 - Multi-Threading, Thread Class
// process_data.cpp
// 2021/1/5 - Jeevan Pant
// 2023/11/17 - Cornel
// 2023/11/22 - Leonardo de la Mora Caceres 
//	email:	lde-la-mora-canceres@myseneca.ca
//	id:		152877205
//	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <string>
#include <iostream>
#include <fstream>
#include <functional>
#include <vector>
#include <thread>
#include "process_data.h"
using namespace std;
namespace sdds
{
	// The following function receives array (pointer) as the first argument, number of array 
	//   elements (size) as second argument, divisor as the third argument, and avg as fourth argument. 
	//   size and divisor are not necessarily same. When size and divisor hold same value, avg will 
	//   hold average of the array elements. When they are different, avg will hold a value called 
	// 	 as average-factor. For part 1, you will be using same value for size and double. Use of 
	//   different values for size and divisor will be useful for multi-threaded implementation in part-2. 
	void computeAvgFactor(const int* arr, int size, int divisor, double& avg) {
		avg = 0;
		for (int i = 0; i < size; i++) {
			avg += arr[i];
		}
		avg /= divisor;
	}

	// The following function receives array (pointer) as the first argument, number of array elements  
	//   (size) as second argument, divisor as the third argument, computed average value of the data items
	//   as fourth argument, and var as fifth argument. Size and divisor are not necessarily same as in the 
	//   case of computeAvgFactor. When size and divisor hold same value, var will get total variance of 
	//   the array elements. When they are different, var will hold a value called as variance factor. 
	//   For part 1, you will be using same value for size and double. Use of different values for size 
	//   and divisor will be useful for multi-threaded implementation in part-2. 
	void computeVarFactor(const int* arr, int size, int divisor, double avg, double& var) {
		var = 0;
		for (int i = 0; i < size; i++) {
			var += (arr[i] - avg) * (arr[i] - avg);
		}
		var /= divisor;
	}

	// The following constructor of the functor receives name of the data file, opens it in 
	//   binary mode for reading, reads first int data as total_items, allocate memory space 
	//   to hold the data items, and reads the data items into the allocated memory space. 
	//   It prints first five data items and the last three data items as data samples. 
	//   
	ProcessData::ProcessData(const string& filename, int n_threads) {
		// TODO: Open the file whose name was received as parameter and read the content
		//         into variables "total_items" and "data". Don't forget to allocate
		//         memory for "data".
		//       The file is binary and has the format described in the specs.

		ifstream file(filename, ios::binary);

		if (!file)
			throw runtime_error("Error: Unable to open the file '" + filename + "'");

		file.read(reinterpret_cast<char*>(&total_items), sizeof(int));

		data = new int[total_items];

		file.read(reinterpret_cast<char*>(data), total_items * sizeof(int));


		cout << "Item's count in file '" << filename << "': " << total_items << endl;
		cout << "  [" << data[0] << ", " << data[1] << ", " << data[2] << ", ... , "
			<< data[total_items - 3] << ", " << data[total_items - 2] << ", "
			<< data[total_items - 1] << "]" << endl;

		// Following statements initialize the variables added for multi-threaded 
		//   computation
		num_threads = n_threads;
		averages = new double[num_threads] {};
		variances = new double[num_threads] {};
		p_indices = new int[num_threads + 1] {};
		for (int i = 0; i < num_threads; i++)
			p_indices[i] = i * (total_items / num_threads);
		p_indices[num_threads] = total_items;
	}
	ProcessData::~ProcessData() {
		delete[] data;
		delete[] averages;
		delete[] variances;
		delete[] p_indices;
	}

	ProcessData::operator bool() const {
		return total_items > 0 && data;
	}

	// TODO Improve operator() function from part-1 for multi-threaded operation. Enhance the  
	//   function logic for the computation of average and variance by running the 
	//   function computeAvgFactor and computeVarFactor in multile threads. 
	// The function divides the data into a number of parts, where the number of parts is 
	//   equal to the number of threads. Use multi-threading to compute average-factor for 
	//   each part of the data by calling the function computeAvgFactor. Add the obtained 
	//   average-factors to compute total average. Use the resulting total average as the 
	//   average value argument for the function computeVarFactor, to compute variance-factors 
	//   for each part of the data. Use multi-threading to compute variance-factor for each 
	//   part of the data. Add computed variance-factors to obtain total variance.
	// Save the data into a file with filename held by the argument fname_target. 
	// Also, read the workshop instruction.
	int ProcessData::operator()(const string& target_file, double& avg, double& var) {
		int success{};

		// averages
		vector<thread> avgThreads;
		for (int i = 0; i < num_threads; ++i)
			avgThreads.emplace_back(bind(&computeAvgFactor, data + p_indices[i], p_indices[i + 1] - p_indices[i], total_items, ref(averages[i])));

		for (auto& thread : avgThreads)
			thread.join();

		for (int i = 0; i < num_threads; ++i)
			avg += averages[i];


		// variance 
		vector<thread> varThreads;
		for (int i = 0; i < num_threads; ++i) {
			varThreads.emplace_back(bind(&computeVarFactor, data + p_indices[i], p_indices[i + 1] - p_indices[i], total_items, avg, ref(variances[i])));
		}

		for (auto& thread : varThreads)
			thread.join();

		for (int i = 0; i < num_threads; ++i)
			var += variances[i];


		ofstream target(target_file, ios::binary);
		if ((success = (target.is_open()))) {
			target.write(reinterpret_cast<char*>(&total_items), sizeof(int));
			target.write(reinterpret_cast<char*>(data), total_items * sizeof(int));
		}
		else
			throw runtime_error("Error: Unable to open the file '" + target_file + "'");

		return success;
	}
}