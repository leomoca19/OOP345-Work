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
        string token{};

        if (more = (delimiter_pos != string::npos &&
            delimiter_pos != next_pos)) {
            token = trim(str.substr(next_pos, delimiter_pos - next_pos));

            next_pos = delimiter_pos + 1;

            m_widthField = std::max(m_widthField, token.length());
        }
        else 
            throw "delimiter is found at next_pos";

        return token;
	}

	void Utilities::setDelimiter(char newDelimiter) {
		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter() {
		return m_delimiter;
	}

    string& trim(string& str)
    {
        size_t trimStart;
        size_t trimEnd;

        trimStart = str.find_first_not_of(' ');
        trimEnd = str.find_last_not_of(' ');

        if (trimStart != string::npos && trimEnd != string::npos && trimStart < trimEnd) {
            str= str.substr(trimStart, trimEnd - trimStart + 1);
        }
        else if (trimStart != string::npos) {
            str= str.substr(trimStart);
        }

        return str;
    }
}