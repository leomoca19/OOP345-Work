/***********************************************************************
Author: Leonardo de la Mora Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: 15-September-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_RIDEREQUEST_H
#define SDDS_RIDEREQUEST_H
#include <iostream>

extern double g_taxrate, g_discount;

namespace sdds {
	const int NameMaxLen = 10,
		DetailsMaxLen = 25;
	class RideRequest {
		char name[NameMaxLen]{},
			details[DetailsMaxLen]{};
		double price{};
		bool discount{};

		void reset();

	public:
		RideRequest();
		void read(std::istream& is = std::cin);
		void display(std::ostream& os = std::cout) const;
	};
}

#endif // !SDDS_RIDEREQUEST_H