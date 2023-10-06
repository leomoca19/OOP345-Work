/***********************************************************************
Author: Leonardo de la Mora Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: October-6-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_CHEESE_H
#define SDDS_CHEESE_H
#include <iostream>
#include <string>
namespace sdds {
	class Cheese {
		std::string m_name{"NaC"};
		size_t m_weight{};
		double m_price{};
		std::string m_features{};

	public:
		//Default constructor and a constructor that receives a string, is responsible for extracting information about the cheese from string and storing the tokens in the properties. String will have the format: Name,Weight,Price,Features
		Cheese(const std::string& str = "");
		Cheese(const Cheese& other);

		//Receives a weight/amount of cheese to slice from the current object.
		// If there is enough cheese, return a copy of current cheese with the desired weight. 
		// If there isn't enough cheese, return an empty cheese object.
		Cheese slice(size_t weight);

		//- A set of queries to retrieve the value of each attribute of the cheese.
		std::string getName() const;
		size_t getWeight() const;
		double getPrice() const;
		std::string getFeatures() const;

		std::ostream& print(std::ostream& os = std::cout) const;

		Cheese& operator=(const Cheese& other);
	};
	std::ostream& operator<<(std::ostream& os, const Cheese& right);
}
#endif
