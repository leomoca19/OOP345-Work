// Name: Leonardo de la mora Caceres
// Seneca Student ID: 152877205
// Seneca email: lde-la-mora-canceres@myseneca.ca
// Date of completion: 2023-Nov-18
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.
#include <iomanip>
#include <iostream>
#include <string>
#include "Utilities.h"
#include "CustomerOrder.h"
using namespace std;
namespace sdds {
	size_t CustomerOrder::m_widthField{};
	void CustomerOrder::clearLstItem()
	{
		for (size_t i = 0; i < m_cntItem; ++i)
			delete m_lstItem[i];

		delete[] m_lstItem;
	}
	CustomerOrder::CustomerOrder(const string& record)
	{
		Utilities util{};
		size_t next_pos{};
		bool more{ true };

		try{
			m_name = util.extractToken(record, next_pos, more);
			m_product = util.extractToken(record, next_pos, more);

			while (more) {
				string itemname = util.extractToken(record, next_pos, more);
				auto temp = new Item * [m_cntItem + 1];

				for (size_t i{}; i < m_cntItem; ++i)
					temp[i] = m_lstItem[i];
				temp[m_cntItem++] = new Item(itemname);

				delete[] m_lstItem;
				m_lstItem = temp;

				m_widthField = max(util.getFieldWidth(), m_widthField);
			}
		}
		catch(const exception& e){
			cerr << "Error during CustomerOrder construction: " << e.what() << '\n';
			throw;
		}
	}
	CustomerOrder::CustomerOrder(CustomerOrder&& other) noexcept
	{
		*this = move(other);
	}
	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& other) noexcept
	{
		if (this != &other) {
			clearLstItem();

			m_name = move(other.m_name);
			m_product = move(other.m_product);
			m_cntItem = move(other.m_cntItem);
			m_lstItem = move(other.m_lstItem);

			other.m_name.clear();
			other.m_product.clear();
			other.m_cntItem = 0;
			other.m_lstItem = nullptr;
		}

		return *this;
	}
	CustomerOrder::~CustomerOrder()
	{
		clearLstItem();
	}

	CustomerOrder::CustomerOrder(CustomerOrder& other)
	{
		throw "Copy construction of CustomerOder not allowed";
	}

	bool CustomerOrder::isOrderFilled() const
	{
		bool allFilled{true};

		for (size_t i = 0; i < m_cntItem && allFilled; ++i) 
			if (!m_lstItem[i]->m_isFilled) 
				allFilled = false;
			
		return allFilled;
	}
	bool CustomerOrder::isItemFilled(const string& itemName) const
	{
		bool allFilled{ true };

		for (size_t i = 0; i < m_cntItem && allFilled; ++i) 
			if (m_lstItem[i]->m_itemName == itemName && !m_lstItem[i]->m_isFilled) 
				allFilled = false;

		return allFilled;
	}
	void CustomerOrder::fillItem(Station& station, ostream& os)
	{
		const auto& station_name = station.getItemName();
		for (size_t i = 0; i < m_cntItem; ++i) 
			if (m_lstItem[i]->m_itemName == station_name) {
				if (!m_lstItem[i]->m_isFilled && station.getQuantity() > 0) {
					m_lstItem[i]->m_isFilled = true;
					station.updateQuantity();
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					os << "    Filled " << m_name << ", " << m_product << " [" << station_name << "]\n";
					return;
				}

				if (!m_lstItem[i]->m_isFilled && !station.getQuantity()) 
					os << "    Unable to fill " << m_name << ", " << m_product
						<< " [" << station_name << "]\n";
			}
	}
	void CustomerOrder::display(ostream& os) const
	{
		os << m_name << " - " << m_product << '\n';
		for (size_t i = 0; i < m_cntItem; i++) {
			os << '[' << right << setw(6) << setfill('0') << m_lstItem[i]->m_serialNumber;

			os << "] " << left << setw(m_widthField) << setfill(' ') << m_lstItem[i]->m_itemName << " - ";

			os << (m_lstItem[i]->m_isFilled ? "" : "TO BE ");

			os << "FILLED\n";
		}
	}
}