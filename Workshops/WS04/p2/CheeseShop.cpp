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
	CheeseShop::CheeseShop(const string& name) : m_name(name) {}
	CheeseShop::CheeseShop(const CheeseShop& other)
	{
		*this = other;
	}
	CheeseShop::CheeseShop(CheeseShop&& other)
	{
		*this = move(other);
	}
	CheeseShop& CheeseShop::operator=(CheeseShop&& other)
	{
		if (this != &other) {
			~*this;
			*this = other;
			~other;
		}
		return *this;
	}
	CheeseShop& CheeseShop::operator=(const CheeseShop& other)
	{
		if (this != &other) {
			~*this;
			m_name = other.m_name;

			for (size_t i = 0; i < other.m_size; i++)
				addCheese(*other.m_cheeses[i]);
		}
		return *this;
	}
	CheeseShop::~CheeseShop()
	{
		~*this;
	}
	void CheeseShop::operator~()
	{
		m_name.clear();
		for (size_t i = m_size; i > 0; i--) {
			delete m_cheeses[i - 1];
			m_cheeses[i - 1] = nullptr;
		}
		delete[] m_cheeses;
		m_cheeses = nullptr;
		m_size = 0;
	}

	CheeseShop& CheeseShop::addCheese(const Cheese& other)
	{
		const Cheese** cheesesCopy = new const Cheese * [m_size + 1];
		for (size_t i = 0; i < m_size; i++)
			cheesesCopy[i] = m_cheeses[i];

		cheesesCopy[m_size++] = new Cheese(other);

		delete[] m_cheeses;
		m_cheeses = cheesesCopy;

		return *this;
	}

	ostream& CheeseShop::print(ostream& os) const
	{
		const char separator[] = "--------------------------\n";

		os << separator << m_name << '\n' << separator;

		os << (m_size ? "" : "This shop is out of cheese!\n");
		for (size_t i = 0; i < m_size; i++)
			m_cheeses[i]->print(os);

		return os << separator;
	}

	ostream& operator<<(ostream& os, const CheeseShop& other) {
		return other.print(os);
	}
}
