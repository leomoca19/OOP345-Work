/***********************************************************************
Author: Leonardo de la Mora Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: 28-September-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
namespace sdds {
	class Book
	{
		std::string m_title{};
		unsigned m_numChapters{};
		unsigned m_numPages{};
	public:
		Book();
		Book(const std::string& title, unsigned nChapters, unsigned nPages);

		/// <summary>
		/// True if the title is not empty (has at least one character), it has at least one chapter, and it has at least one page
		/// </summary>
		operator bool()const;

		Book& operator=(const Book& other);

		double pagesOverChapters() const;

		std::ostream& print(std::ostream& os = std::cout) const;
	};
	std::ostream& operator<<(std::ostream& os, const Book& bk);
}
#endif // !SDDS_BOOK_H
