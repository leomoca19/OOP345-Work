// Name: Leonardo de la mora Caceres
// Seneca Student ID: 152877205
// Seneca email: lde-la-mora-canceres@myseneca.ca
// Date of completion: 2023-Nov-14
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.
#include <iostream>
#include <string>
#include <iomanip>
#include "Utilities.h"
#include "Station.h"
using namespace std;
namespace sdds {
	Station::Station(const std::string& record) : m_id(++id_generator) {
		Utilities util;
		size_t next_pos{};
		bool more{ 1 };

		m_itemName = util.extractToken(record, next_pos, more);
		m_serial = stoi(util.extractToken(record, next_pos, more));
		m_quantity = stoi(util.extractToken(record, next_pos, more));

		m_widthField = max(util.getFieldWidth(), m_widthField);
		m_description = util.extractToken(record, next_pos, more);
	}

	void Station::display(std::ostream& os, bool full) const
	{
		os << setw(3) << setfill('0') << right << m_id << " | "
			<< setw(m_widthField) << setfill(' ') << left << m_itemName << " | "
			<< setw(6) << setfill('0') << right << m_serial << " | "
			<< setfill(' ');

		if (full) 
			os << setw(4) << m_quantity << " | " << m_description;
		
		os << '\n';
	}
}
