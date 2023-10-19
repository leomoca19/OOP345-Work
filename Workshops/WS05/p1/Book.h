/***********************************************************************
Author: Leonardo de la Mora Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: October-20-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
namespace sdds {
	class Book {
		std::string 
			author{},
			title{},
			pubCountry{},
			description{};

		size_t 
			pubYear{},
			price{};

	public:
		Book();
		explicit Book(const std::string& = "");

		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
	};
	std::ostream& operator<<(std::ostream&, const Book&);
}
#endif // !SDDS_BOOK_H