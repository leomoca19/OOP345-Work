// Name: Leonardo de la mora Caceres
// Seneca Student ID: 152877205
// Seneca email: lde-la-mora-canceres@myseneca.ca
// Date of completion: 2023-Nov-29
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.
#include "Workstation.h"
using namespace std;
namespace sdds {
	void Workstation::fill(std::ostream& os)
	{
		if (!m_orders.empty())
			m_orders.front().fillItem(*this, os);
	}

	bool Workstation::attemptToMoveOrder()
	{
		if (!m_orders.empty()) {
			CustomerOrder& order = m_orders.front();

			if (order.isItemFilled(getItemName()) || !getQuantity()) {
				if (!m_pNextStation) {
					if (order.isOrderFilled()) {
						g_completed.push_back(std::move(order));
						m_orders.pop_front();
						return true;
					}

					else {
						g_incomplete.push_back(std::move(order));
						m_orders.pop_front();
						return true;
					}
				}

				m_pNextStation->m_orders.push_back(std::move(order));
				m_orders.pop_front();
				return true;
			}
		}

		return false;
	}

	void Workstation::display(std::ostream& os) const
	{
		os << getItemName() 
			<< " --> "
			<< (!m_pNextStation 
				? "End of Line" 
				: m_pNextStation->getItemName()) 
			<< '\n';
	}

	Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
	{
		m_orders.push_back(move(newOrder));
		return *this;
	}

}