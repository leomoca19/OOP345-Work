// Name: Leonardo de la mora Caceres
// Seneca Student ID: 152877205
// Seneca email: lde-la-mora-canceres@myseneca.ca
// Date of completion: 2023-Nov-29
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.
#include <string>
#include <fstream>
#include "LineManager.h"
#include "Utilities.h"
using namespace std;
namespace sdds {
	LineManager::LineManager(const string& file, const vector<Workstation*>& stations)
	{
		Utilities util;
		string record{};
		ifstream input(file);

		if (!input)
			throw string("Unable to open file ") + file;


		while (getline(input, record)) {
			size_t next_pos{ 0 };
			bool more{ true };
			string current{}, next{};

			// Extract current and next workstation names from the record
			current = util.extractToken(record, next_pos, more);
			next = util.extractToken(record, next_pos, more);

			// Define lambda functions to find workstations by name
			auto findCurrent = [&](const Workstation* station) { 
				return station->getItemName() == current; 
			};
			auto findNext = [&](const Workstation* station) { 
				return station->getItemName() == next; 
			};

			// Find iterators pointing to the current and next workstations in the collection
			auto currentIt = find_if(stations.begin(), stations.end(), findCurrent);
			auto nextIt = find_if(stations.begin(), stations.end(), findNext);

			// Check if both current and next workstations are found in the collection
			if (currentIt != stations.end() && nextIt != stations.end())
				// Link the current workstation to the next workstation
				(*currentIt)->setNextStation(*nextIt);
			else
				// Throw an exception if the linkage is unsuccessful
				throw string("Unable to link stations [") + current + "] to [" + next + "].";
		}

		// Reserve space for the m_activeLine vector to improve performance
		m_activeLine.reserve(stations.size());

		// Find the iterator pointing to the first station on the assembly line
		auto it = find_if(stations.begin(), stations.end(),
			[&](const Workstation* station) { 
				return station->getNextStation() == nullptr; 
			}
		);

		// Check if the first station is found
		if (it != stations.end()) {
			m_firstStation = *it;
			m_cntCustomerOrder = g_pending.size();
		}
		else 
			throw string("Unable to find the first station on the assembly line.");
	}
	void LineManager::reorderStations()
	{
	}
	bool LineManager::run(ostream& os)
	{
		bool filled{};
		return filled;
	}
	void LineManager::display(ostream& os) const
	{
	}
}