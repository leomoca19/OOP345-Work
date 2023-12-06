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
	LineManager::LineManager(const string& file, const vector<Workstation*>& stations)
	{
		string record{};
		ifstream input(file);

		if (!input)
			throw string("Unable to open file ") + file;


		while (getline(input, record)) {
			Utilities util;
			size_t next_pos{ 0 };
			bool more{ true };
			Workstation *nextSt{};

			const auto current = util.extractToken(record, next_pos, more);
			const auto currentSt = find_if(stations.begin(), stations.end(), [&current](Workstation* station) {
				return station->getItemName() == current;
				});

			if (more) {
				const auto next = util.extractToken(record, next_pos, more);

				nextSt = *find_if(stations.begin(), stations.end(), [&](Workstation* station) {
					return station->getItemName() == next;
					});
			}

			m_activeLine.emplace_back(*currentSt)->setNextStation(nextSt);
		}
		
		m_firstStation = m_activeLine.front();
		m_cntCustomerOrder = g_pending.size();
		input.close();
	}

	void LineManager::reorderStations()
	{
		const auto last_station = find_if(m_activeLine.begin(), m_activeLine.end(), [](const Workstation* station) {
			return !(*station).getNextStation();
			});

		swap(*last_station, m_activeLine.back());
		const auto* station_ptr = &m_activeLine.back()->getItemName();

		for (auto i = m_activeLine.size() - 1; i > 0; --i) {
			const auto matching_station = find_if(m_activeLine.begin(), m_activeLine.end(), [&station_ptr](const Workstation* innerStation)
				{return (*innerStation).getNextStation()->getItemName() == *station_ptr; });

			swap(*matching_station, m_activeLine[i - 1]);
			station_ptr = &m_activeLine[i - 1]->getItemName();
		}

		m_firstStation = m_activeLine.front();
	}
	bool LineManager::run(ostream& os)
	{
		static auto count = 1;
		static const auto max_orders = g_pending.size();
		os << "Line Manager Iteration: " << count << "\n";

		if (!g_pending.empty()) {
			*m_firstStation += move(g_pending.front());
			g_pending.pop_front();
		}

		for_each(m_activeLine.begin(), m_activeLine.end(), [&os](Workstation* ws)
			{ws->fill(os); });

		for_each(m_activeLine.cbegin(), m_activeLine.cend(), [](Workstation* internal_ws)
			{ internal_ws->attemptToMoveOrder(); });

		++count;

		return g_completed.size() + g_incomplete.size() == max_orders;
	}
	void LineManager::display(ostream& os) const
	{
		for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* station) {
			station->display(os); 
			});
	}
}