// Name: Leonardo de la mora Caceres
// Seneca Student ID: 152877205
// Seneca email: lde-la-mora-canceres@myseneca.ca
// Date of completion: 2023-Nov-29
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "LineManager.h"
#include "Utilities.h"
using namespace std;
namespace sdds {
	LineManager::LineManager(const std::string& filename, const std::vector<Workstation*>& stations) {
		Utilities util;
		ifstream file(filename);
		if (!file) {
			throw "Incorrect file name!";
		}
		else {
			string str = "";
			string currentStr = "";
			string nextStr = "";
			bool more;
			size_t next_pos = 0;
			Workstation* currentStation = nullptr;
			Workstation* nextStation = nullptr;
			Workstation* firstStation = nullptr;
			while (getline(file, str)) {
				currentStr = util.extractToken(str, next_pos, more);
				currentStation = *find_if(stations.begin(), stations.end(), [&](Workstation* station) {
					return station->getItemName() == currentStr;
					});
				m_activeLine.push_back(currentStation);
				if (more) {
					nextStr = util.extractToken(str, next_pos, more);
					nextStation = *find_if(stations.begin(), stations.end(), [&](Workstation* station) {
						return station->getItemName() == nextStr;
						});
					currentStation->setNextStation(nextStation);
				}
			}
			for_each(stations.begin(), stations.end(), [&](Workstation* station) {
				firstStation = *find_if(stations.begin(), stations.end(), [&](Workstation* station) {
					return station->getNextStation() == firstStation;
					});
				});
			m_firstStation = firstStation;
		}
		file.close();
		m_cntCustomerOrder = g_pending.size();
	}

	void LineManager::reorderStations()
	{
		Workstation* station = m_firstStation;
		vector<Workstation*> reordered;

		while (station) {
			reordered.push_back(station);
			station = station->getNextStation();
		}

		m_activeLine = reordered;
	}
	bool LineManager::run(ostream& os)
	{
		static size_t count = 1;

		os << "Line Manager Iteration: " << count++ << '\n';

		if (!g_pending.empty()) {
			*m_firstStation += move(g_pending.front());
			g_pending.pop_front();
		}

		for (const auto& station : m_activeLine)
			station->fill(os);

		for (const auto& station : m_activeLine)
			station->attemptToMoveOrder();

		return m_cntCustomerOrder == g_completed.size() + g_incomplete.size();
	
	}
	void LineManager::display(ostream& os) const
	{
		for (const auto& station : m_activeLine)
			station->display(os);
	}
}