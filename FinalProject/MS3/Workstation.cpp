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
	std::deque<CustomerOrder>
		g_pending,
		g_completed,
		g_incomplete;

	void Workstation::fill(std::ostream& os)
	{
		if (!m_orders.empty())
			m_orders.begin()->fillItem(*this, os);
	}

	bool Workstation::attemptToMoveOrder()
	{
		bool moved{};
		if (!m_orders.empty()) {
			if (m_orders.front().isItemFilled(getItemName())) {
				if (!m_pNextStation) {

					if (m_orders.front().isOrderFilled()) 
						g_completed.push_back(move(m_orders.front()));
					
					else 
						g_incomplete.push_back(move(m_orders.front()));

					m_orders.pop_front();
				}
				else {
					*m_pNextStation += move(m_orders.front());
					m_orders.pop_front();
				}
				moved = true;
			}
			else if (getQuantity() == 0) {
				if (!m_pNextStation) {
					g_incomplete.push_back(move(m_orders.front()));
					m_orders.pop_front();
				}
				else {
					*m_pNextStation += move(m_orders.front());
					m_orders.pop_front();
				}
				moved = true;
			}
		}
		return moved;
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