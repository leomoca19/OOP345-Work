/***********************************************************************
Author: Leonardo de la Mora Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: October-6-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_CHEESEPARTY_H
#define SDDS_CHEESEPARTY_H
#include <iostream>
#include "Cheese.h"
namespace sdds {
	class CheeseParty {
		const Cheese** m_cheeses{};
		std::string m_name{ "Cheese Party" };
		size_t m_size{};

	public:
		CheeseParty();
		CheeseParty(const std::string& name);
		CheeseParty(const CheeseParty& other);
		CheeseParty(CheeseParty&& other);
		CheeseParty& operator=(const CheeseParty& other);
		CheeseParty& operator=(CheeseParty&& other);
		~CheeseParty();
		void operator~();

		CheeseParty& addCheese(const Cheese& newCheese);
		CheeseParty& removeCheese();

		const Cheese* operator[](size_t i) const;

		std::ostream& print(std::ostream& os) const;
	};
	std::ostream& operator<<(std::ostream& os, const CheeseParty& other);
}
#endif //!SDDS_CHEESEPARTY_H
