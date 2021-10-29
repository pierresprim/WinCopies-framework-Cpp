#pragma once
#ifndef ICOLLECTION_H
#define ICOLLECTION_H

#include "IEnumerable.h"

namespace WinCopies
{
	namespace Collections
	{
		INTERFACE(IReadOnlyCollection)
		{
			virtual bool GetIsReadOnly() = 0;
		};

		INTERFACE(ICollection) :
			BASE_INTERFACE IReadOnlyCollection
		{
		public:
			virtual int Clear() = 0;
		};

		INTERFACE(IList)
		{
		public:
            virtual bool GetIsFixedSize() = 0;

            virtual int RemoveAt(const int index) = 0;
		};

		namespace Generic
		{
			TEMPLATE
				INTERFACE(ICollection) :
				BASE_INTERFACE IEnumerable<T>
			{
				virtual int Add(const T item) = 0;

				virtual bool Contains(const T item) = 0;

				virtual void CopyTo(const T * _array, const int arrayIndex, const int arrayLength) = 0;

				virtual int TryRemove(const T item, const bool* result) = 0;
			};

			TEMPLATE
				INTERFACE(IReadOnlyList) :
				BASE_INTERFACE IEnumerable<T>
			{
			public:
				virtual T GetAt(const int index) = 0;
			};

            TEMPLATE
                INTERFACE(IList) :
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
