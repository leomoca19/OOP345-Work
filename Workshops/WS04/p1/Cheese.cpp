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
	const string letters{ "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM" };
	const size_t nameW = 21;
	const size_t weightW = 5;
	const size_t priceW = 5;
	const size_t featuresW = 33;
	Cheese::Cheese(const string& str)
	{
		string temp{};
		size_t strFirst{}, strLast{}, commaPos{};

		if(str != "") {
			temp = str.substr(0, commaPos = str.find_first_of(','));

			strFirst = temp.find_first_of(letters);
			strLast = temp.find_last_of(letters);
			name = temp.substr(strFirst, strLast - strFirst + 1);

			temp = str.substr(commaPos + 1);
			temp = temp.substr(0, commaPos += (temp.find_first_of(',')) + 1);
			weight = stoul(temp);

			temp = str.substr(commaPos + 1);
			temp = temp.substr(0, commaPos += (temp.find_first_of(',')) + 1);
			price = stod(temp);

			//won't read the last feature
			temp = str.substr(commaPos + 1);
			while ((temp.find_first_of(',') != string::npos)) {
				commaPos += (temp.find_first_of(',')) + 1;
				temp = temp.substr(0, temp.find_first_of(','));
				strFirst = temp.find_first_of(letters);
				strLast = temp.find_last_of(letters);
				features += temp.substr(strFirst, strLast - strFirst + 1) + ' ';
				temp = str.substr(commaPos + 1);
			}

			//read the last feature
			temp = str.substr(commaPos + 1);
			strFirst = temp.find_first_of(letters);
			strLast = temp.find_last_of(letters);
			features += temp.substr(strFirst, strLast - strFirst + 1);
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

	ostream& Cheese::print(ostream& os) const
	{
		os.setf(ios::left);
		{
			os << '|';
			os.width(nameW);
			os << ((name.length() <= nameW) ? name : name.substr(0, nameW)) << '|';

			os.width(weightW);
			os << weight << '|';

			os.width(priceW); os.precision(2);
			os.setf(ios::fixed);
			{
				os << price << '|';
			}
			os.unsetf(ios::fixed);

			os.width(featuresW);
			os.setf(ios::right);
			{
				os << ((features.length() <= featuresW) ? features : features.substr(0, featuresW)) << " |\n";
			}
			os.unsetf(ios::right);
		}
		os.unsetf(ios::left);

		return os;
	}
	ostream& operator<<(ostream& os, const Cheese& right)
	{
		return right.print(os);
	}
}