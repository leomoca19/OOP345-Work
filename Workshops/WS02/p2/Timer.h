/***********************************************************************
Author: Leonardo de la Mora Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: 23-September-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H
#include <chrono>
namespace sdds {
	class Timer {
	private:
		std::chrono::steady_clock::time_point startTime;
	public:
		void start();
		long long stop();
	};
}
#endif // !SDDS_TIMER_H

