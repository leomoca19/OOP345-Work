/***********************************************************************
Author: Leonardo de la Mora Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: 15-September-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#include "RideRequest.h"
#include <iostream>
using namespace std;

double g_taxrate = .0f, g_discount = .0f;

namespace sdds {
	void RideRequest::reset()
	{
		for (auto& i : name)
			i = '\0';
		for (auto& i : details)
			i = '\0';
		price = .0f;
		discount = 0;
	}
	RideRequest::RideRequest() {}
	void RideRequest::read(istream& is)
	{
		reset();
		if (is && is.peek() != -1) {
			is.getline(name, 11, ',');
			is.getline(details, 26, ',');
			is >> price;
			is.ignore();
			discount = is.peek() == 'Y' ? 1 : 0;
			is.ignore();
		}
	}
	void RideRequest::display(ostream& os) const
	{
		static size_t counter = 1;
		os.setf(ios::fixed);
		os.setf(ios::left);

		os.width(2);
		os << counter << ". ";

		if(name[0] == '\0'){
			cout << "No Ride Request";
		}
		else {
			os.width(10);
			os << name << '|';

			os.width(25);
			os << details << '|';

			os.width(12);
			os.precision(2);
			os << price * (1 + g_taxrate) << '|'; 

			if(discount) {
				os.width(13);
				os.precision(2);
				os << right << (price * (1 + g_taxrate)) - g_discount; 
				os.unsetf(ios::right);
			}
			
		}
		os << '\n';
		counter++;
		os.unsetf(ios::left);
		os.unsetf(ios::fixed);
	}
}