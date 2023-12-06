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
	inline std::deque<CustomerOrder>
		g_pending, 
		g_completed,
		g_incomplete;

	class Workstation : public Station {
		std::deque<CustomerOrder> m_orders{};
		Workstation* m_pNextStation{};

	public:
		Workstation() = default;
		explicit Workstation(const std::string& record) : Station(record){}
		
		Workstation(const Workstation& other) = delete;
		Workstation& operator=(const Workstation& other) = delete;

		Workstation(Workstation&& other) = delete;
		Workstation& operator=(Workstation&& other) = delete;


		void fill(std::ostream& os); 
		bool attemptToMoveOrder(); 
		void setNextStation(Workstation* station = nullptr) { m_pNextStation = station; }
		Workstation* getNextStation() const { return m_pNextStation; }
		void display(std::ostream& os) const;
		Workstation& operator+=(CustomerOrder&& newOrder);
	 };
}
#endif // !SDDS_WORKSTATION_H
