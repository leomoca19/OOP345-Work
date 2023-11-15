// Name: Leonardo de la mora Caceres
// Seneca Student ID: 152877205
// Seneca email: lde-la-mora-canceres@myseneca.ca
// Date of completion: 2023-Nov-14
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.
#ifndef UTILITIES_H
#define UTILITIES_H
namespace sdds {
	class Utilities {
		static char m_delimiter;
		size_t m_widthField;

	public:
		/// <summary>
		/// sets the field width of the current object to the value of parameter `newWidth`
		/// </summary>
		void setFieldWidth(size_t newWidth);

		/// <summary>
		/// returns the field width of the current object
		/// </summary>
		size_t getFieldWidth() const;

		/// <summary>
		///  extracts a token from string `str` referred to by the first parameter
		/// </summary>
		/// 
		/// <how it works>
		/// uses the delimiter to extract the next token from `str` starting at position `next_pos`
		///		-If successful, return a copy of the extracted token found(without spaces at the 
		///		beginning / end),    update `next_pos` with the position of the next token, and set 
		///		`more` to `true` (`false` otherwise)
		/// 
		///		-reports an exception if a delimiter is found at `next_pos`
		/// 
		///		-updates the current object's `m_widthField` data member if its current value is less 
		///		than the size	of the token extracted
		/// </how it works>
		/// 
		/// <note>
		/// in this application, `str` represents a single line that has been read from an input file
		/// </note>
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);

		/// <summary>
		/// sets the delimiter for this class to the character received
		/// </summary>
		static void setDelimiter(char newDelimiter);

		/// <summary>
		/// returns the delimiter for this class
		/// </summary>
		static char getDelimiter();
	};
}
#endif // !UTILITIES_H
