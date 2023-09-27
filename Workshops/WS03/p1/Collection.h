/***********************************************************************
Author: Leonardo de la Mora Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: 28-September-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iostream>
#include "Book.h"
namespace sdds {
	template <typename T, unsigned C>
	class Collection {
		T m_items[C];
		size_t m_size{};
		static T m_smallestItem;
		static T m_largestItem;

	protected:
		void setSmallestItem(const T& newSmallest) {
			if (newSmallest < m_smallestItem)
				m_smallestItem = newSmallest;
		}
		void setLargestItem(const T& newLargest) {
			if (newLargest > m_largestItem)
				m_largestItem = newLargest;
		}	

	public:
		T getSmallestItem() { 
			// added them here because I need to execute this lines to format the 
			// output and I don't know where elese to put it
			std::cout.setf(std::ios::fixed);
			std::cout.precision(1);
			return m_smallestItem; }
		T getLargestItem() { return m_largestItem; }

		size_t size() const { return m_size; }
		size_t capacity() const { return C; }
		std::ostream& print(std::ostream& os) const {
			std::cout << '[';

			//prints the item and a comma for all but last item
			for (size_t i = 0; i < m_size - 1; i++)
				std::cout << m_items[i] << ',';

			//prints last item without comma after
			return std::cout << m_items[m_size - 1] << ']';
		}

		bool operator+=(const T& newItem) {
			bool added{};
			if (added = m_size < C) 
			{
				if (newItem < m_smallestItem)
					setSmallestItem(newItem);
				else if (newItem > m_largestItem)
					setLargestItem(newItem);

				m_items[m_size++] = newItem;
			}
			return added;
		}
	};

	template <typename T, unsigned C>
	T Collection<T, C>::m_smallestItem = 9999;

	template <typename T, unsigned C>
	T Collection<T, C>::m_largestItem = -9999;

	template <>
	Book Collection<Book, 10>::m_smallestItem = Book("", 1, 1000);

	template <>
	Book Collection<Book, 10>::m_largestItem = Book("", 1000, 1);
}
#endif // !SDDS_COLLECTION_H
