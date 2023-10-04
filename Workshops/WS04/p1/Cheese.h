/***********************************************************************
Author: Leonardo de la Mora Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: September-6-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_CHEESE_H
#define SDDS_CHEESE_H
#include <iostream>
#include <string>
namespace sdds {
	class Cheese {
		std::string name{"NaC"};
		size_t weight{};
		double price{};
		std::string features{};

	public:
		//- a default constructor
		//- `Cheese(const std::string& str)`: A constructor that receives the cheese's details as a string; this constructor is responsible for extracting information about the cheese from the string and storing the tokens in the instance's attributes. The string will always have the following format:
		//  ```
		//  Name,Weight,Price,Features
		//  ```
		//  Every token that follows the price is a feature of the cheese (e.g., for `"Cheddar, 1200, 2.99, Hard, Sharp, Smooth"` the features are *Hard*, *Sharp*, and *Smooth*). Each of extracted tokens should be stored in the respective data member; the features should be stored as a space separated list of strings (e.g., `"Hard Sharp Smooth"`).
		//  This constructor should remove all leading and trailing spaces from the **beginning and end** of any token extracted from parameter.
		//  When implementing the constructor, consider these following functions:
		//  - [std::string::substr()](https://en.cppreference.com/w/cpp/string/basic_string/substr)
		//  - [std::string::find()](https://en.cppreference.com/w/cpp/string/basic_string/find)
		//  - [std::string::find_first_of()](https://en.cppreference.com/w/cpp/string/basic_string/find_first_of)
		//  - [std::string::erase()](https://en.cppreference.com/w/cpp/string/basic_string/erase)
		//  - [std::stoul()](https://en.cppreference.com/w/cpp/string/basic_string/stoul)
		//  - [std::stod()](https://en.cppreference.com/w/cpp/string/basic_string/stod)
		Cheese(const std::string& str = "");


		//- `Cheese slice(size_t weight)`: a modifier that receives as a parameter a weight/amount of cheese to slice from the current cheese object.
		//  If there is enough cheese to make this slice (weight <= weight of the cheese in current object), then return a copy of current cheese with the desired weight. Update the current object's weight after slicing.
		//  If there isn't enough cheese, then return a cheese object that is in an empty state instead.
		Cheese slice(size_t weight);


		//- A set of queries to retrieve the value of each attribute of the cheese.
		std::string getName() const;
		size_t getWeight() const;
		double getPrice() const;
		std::string getFeatures() const;

		std::ostream& print(std::ostream& os = std::cout) const;
		std::istream& read(std::istream& is = std::cin);
	};
	std::ostream& operator<<(std::ostream& os, const Cheese& right);
	std::istream& operator>>(std::istream& is, Cheese& right);
}
#endif
