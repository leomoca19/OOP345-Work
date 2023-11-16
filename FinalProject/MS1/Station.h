// Name: Leonardo de la mora Caceres
// Seneca Student ID: 152877205
// Seneca email: lde-la-mora-canceres@myseneca.ca
// Date of completion: 2023-Nov-14
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.
#ifndef STAION_H
#define STAION_H
#include <string>
namespace sdds {
	class Station {
		static size_t
			m_widthField,
			id_generator;

		int m_id;

		size_t
			m_serial,
			m_quantity;

		std::string
			m_itemName,
			m_description;

	public:
		/// <summary>
		/// This string	contains a single record (one line) that has been retrieved from the 
		///	input file specified by the	user
		/// 
		///	- this constructor uses a `Utilities` object (defined locally) to extract each token 
		/// from the record and		populates the `Station` object accordingly
		/// 
		///	- this constructor assumes that the string contains 4 fields separated by the 
		/// delimiter, in the following   	order:
		///		-name of the item
		///		- starting serial number
		///		- quantity in stock
		///		- description
		///
		///	- the token delimiter is a single character, specified by the client and previously stored 
		/// into thec `Utilities` class of objects
		/// 
		///	- this constructor extracts *name*, *starting serial number*, and *quantity* from the string first
		/// 
		///	- before extracting *description*, it updates `Station::m_widthField` to the maximum 
		/// value `Station::m_widthField` and `Utilities::m_widthField`
		/// 
		///	- **Note:**  the `display(...)` member function uses this field width to align the output across all
		/// the	records retrieved from the file
		/// </summary>
		Station(const std::string& record);

		/// <summary>
		/// -returns the name of the current `Station` object
		/// </summary>
		/// <returns></returns>
		const std::string& getItemName() const;

		/// <summary>
		/// returns the next serial number to be used on the assembly line and increments `m_serialNumber`
		/// </summary>
		/// <returns></returns>
		size_t getNextSerialNumber();

		/// <summary>
		/// returns the remaining quantity of items in the `Station` object
		/// </summary>
		/// <returns></returns>
		size_t getQuantity() const;

		/// <summary>
		/// subtracts 1 from the available quantity; should not drop below 0
		/// </summary>
		void updateQuantity();

		/// <summary>
		///  inserts information about the current object into stream 'os'
		///		-if the second parameter is `false`, this function inserts only the ID, name, and serial 
		///		number in the format : `ID | NAME | SERIAL | `
		/// 
		///		-if the second parameter if `true`, this function inserts the information in the 
		///		following format : `ID | NAME | SERIAL | QUANTITY | DESCRIPTION`
		/// 
		///		-the `ID` field uses 3 characters, the `NAME` field uses `m_widthField` characters,
		///		 the `QUANTITY` field uses 4 characters, the `SERIAL` field uses 6 characters; the 
		///		`DESCRIPTION` has no formatting options(see the sample output for other formatting 
		///		options)
		/// 
		///		-this function terminates the printed message with an endline
		/// </summary>
		/// <param name="os"></param>
		/// <param name="full"></param>
		void display(std::ostream& os, bool full) const;			
	};
}
#endif // !STAION_H
