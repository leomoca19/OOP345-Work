/***********************************************************************
Author: Leonardo de la Mora Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: October-6-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#include "CheeseShop.h"
using namespace std;
namespace sdds {
	ostream& CheeseShop::print(ostream& os) const
	{
		return os;
	}
	CheeseShop::CheeseShop(const string& name): m_cheeses(), m_name(name), m_size() {}
	CheeseShop::~CheeseShop()
	{

	}

	CheeseShop& CheeseShop::operator=(const CheeseShop& other)
	{
		return *this;
	}
	CheeseShop& CheeseShop::addCheese(const Cheese& other)
	{
		return *this;
	}

	CheeseShop& CheeseShop::operator[](const size_t& i) const
	{
		CheeseShop* temp{};
		return *temp;
	}

	ostream& operator<<(ostream& os, const Cheese& other) {
		return other.print(os);
	}
}
