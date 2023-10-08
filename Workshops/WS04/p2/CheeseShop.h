/***********************************************************************
Author: Leonardo de la Mora Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: October-6-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_CHEESESHOP_H
#define SDDS_CHEESESHOP_H
#include <iostream>
#include "Cheese.h"
namespace sdds {
	class CheeseShop {
		const Cheese** m_cheeses{};
		std::string m_name;
		size_t m_size{};

	public:
		CheeseShop(const std::string& name = "No name");
		CheeseShop(const CheeseShop& other);
		CheeseShop(CheeseShop&& other);
		CheeseShop& operator=(CheeseShop&& other);
		CheeseShop& operator=(const CheeseShop& other);
		~CheeseShop();
		void operator~();

		CheeseShop& addCheese(const Cheese& other);

		std::ostream& print(std::ostream& os) const;
	};
	std::ostream& operator<<(std::ostream& os, const CheeseShop& other);
}
#endif //!SDDS_CHEESESHOP_H