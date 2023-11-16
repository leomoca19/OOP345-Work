// Name: Leonardo de la mora Caceres
// Seneca Student ID: 152877205
// Seneca email: lde-la-mora-canceres@myseneca.ca
// Date of completion: 2023-Nov-14
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.
#include <algorithm>
#include "Utilities.h"
using namespace std;
namespace sdds {
	char Utilities::m_delimiter = '\0';

	void Utilities::setFieldWidth(size_t newWidth) {
		m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const {
		return m_widthField;
	}

	string Utilities::extractToken(const string& str, size_t& next_pos, bool& more) {
		size_t delimiter_pos = str.find(m_delimiter, next_pos);
		std::string token{};
		size_t trimStart{},
			trimEnd{};

		if (delimiter_pos != next_pos)
		{
			token = str.substr(next_pos, delimiter_pos - next_pos);
			next_pos = delimiter_pos + 1;
		}
		else
		{
			throw "delimiter found at next_pos";
			more = 0;
		}

		trimStart = token.find_first_not_of(' ');
		trimEnd = token.find_last_not_of(' ');
		token = 
			(trimStart != trimEnd)
			? token.substr(trimStart, trimStart - trimEnd)
			: token.substr(trimStart);

		m_widthField = max(m_widthField, token.length());

		return token;
	}

	void Utilities::setDelimiter(char newDelimiter) {
		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter() {
		return m_delimiter;
	}
}