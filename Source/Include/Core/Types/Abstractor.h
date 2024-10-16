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

#define ABSTRACTION_TEMPLATE_INTERFACE(prefix, name, suffix) SURROUND(I##prefix, name, suffix<T>)
#define ABSTRACTION_TEMPLATE_CLASS(prefix, name, suffix) CLASS SURROUND(prefix, name, suffix)

#define ___ABSTRACTION_TEMPLATE(templateParams, name, completeName) SINGLE_ARG templateParams CLASS completeName; SINGLE_ARG templateParams using SURROUND(FIRST_ARG name, SECOND_ARG name, Abstractor) = Abstractor<completeName<TAbstracted, T>, TAbstracted>;
#define __ABSTRACTION_TEMPLATE(templateParams, aliasRenderer, baseType, name, completeName, interfaceName, ...) aliasRenderer(templateParams, name, completeName) SINGLE_ARG templateParams CLASS completeName : public baseType<TAbstracted, T>, BASE_INTERFACE interfaceName
#define _ABSTRACTION_TEMPLATE(templateParams, name, completeName, interfaceName, ...) CALL_VA_MACRO(__ABSTRACTION_TEMPLATE, templateParams, EXPAND(IF_VA_ARGS((DISCARD, CONCATENATE(__VA_ARGS__, completeName)), (___ABSTRACTION_TEMPLATE, SURROUND(FIRST_ARG name, SECOND_ARG name, Abstractor)), __VA_ARGS__)), name, completeName, interfaceName, __VA_ARGS__)

#define _ABSTRACTION_TEMPLATE_PARAMS(interfaceName) TEMPLATE_EC_IF_TRUE(((ENABLE_IF_BASE_OF(interfaceName, TAbstracted))), TAbstracted, T)
#define ABSTRACTION_TEMPLATE_PARAMS(prefix, interfaceName, suffix) _ABSTRACTION_TEMPLATE_PARAMS(ABSTRACTION_TEMPLATE_INTERFACE(prefix, interfaceName, suffix))

#define _AABSTRACTION_TEMPLATE(prefix, name, interfaceName, abstractorSuffix, ...) _ABSTRACTION_TEMPLATE((_ABSTRACTION_TEMPLATE_PARAMS(interfaceName)), (prefix, name), SURROUND(prefix, name, abstractorSuffix), interfaceName, __VA_ARGS__)

#define AABSTRACTION_TEMPLATE(prefix, name, abstractedSuffix, abstractorSuffix, ...) _AABSTRACTION_TEMPLATE(prefix, name, ABSTRACTION_TEMPLATE_INTERFACE(prefix, name, abstractedSuffix), abstractorSuffix, __VA_ARGS__)
#define ABSTRACTION_TEMPLATE(name, abstractedSuffix, abstractorSuffix, ...) AABSTRACTION_TEMPLATE(, name, abstractedSuffix, abstractorSuffix, __VA_ARGS__)

#define ABSTRACTION_TEMPLATE_HEADER(prefix, name, abstractedSuffix, abstractorSuffix) ABSTRACTION_TEMPLATE_PARAMS(prefix, name, abstractedSuffix) ABSTRACTION_TEMPLATE_CLASS(prefix, name, abstractorSuffix)

#define COLLECTION_ABSTRACTION_TEMPLATE_PARAMS(prefix, name) ABSTRACTION_TEMPLATE_PARAMS(prefix, name, List)
#define COLLECTION_ABSTRACTION_TEMPLATE_CLASS(prefix, name) ABSTRACTION_TEMPLATE_CLASS(prefix, name, Collection)

#define COLLECTION_ABSTRACTION_TEMPLATE_HEADER(prefix, name) ABSTRACTION_TEMPLATE_HEADER(prefix, name, List, Collection)

#define CCOLLECTION_ABSTRACTION_TEMPLATE(prefix, name, ...) AABSTRACTION_TEMPLATE(prefix, name, List, Collection, __VA_ARGS__)
#define COLLECTION_ABSTRACTION_TEMPLATE(name, ...) CCOLLECTION_ABSTRACTION_TEMPLATE(, name, __VA_ARGS__)
#endif WINCOPIES_TYPES_ABSTRACTOR_H