#pragma once
#ifndef WINCOPIES_ICOLLECTION_H
#define WINCOPIES_ICOLLECTION_H

#include "Enumeration/IEnumerable.h"

namespace WinCopies
{
	namespace Collections
	{
		INTERFACE_CLASS(IReadOnlyCollection)
		{
		public:
			virtual bool IsReadOnly() = 0;
		};

		INTERFACE_CLASS(ICollection) :
			BASE_INTERFACE IReadOnlyCollection
		{
		public:
			virtual ErrorCode Clear() = 0;
		};

		INTERFACE_CLASS(IList)
		{
		public:
            virtual bool GetIsFixedSize() = 0;

            virtual int RemoveAt(const int index) = 0;
		};

		namespace Generic
		{
			TEMPLATE
				INTERFACE_CLASS(ICollection) :
				BASE_INTERFACE IEnumerable<T>
			{
		public:
				virtual int Add(const T item) = 0;

				virtual bool Contains(const T item) = 0;

				virtual void CopyTo(const T * _array, const int arrayIndex, const int arrayLength) = 0;

				virtual int TryRemove(const T item, const bool* result) = 0;
			};

			TEMPLATE
				INTERFACE_CLASS(IReadOnlyList) :
				BASE_INTERFACE IEnumerable<T>
			{
			public:
				virtual T GetAt(const int index) = 0;
			};

            TEMPLATE
				INTERFACE_CLASS(IList) :
                BASE_INTERFACE IReadOnlyList<T>,
                BASE_INTERFACE ICollection<T>
            {
            public:
                virtual int IndexOf(const T item) = 0;
                
				virtual int Insert(const int index, const T item) = 0;
                
				virtual int RemoveAt(const int index) = 0;
            };
		}
	}
}
#endif
