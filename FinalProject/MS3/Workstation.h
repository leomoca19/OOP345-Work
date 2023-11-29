// Name: Leonardo de la mora Caceres
// Seneca Student ID: 152877205
// Seneca email: lde-la-mora-canceres@myseneca.ca
// Date of completion: 2023-Nov-29
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.
#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H
#include <deque>
#include <string>
#include "Station.h"
#include "CustomerOrder.h"
namespace sdds{
	class Workstation : public Station {
		std::deque<CustomerOrder> m_orders;
		Workstation* m_pNextStation{};

	public:

		Workstation(const std::string& record) : Station(record){}
		
		Workstation(const Workstation& other) = delete;
		Workstation& operator=(const Workstation& other) = delete;

		Workstation(Workstation&& other) = delete;
		Workstation& operator=(Workstation&& other) = delete;


		/// <summary>
		/// fills the order at the front of the queue only if there are CustomerOrders in the queue
		/// </summary>
		/// <param name="os"></param>
		void fill(std::ostream& os); 

		/// <summary>
		/// moves order order at the front of the queue to next station in the assembly line
		/// </summary>
		/// <returns>true if an order has been moved</returns>
		bool attemptToMoveOrder(); 

		/// <summary>
		/// stores the address of the referenced Workstation object in the pointer to the m_pNextStation
		/// </summary>
		/// <param name="station">defaults to nullptr</param>
		void setNextStation(Workstation* station = nullptr); 

		/// <returns>address of next Workstation</returns>
		Workstation* getNextStation() const { return m_pNextStation; }

		/// <summary>
		/// inserts the name of the Item for which the current object is responsible into stream os following the format : ITEM_NAME-- > NEXT_ITEM_NAME
		///
		/// if the current object is the last Workstation in the assembly line this query inserts : ITEM_NAME-- > End of Line.
		///
		/// in either case, the message is terminated with \n
		/// </summary>
		/// <param name="os"></param>
		void display(std::ostream& os) const;

		/// <summary>
		/// moves the CustomerOrder referenced in newOrder to the back of the queue
		/// </summary>
		/// <param name="newOrder"></param>
		/// <returns></returns>
		Workstation& operator+=(CustomerOrder&& newOrder);
	 };
}
#endif // !SDDS_WORKSTATION_H
