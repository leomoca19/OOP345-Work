/***********************************************************************
Author: Leonardo de la Mora Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: September-6-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#include "Cheese.h"
using namespace std;
namespace sdds {
	string letters{ "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM" };
	Cheese::Cheese(const string& str)
	{
		string temp{};
		size_t strFirst{}, strLast{}, commaPos{};

		if(str != "") {
			temp = str.substr(0, commaPos = str.find_first_of(','));
			//Name,Weight,Price,Features

			strFirst = temp.find_first_of(letters);
			strLast = temp.find_last_of(letters);
			name = temp.substr(strFirst, strLast - strFirst + 1);

			temp = str.substr(commaPos + 1);
			temp = temp.substr(0, commaPos += (temp.find_first_of(',')) + 1);
			weight = stoul(temp);

			temp = str.substr(commaPos + 1);
			temp = temp.substr(0, commaPos += (temp.find_first_of(',')) + 1);
			price = stod(temp);

			temp = str.substr(commaPos + 1);

		}
	}

	Cheese Cheese::slice(size_t weight)
	{
		return *this;
	}

	std::string Cheese::getName() const
	{
		return name;
	}
	size_t Cheese::getWeight() const
	{
		return weight;
	}
	double Cheese::getPrice() const
	{
		return price;
	}
	std::string Cheese::getFeatures() const
	{
		return features;
	}

	std::ostream& Cheese::print(std::ostream& os) const
	{
		return os;
	}
	std::istream& Cheese::read(std::istream& is)
	{
		return is;
	}

	std::ostream& operator<<(std::ostream& os, const Cheese& right)
	{
		return right.print(os);
	}
	std::istream& operator>>(std::istream& is, Cheese& right)
	{
		return right.read(is);
	}
}