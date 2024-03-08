#pragma once
#ifndef ISIMPLELINKEDLISTBASE_H
#define ISIMPLELINKEDLISTBASE_H

#include "defines.h"
#include "Countable.h"
#include "ICollection.h"

namespace WinCopies
{
	namespace Collections
	{
		INTERFACE(ISimpleLinkedListBase)
		{
		public:
			ABSTRACT_METHOD_CONST(bool GetHasItems);
		};

		INTERFACE(ISimpleLinkedListBase2) :
			BASE_INTERFACE ISimpleLinkedListBase,
			BASE_INTERFACE IUIntCountable
		{
			// Left empty.
		};

		INTERFACE(ISimpleLinkedList) :
			BASE_INTERFACE ISimpleLinkedListBase2
		{
		public:
			ABSTRACT_ARG_METHOD_CONST(bool TryPeek, void** const result);

			ABSTRACT_ARG_METHOD_CONST(int Peek, void** const result);
		};

		namespace Generic
		{
			TEMPLATE
				INTERFACE(ISimpleLinkedListBase)
			{
			public:
				ABSTRACT_ARG_METHOD_CONST(bool GenericTryPeek, T* const result);

				ABSTRACT_ARG_METHOD_CONST(int GenericPeek, T* const result);
			};

			TEMPLATE
				INTERFACE(ISimpleLinkedList) :
				BASE_INTERFACE ISimpleLinkedListBase2,
				BASE_INTERFACE ISimpleLinkedListBase<T>,
				BASE_INTERFACE WinCopies::Collections::ISimpleLinkedList,
				BASE_INTERFACE IList<T>,
				BASE_INTERFACE IList,
				BASE_INTERFACE ICollection
			{
			public:
				FINAL_ARG_METHOD_CONST(bool TryPeek, void** const result)
				{
					return GenericTryPeek((T*)*result);
				}

				FINAL_ARG_METHOD_CONST(int Peek, void** const result)
				{
					return GenericPeek((T*)*result);
				}
			};
		}
	}
}

#endif
