// Name: Leonardo de la mora Caceres
// Seneca Student ID: 152877205
// Seneca email: lde-la-mora-canceres@myseneca.ca
// Date of completion: 2023-Nov-18
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.
#ifndef CUSTOMERS_H
#define CUSTOMERS_H
#include <iostream>
#include "Station.h"
namespace sdds {
	struct Item
	{
		std::string m_itemName;
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };

		Item(const std::string& src) : m_itemName(src) {};
	};

	class CustomerOrder {
		static size_t m_widthField;

		std::string m_name{};
		std::string m_product{};
		size_t m_cntItem{};
		Item** m_lstItem{};

		void clearLstItem();
	public:
		CustomerOrder() {}
		CustomerOrder(const std::string& record);
		CustomerOrder(CustomerOrder&& other) noexcept;
		CustomerOrder& operator=(CustomerOrder&& other) noexcept;
		~CustomerOrder();

		CustomerOrder(CustomerOrder& other) = delete; // maybe remove delete and make it throw
		CustomerOrder& operator=(CustomerOrder& other) = delete;

		bool isOrderFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream & os) const; 
	};
}
#endif // !CUSTOMERS_H
