/***********************************************************************
Author: Leonardo de la Mora Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: 28-September-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#include "Book.h"
using namespace std;
namespace sdds {
	Book::Book(const string& title, unsigned nChapters, unsigned nPages) : 
		m_title(title), m_numChapters(nChapters), m_numPages(nPages){}
	Book::Book(){}
	Book::operator bool() const
	{
		return m_title[0] != '\0' && m_numChapters > 0 && m_numPages > 0;
	}
	Book& Book::operator=(const Book& other)
	{
		if (this != &other) {
			m_title = other.m_title;
			m_numChapters = other.m_numChapters;
			m_numPages = other.m_numPages;
		}
		return *this;
	}
	double Book::pagesOverChapters() const
	{
		return m_numPages / m_numChapters;
	}
	ostream& Book::print(ostream& os) const
	{
		if (*this) {
			os.setf(ios::right); os.setf(ios::fixed);
			os.width(m_numChapters > 9 ? 49 : 50);
			os << m_title << ',' << m_numChapters << ',' << m_numPages << " | (";

			os.precision(6);
			os << (double)m_numPages / m_numChapters << ")    ";

			os.unsetf(ios::right);
		}
		else 
			cout << "| Invalid book data";

		return os;
	}
	ostream& operator<<(ostream& os, const Book& bk)
	{
		return bk.print(os);
	}
}
