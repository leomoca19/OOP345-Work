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
		// to read from inputs
		string record{};
		ifstream input(file);

		// temp stations and their string names
		string current{}, next{};
		Workstation* currentSt{}, * nextSt{}, * firstSt{};

		if (!input)
			throw string("Unable to open file ") + file;


		while (getline(input, record)) {
			// to use Utilities class
			Utilities util;
			size_t next_pos{ 0 };
			bool more{ true };

			current = util.extractToken(record, next_pos, more);
			currentSt= *find_if(stations.begin(), stations.end(), [&](Workstation* station) {
				return station->getItemName() == current;
				});
			m_activeLine.push_back(currentSt);

			if (more) {
				next = util.extractToken(record, next_pos, more);
				nextSt= *find_if(stations.begin(), stations.end(), [&](Workstation* station) {
					return station->getItemName() == next;
					});
				currentSt->setNextStation(nextSt);
			}
		}
		for_each(stations.begin(), stations.end(), [&](Workstation* station) {
			firstSt = *find_if(stations.begin(), stations.end(), [&](Workstation* station) {
				return station->getNextStation() == firstSt;
				});
			});

		m_firstStation = firstSt;

		m_cntCustomerOrder = g_pending.size();
		input.close();
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
		for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* station) {
			station->display(os); 
			});
	}
}