// Name: Leonardo de la mora Caceres
// Seneca Student ID: 152877205
// Seneca email: lde-la-mora-canceres@myseneca.ca
// Date of completion: 2023-Nov-18
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.
#include <iomanip>
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
	CustomerOrder::CustomerOrder(const std::string& record)
	{
		Utilities util{};
		size_t next_pos{};
		bool more{ true };

		m_name = util.extractToken(record, next_pos, more);
		m_product = util.extractToken(record, next_pos, more);

		while (more) {
			string itemname = util.extractToken(record, next_pos, more);
			auto temp = new Item* [m_cntItem + 1];

			for (size_t i{}; i < m_cntItem; ++i)
				temp[i] = m_lstItem[i];
			temp[m_cntItem++] = new Item(itemname);

			delete[] m_lstItem;
			m_lstItem = temp;

			m_widthField = max(util.getFieldWidth(), m_widthField);
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

			m_name = std::move(other.m_name);
			m_product = std::move(other.m_product);
			m_cntItem = std::move(other.m_cntItem);
			m_lstItem = std::move(other.m_lstItem);

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
		bool allFilled{ true};

		for (size_t i = 0; i < m_cntItem && allFilled; i++)
			allFilled = m_lstItem[i]->m_isFilled;

		return allFilled;
	}
	bool CustomerOrder::isItemFilled(const std::string& itemName) const
	{
		bool allFilled{ true };

		for (size_t i = 0; i < m_cntItem && allFilled; i++)
			if (itemName == m_lstItem[i]->m_itemName)
				allFilled = m_lstItem[i]->m_isFilled;

		return allFilled;
	}
	void CustomerOrder::fillItem(Station& station, std::ostream& os)
	{
		for (size_t i = 0; i < m_cntItem; ++i)
		{
			if (m_lstItem[i]->m_itemName == station.getItemName())
			{
				if (!m_lstItem[i]->m_isFilled)
				{
					if (station.getQuantity() > 0)
					{
						m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
						m_lstItem[i]->m_isFilled = true;
						station.updateQuantity();

						os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
					}
					else
					{
						os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
					}
				}
				else
				{
					os << "    " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "] already filled" << std::endl;
				}
				break;
			}
		}
	}
	void CustomerOrder::display(std::ostream& os) const
	{
		os << m_name << " - " << m_product << '\n';
		for (size_t i = 0; i < m_cntItem; ++i)
		{
			os << "[" << setw(6) << setfill('0') << m_lstItem[i]->m_serialNumber << "] " << setw(m_widthField) << setfill(' ') << left << m_lstItem[i]->m_itemName << " - "
				<< (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << endl;
		}
	}
}