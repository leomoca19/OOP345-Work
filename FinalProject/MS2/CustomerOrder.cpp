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
	CustomerOrder::CustomerOrder(const std::string& record) : m_cntItem{}
	{
		Utilities util{};
		size_t next_pos{};
		bool more{ 1 };

		m_name = util.extractToken(record, next_pos, more);
		m_product = util.extractToken(record, next_pos, more);

		m_lstItem = new Item * [m_cntItem];

		while (more) {
			string itemname = util.extractToken(record, next_pos, more);
			m_lstItem[m_cntItem++] = new Item(itemname);
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