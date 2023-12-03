// Name: Leonardo de la mora Caceres
// Seneca Student ID: 152877205
// Seneca email: lde-la-mora-canceres@myseneca.ca
// Date of completion: 2023-Nov-14
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.
#include <algorithm>
#include <string>
#include <iostream>
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
		string token;
		size_t i = next_pos;

		while (i < str.length() && str[i] != m_delimiter) 
			++i;
		

		if (i == next_pos || (i == str.length() && str[i - 1] == m_delimiter)) {
			more = false;
			throw runtime_error("Error: Bad token");
		}

		token = str.substr(next_pos, i - next_pos);

		next_pos = i + 1;
		trim(token);

		m_widthField = max(m_widthField, token.length());

		more = true;
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
		size_t trimStart = str.find_first_not_of(' ');
		size_t trimEnd = str.find_last_not_of(' ');

		if (trimStart != string::npos && trimEnd != string::npos && trimStart < trimEnd)
			str = str.substr(trimStart, trimEnd - trimStart + 1);
		else if (trimStart != string::npos) 
			str = str.substr(trimStart);
		
		return str;
	}
}