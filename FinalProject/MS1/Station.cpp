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
		return size_t();
	}

	void Station::updateQuantity()
	{
	}

	void Station::display(std::ostream& os, bool full) const
	{
		os << m_id << " | " << m_itemName << " | " << m_serial << " | "
			<< (full ? m_quantity + " | " + m_description : "") << endl;

		//`ID` field uses 3 characters, `NAME` field uses `m_widthField` characters,
		//`QUANTITY` field uses 4 characters, `SERIAL` field uses 6 characters

		//`DESCRIPTION` has no formatting options
	}
}
