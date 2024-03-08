#pragma once
#ifndef ISIMPLELINKEDLISTBASE_H
#define ISIMPLELINKEDLISTBASE_H

#include "../Countable.h"
#include "../ICollection.h"

namespace WinCopies
{
	namespace Collections
	{
		INTERFACE_CLASS(ISimpleLinkedListBase)
		{
		public:
			ABSTRACT_METHOD_CONST(bool GetHasItems);
		};

		INTERFACE_CLASS(ISimpleLinkedListBase2) :
			BASE_INTERFACE ISimpleLinkedListBase,
			BASE_INTERFACE IUIntCountable
		{
			// Left empty.
		};

		INTERFACE_CLASS(ISimpleLinkedList) :
			BASE_INTERFACE ISimpleLinkedListBase2
		{
		public:
			ABSTRACT_ARG_METHOD_CONST(bool TryPeek, void** const result);
			ABSTRACT_ARG_METHOD_CONST(int Peek, void** const result);
		};

		namespace Generic
		{
			TEMPLATE
				INTERFACE_CLASS(ISimpleLinkedListBase)
			{
			public:
				ABSTRACT_ARG_METHOD_CONST(bool GenericTryPeek, T* const result);
				ABSTRACT_ARG_METHOD_CONST(int GenericPeek, T* const result);
			};

			TEMPLATE
				INTERFACE_CLASS(ISimpleLinkedList) :
				BASE_INTERFACE ISimpleLinkedListBase2,
				BASE_INTERFACE ISimpleLinkedListBase<T>,
				BASE_INTERFACE WinCopies::Collections::ISimpleLinkedList,
				BASE_INTERFACE IList<T>,
				BASE_INTERFACE WinCopies::Collections::IList,
				BASE_INTERFACE WinCopies::Collections::ICollection
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
