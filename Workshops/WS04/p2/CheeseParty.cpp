/***********************************************************************
Author: Leonardo de la Mora Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: October-6-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#include "CheeseParty.h"
using namespace std;
namespace sdds {
	CheeseParty::CheeseParty(){}
	CheeseParty::CheeseParty(const std::string& name) : m_name(name){}
	CheeseParty::CheeseParty(const CheeseParty& other) {
		*this = other;
	}
	CheeseParty::CheeseParty(CheeseParty&& other){
		*this = move(other);
	}
	CheeseParty& CheeseParty::operator=(const CheeseParty& other){
		if (this != &other) {
			m_name = other.m_name;
			m_size = other.m_size;

			delete[] m_cheeses;
			m_cheeses = nullptr;

			m_cheeses = new const Cheese* [other.m_size];
			for (size_t i = 0; i < m_size; i++)
			{
				m_cheeses[i] = other.m_cheeses[i];
			}
		}
		return *this;
	}
	CheeseParty& CheeseParty::operator=(CheeseParty && other) {
		if (this != &other) {
			m_name = other.m_name;
			m_size = other.m_size;

			delete[] m_cheeses;
			m_cheeses = other.m_cheeses;
			other.m_cheeses = nullptr;
			other.m_size = 0;
		}
		return *this;
	}
	CheeseParty::~CheeseParty() {
		~*this;
	}
	void CheeseParty::operator~() {
		m_name.clear();
		for (size_t i = m_size; i > 0; i--) {
			delete m_cheeses[i - 1];
			m_cheeses[i - 1] = nullptr;
		}
		delete[] m_cheeses;
		m_cheeses = nullptr;
		m_size = 0;
	}

	CheeseParty& CheeseParty::addCheese(const Cheese& newCheese)
	{
		bool found{};
		for (size_t i = 0; i < m_size && !found; i++)
			found = &newCheese == m_cheeses[i];
				
		if (!found) {
			const Cheese** newCheeses = new const Cheese*[m_size + 1];
			for (size_t i = 0; i < m_size; i++)
				newCheeses[i] = m_cheeses[i];

			newCheeses[m_size++] = &newCheese;
			delete[] m_cheeses;
			m_cheeses = newCheeses;
		}
		
		return *this;
	}
	CheeseParty& CheeseParty::removeCheese() {
		bool found{};
		for (size_t i = 0; i < m_size && !found; i++)
			if (found = !m_cheeses[i]->getWeight())
				m_cheeses[i] = nullptr;

		return *this;
	}

	const Cheese* CheeseParty::operator[](size_t i) const{
		return (i <= m_size ? m_cheeses[i] : static_cast<const Cheese*>(nullptr));
	}

	ostream& CheeseParty::print(ostream& os) const {
		const char separator[] = "--------------------------\n";

		os << separator << m_name << '\n' << separator <<
			(m_size ? "" : "This party is just getting started!\n");

		for (size_t i = 0; i < m_size; i++)
			if (m_cheeses[i]) 
				m_cheeses[i]->print(os);

		return os << separator;
	}

	ostream& operator<<(ostream& os, const CheeseParty& other) {
		return other.print(os);
	}
}