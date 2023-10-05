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

		if (str != "") {
			temp = str.substr(0, commaPos = str.find_first_of(','));

			strFirst = temp.find_first_of(letters);
			strLast = temp.find_last_of(letters);
			m_name = temp.substr(strFirst, strLast - strFirst + 1);

			temp = str.substr(commaPos + 1);
			temp = temp.substr(0, commaPos += (temp.find_first_of(',')) + 1);
			m_weight = stoul(temp);

			temp = str.substr(commaPos + 1);
			temp = temp.substr(0, commaPos += (temp.find_first_of(',')) + 1);
			m_price = stod(temp);

			//won't read the last feature
			temp = str.substr(commaPos + 1);
			while ((temp.find_first_of(',') != string::npos)) {
				commaPos += (temp.find_first_of(',')) + 1;
				temp = temp.substr(0, temp.find_first_of(','));
				strFirst = temp.find_first_of(letters);
				strLast = temp.find_last_of(letters);
				m_features += temp.substr(strFirst, strLast - strFirst + 1) + ' ';
				temp = str.substr(commaPos + 1);
			}

			//read the last feature
			temp = str.substr(commaPos + 1);
			strFirst = temp.find_first_of(letters);
			strLast = temp.find_last_of(letters);
			m_features += temp.substr(strFirst, strLast - strFirst + 1);
		}
	}
	Cheese::Cheese(const Cheese& other)
	{
		*this = other;
	}

	Cheese Cheese::slice(size_t weight)
	{
		Cheese temp{};
		if (weight <= m_weight) {
			temp = *this;
			temp.m_weight = weight;
			m_weight -= weight;
		}
		return temp;
	}

	std::string Cheese::getName() const
	{
		return m_name;
	}
	size_t Cheese::getWeight() const
	{
		return m_weight;
	}
	double Cheese::getPrice() const
	{
		return m_price;
	}
	std::string Cheese::getFeatures() const
	{
		return m_features;
	}

	ostream& Cheese::print(ostream& os) const
	{
		os.setf(ios::left);
		{
			os << '|';
			os.width(nameW);
			os << ((m_name.length() <= nameW) ? m_name : m_name.substr(0, nameW)) << '|';

			os.width(weightW);
			os << m_weight << '|';

			os.width(priceW); os.precision(2);
			os.setf(ios::fixed);
			{
				os << m_price << '|';
			}
			os.unsetf(ios::fixed);

			os.width(featuresW);
			os.setf(ios::right);
			{
				os << ((m_features.length() <= featuresW) ? m_features : m_features.substr(0, featuresW)) << " |\n";
			}
			os.unsetf(ios::right);
		}
		os.unsetf(ios::left);

		return os;
	}

	Cheese& Cheese::operator=(const Cheese& other)
	{
		if (this != &other) {
			m_name = other.m_name;
			m_weight = other.m_weight;
			m_price = other.m_price;
			m_features = other.m_features;
		}
		return *this;
	}

	ostream& operator<<(ostream& os, const Cheese& right)
	{
		return right.print(os);
	}
}