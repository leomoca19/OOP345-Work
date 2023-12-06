// Name: Leonardo de la mora Caceres
// Seneca Student ID: 152877205
// Seneca email: lde-la-mora-canceres@myseneca.ca
// Date of completion: 2023-Nov-14
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.
#ifndef STATION_H
#define STATION_H
#include <string>
namespace sdds {
	class Station {
		static inline size_t
			m_widthField{1},
			id_generator{};

		int m_id{};

		size_t
			m_serial{},
			m_quantity{};

		std::string
			m_itemName{},
			m_description{};

	public:
		Station() = default;

		explicit Station(const std::string& record);

		const std::string& getItemName() const { return m_itemName; }

		size_t getNextSerialNumber() { return m_serial++; }

		size_t getQuantity() const { return m_quantity; }

		void updateQuantity() { m_quantity = m_quantity > 0 ? m_quantity - 1 : 0; }

		void display(std::ostream& os, bool full) const;			
	};
}
#endif // !STATION_H
