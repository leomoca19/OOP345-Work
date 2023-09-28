/***********************************************************************
Author: Leonardo de la Mora Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: 28-September-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_ORDEREDCOLLECTION_H
#define SDDS_ORDEREDCOLLECTION_H
#include "Collection.h"
namespace sdds {
	template <typename T>
	class OrderedCollection : public Collection<T, 72> {
	public:
        bool operator+=(const T& newItem) {
            bool added{};
            if(added = Collection<T, 72>::operator+=(newItem))
                sortItems();
            return added;
        }
	};
}
#endif // !SDDS_ORDEREDCOLLECTION_H
