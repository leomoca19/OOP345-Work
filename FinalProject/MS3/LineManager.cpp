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
	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
	{
		Utilities util;
		ifstream input;
		string record;

		if (file.empty()) 
			throw string("ERROR: No filename provided.");

		input.open(file);
		if (!input)
			throw string("Unable to open file ") + file;


		while (getline(input, record)) {
			Workstation* currentSt;
			Workstation* nextSt;
			size_t next_pos{};
			bool more{ true };


			//////the error is here, after finding the name of th station, it must find the line or something like that
			currentSt = new Workstation(util.extractToken(record, next_pos, more));
			nextSt = new Workstation(util.extractToken(record, next_pos, more));
			//////


			//load the contents of the file


			m_activeLine.push_back(currentSt);
			m_activeLine.push_back(nextSt);


			currentSt->setNextStation(nextSt);
		}

		if (!m_activeLine.empty()) 
			m_firstStation = m_activeLine.front();
		else 
			throw std::string("ERROR: No workstations found in the file.");


		m_cntCustomerOrder = g_pending.size();

		input.close();
	}
	void LineManager::reorderStations()
	{
	}
	bool LineManager::run(std::ostream& os)
	{
		bool filled{};
		return filled;
	}
	void LineManager::display(std::ostream& os) const
	{
	}
}