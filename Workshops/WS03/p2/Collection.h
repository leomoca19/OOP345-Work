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
			formatToPrecision1();
			return m_smallestItem;
		}
		T getLargestItem() { 
			formatToPrecision1();
			return m_largestItem;
		}

		size_t size() const { return m_size; }
		size_t capacity() const { return C; }
		std::ostream& print(std::ostream& os) const {
			std::cout << '[';

			//prints the item and a comma for all but last item
			for (size_t i = 0; i < m_size - 1; i++)
				std::cout << m_items[i] << ',';

			//prints last item without comma after
			return std::cout << m_items[m_size - 1] << "]\n";
		}

		bool operator+=(const T& newItem) {
			bool added{};
			if ((added = m_size < C))
			{
				if (newItem < m_smallestItem)
					setSmallestItem(newItem);
				else if (newItem > m_largestItem)
					setLargestItem(newItem);

				m_items[m_size++] = newItem;
			}
			return added;
		}
		T operator[](const size_t& i) const { //check if should be const
			T temp;
			if (i < m_size)
				temp = m_items[i];
			return temp;
		}

		void incrSize() { m_size++; }
	};

	void formatToPrecision1() {
		std::cout.setf(std::ios::fixed);
		std::cout.precision(1);
	}

	template <typename T, unsigned C>
	T Collection<T, C>::m_smallestItem = 9999;
	template <typename T, unsigned C>
	T Collection<T, C>::m_largestItem = -9999;


	template <>
	Book Collection<Book, 10>::m_smallestItem = Book("", 1, 1000);
	template <>
	Book Collection<Book, 10>::m_largestItem = Book("", 1000, 1);

	template <>
	Book Collection<Book, 72>::m_smallestItem = Book("", 1, 1000);
	template <>
	Book Collection<Book, 72>::m_largestItem = Book("", 1000, 1);

	template<>
	std::ostream& Collection<Book, 10>::print(std::ostream& os) const {
		throw "I still have ot implement this";
		/* This should be thoe output, this function is in charged of printing each of these chars
		| ---------------------------------------------------------------------------|
		|          Software Architecture for Busy Developers,7,174 | (24.857143)     |
		|      Low-Code Application Development with Appian,16,462 | (28.875000)     |
		|       Natural Language Processing with TensorFlow,11,514 | (46.727273)     |
		|                                   Learning DevOps,17,560 | (32.941176)     |
		|                             SQL for Data Analytics,9,540 | (60.000000)     |
		|  Deciphering Object-Oriented Programming with C++,21,594 | (28.285714)     |
		| ---------------------------------------------------------------------------|
		*/
		return os;
	}
	template<>
	std::ostream& Collection<Book, 72>::print(std::ostream& os) const {
		throw "I still have ot implement this";
		return os;
	}
}
#endif // !SDDS_COLLECTION_H
