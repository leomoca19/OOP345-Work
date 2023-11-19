// Name: Leonardo de la mora Caceres
// Seneca Student ID: 152877205
// Seneca email: lde-la-mora-canceres@myseneca.ca
// Date of completion: 2023-Nov-18
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.
#include "Utilities.h"
#include "CustomerOrder.h"
using namespace std;
namespace sdds {
	size_t CustomerOrder::m_widthField{};
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
	}
	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& other) noexcept
	{
		return *this;
	}
	CustomerOrder::~CustomerOrder()
	{
		for (size_t i = 0; i < m_cntItem; ++i) 
			delete m_lstItem[i];

		delete[] m_lstItem;
	}

	bool CustomerOrder::isOrderFilled() const
	{
		return false;
	}
	bool CustomerOrder::isItemFilled(const std::string& itemName) const
	{
		return false;
	}
	void CustomerOrder::fillItem(Station& station, std::ostream& os)
	{
	}
	void CustomerOrder::display(std::ostream& os) const
	{
	}
}