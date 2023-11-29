// Name: Leonardo de la mora Caceres
// Seneca Student ID: 152877205
// Seneca email: lde-la-mora-canceres@myseneca.ca
// Date of completion: 2023-Nov-29
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.
#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H
#include <vector>
#include <iostream>
#include "Workstation.h"
namespace sdds {
	class LineManager {
		std::vector<Workstation*> m_activeLine;
		size_t m_cntCustomerOrder{};
		Workstation* m_firstStation;

	public:

		/// \brief configures the assembly line based on the given file and collection of workstations:
		/// Stores the workstations in the order received in m_activeLine. It loads the contents of the file, stores the address of the next workstation in each element of the collection, identifies the first station in the assembly line and stores its address in the m_firstStation. Also updates the total number of orders in g_pending queue. If an error occurs during this process, the constructor reports the error.
		/// \param file The name of the file that identifies the active stations on the assembly line 
		/// \param stations A collection of workstations available for configuring the assembly line
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);

		/// \brief  reorders the workstations in m_activeLine.
		/// 
		/// The elements in the reordered collection start with the first station, proceeds to the next, and so forth until the end of the line
		void reorderStations();

		/// \brief  performs one iteration of operations on all of the workstations in the current assembly line by doing the following :
		/// keeps track of the current iteration number, 
		///	inserts into os the iteration number in the format Line Manager Iteration : COUNT<endl>, 
		///	moves the order at the front of the g_pending queue to the m_firstStation and remove it from the queue, 
		/// for each station, executes one fill operation, 
		///	for each station, attempts to move an order down the line
		/// 
		/// \param os An ostream reference
		/// \return true if all customer orders have been filled or cannot be filled
		bool run(std::ostream& os);

		/// \brief displays all active stations on the assembly line in their current order
		void display(std::ostream& os) const;
	};
}
#endif // !SDDS_LINEMANAGER_H
