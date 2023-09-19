/***********************************************************************
Author: Leonardo de la Mora Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: 18-September-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "RideRequest.h"
#include <iostream>
using namespace std;

double g_taxrate = .0f, g_discount = .0f;

namespace sdds {
	void RideRequest::reset()
	{
		if(details){
			delete[] details;
			details = nullptr;
		}

		for (auto& i : name)
			i = '\0';
		price = .0f;
		discount = 0;
	}
	RideRequest::RideRequest() {}
	RideRequest::RideRequest(const RideRequest& other)
	{
		*this = other;
	}
	RideRequest& RideRequest::operator=(const RideRequest& other)
	{
		if (this != &other && other.details) {
			reset();
			details = new char[strlen(other.details) + 1];
			strcpy(details, other.details);

			strcpy(name, other.name);
			price = other.price;
			discount = other.discount;
		}
		return *this;
	}
	RideRequest::~RideRequest()
	{
		reset();
	}
	void RideRequest::read(istream& is)
	{
		char tempDetails[99 + 1]{};
		reset();
		if (is && is.peek() != -1) {
			is.getline(name, 11, ',');
			
			is.getline(tempDetails, 99, ',');
			details = new char[strlen(tempDetails) + 1];
			strcpy(details, tempDetails);

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