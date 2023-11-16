// Name: Leonardo de la mora Caceres
// Seneca Student ID: 152877205
// Seneca email: lde-la-mora-canceres@myseneca.ca
// Date of completion: 2023-Nov-14
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.
#include <iostream>
#include <algorithm>
#include "Utilities.h"
#include "Station.h"
using namespace std;
namespace sdds {
	size_t Station::m_widthField{},
		Station::id_generator{};

	Station::Station(const std::string& record) : m_id(id_generator++) {
		Utilities util;
		size_t npos{};
		bool more{ 1 };

		m_itemName = util.extractToken(record, npos, more);
		m_serial = stoi(util.extractToken(record, npos, more));
		m_quantity = stoi(util.extractToken(record, npos, more));

		m_widthField = max(util.getFieldWidth(), m_widthField);

		m_description = util.extractToken(record, npos, more);
	}

	const string& Station::getItemName() const {
		return m_itemName;
	}

	size_t Station::getNextSerialNumber()
	{
		return m_serial++;
	}

	size_t Station::getQuantity() const
	{
		return m_quantity;
	}

	void Station::updateQuantity()
	{
		m_quantity = m_quantity ? --m_quantity : 0;
	}

	void Station::display(std::ostream& os, bool full) const
	{
		os.setf(ios::left);

		os.width(3); os.fill('0');
		os << m_id << " | ";
		os.fill(' ');

		os.width(m_widthField);
		os << m_itemName << " | ";

		os.width(6);
		os << m_serial << " | ";

		if (full)
		{
			os.width(4);
			os << m_quantity << " | " << m_description;
		}

		os << endl;
		os.unsetf(ios::left);
	}
}
