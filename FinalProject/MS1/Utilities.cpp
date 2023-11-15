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
	void Utilities::setFieldWidth(size_t newWidth){
		m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const{
		return m_widthField;
	}

	string Utilities::extractToken(const string& str, size_t& next_pos, bool& more){
		string str_{};
		size_t i{ next_pos };
		bool success{};

		//uses the delimiter to extract the next token from `str` starting at position `next_pos`
		while (str[i] != m_delimiter) {

		}


		if (success) {
			///	-If successful, return a copy of the extracted token found(without spaces at the 
			///	beginning / end),    update `next_pos` with the position of the next token, and set 
			///	`more` to `true` (`false` otherwise)
		}
		///		-reports an exception if a delimiter is found at `next_pos`
		///		-updates the current object's `m_widthField` data member if its current value is less 
		///		than the size	of the token extracted


		return str_;
	}

	void Utilities::setDelimiter(char newDelimiter){}

	char Utilities::getDelimiter() {
		return m_delimiter;
	}
}