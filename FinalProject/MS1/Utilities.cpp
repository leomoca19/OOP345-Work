// Name: Leonardo de la mora Caceres
// Seneca Student ID: 152877205
// Seneca email: lde-la-mora-canceres@myseneca.ca
// Date of completion: 2023-Nov-14
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.
#include "Utilities.h"
using namespace std;
namespace sdds {
	char Utilities::m_delimiter = '\0';

	void Utilities::setFieldWidth(size_t newWidth){
		m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const{
		return m_widthField;
	}

	string Utilities::extractToken(const string& str, size_t& next_pos, bool& more){
        size_t delimiter_pos = str.find(m_delimiter, next_pos);
        std::string token;

		//To be completed

		return token;
	}

	void Utilities::setDelimiter(char newDelimiter){
		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter() {
		return m_delimiter;
	}
}