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
		string token{};
		size_t i{ next_pos };
		bool found{};


		/*uses the delimiter to extract the next token from str starting at position next_pos.
	If successful, return a copy of the extracted token found(without spaces at the beginning / end), update next_pos with the position of the next token, and set more to true (false otherwise).
	reports an exception if a delimiter is found at next_pos.
	updates the current object's m_widthField data member if its current value is less than the size of the token extracted.
	Note : in this application, str represents a single line that has been read from an input file.*/


		for (;!found && (more = i < str.length()); i++)
			if ((found = str[i] == m_delimiter))
				break;

		try { // can be more consice, but my brain is fried
			if ((found && !more) || i == next_pos)
			{
				more = 0;
				throw false;
			}

			else if (!found && !more)
				throw true;
		}
		catch (bool& valid) {
			if (!valid)
				throw "bad token";
		}

		token = str.substr(next_pos, i - next_pos);
		next_pos = i + 1;

		trim(token);
		m_widthField = std::max(m_widthField, token.length());

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