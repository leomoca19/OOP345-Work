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
		if (m_orders.size())
		{
			m_orders.front().fillItem(*this, os);
			m_orders.pop_front();
		}
	}

}