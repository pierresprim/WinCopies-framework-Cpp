#pragma once

#ifndef WINCOPIES_TYPES_ABSTRACTOR_H
#define WINCOPIES_TYPES_ABSTRACTOR_H

#include "../../Kernel/Macros/Type/TypeBase.hxx"
#include "../../Kernel/Macros/Method/Implementation.hxx"

#include "../../Core/Typing/Typing.h"
#include "../../Core/Typing/EnableIf.h"

using namespace WinCopies::Typing;

namespace WinCopies
{
	TEMPLATE CLASS AbstractorBase ABSTRACT
	{
	private:
		Shared<T> _obj = nullptr;

		REMOVED_METHOD_DEFINITION(Abstractor);

	protected:
		INLINE_FIELD_RETURN(VIRTUALITY_NONE, Shared<T>, InnerObject, obj)

		INLINE_FIELD_SET(Abstractor, Shared<T>, obj)

	public:
		ABSTRACT_DESTRUCTOR_DEFINITION(AbstractorBase);
	};

	TEMPLATE_EC_IF_TRUE(((ENABLE_IF_BASE_OF(AbstractorBase<TObj>, TAbstractor))), TAbstractor, TObj) CLASS Abstractor ABSTRACT :
		public AbstractorBase<TObj>
	{
	private:
		TAbstractor** _ptr = nullptr;

	protected:
		inline explicit CLASS_INITIALIZATION(Abstractor, (AbstractorBase<TObj>), , (((Shared<TObj>), obj)), ((TAbstractor**), ptr))

	public:
		INLINE_DESTRUCTOR_DEFINITION(VIRTUALITY_OVERRIDE, Abstractor, *_ptr = nullptr)
	};
}

#define _ABSTRACTION_TEMPLATE(name, interfaceName, abstractedSuffix, abstractorSuffix) TEMPLATE CLASS name##abstractorSuffix : public Abstractor<interfaceName>, BASE_INTERFACE interfaceName
#define ABSTRACTION_TEMPLATE(name, abstractedSuffix, abstractorSuffix) _ABSTRACTION_TEMPLATE(name, I##name##abstractedSuffix<T>, abstractedSuffix, abstractorSuffix)

#define COLLECTION_ABSTRACTION_TEMPLATE(name) ABSTRACTION_TEMPLATE(name, List, Collection)
#endif WINCOPIES_TYPES_ABSTRACTOR_H