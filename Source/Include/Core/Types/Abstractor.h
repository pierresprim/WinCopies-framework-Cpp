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

#define _ABSTRACTION_TEMPLATE_CLASS(prefix, name, suffix) prefix##name##suffix

#define ABSTRACTION_TEMPLATE_INTERFACE(prefix, name, suffix) I##prefix##name##suffix<T>
#define ABSTRACTION_TEMPLATE_CLASS(prefix, name, suffix) class _ABSTRACTION_TEMPLATE_CLASS(prefix, name, suffix)

#define __GET_ABSTRACTION_TEMPLATE_ARG(...) <ALL_BUT_FIRST_ARG(__VA_ARGS__) T>, FIRST_ARG(__VA_ARGS__)
#define _GET_ABSTRACTION_TEMPLATE_ARG(templateParams, name, interfaceName) name __GET_ABSTRACTION_TEMPLATE_ARG(IF_B(COMPL(FIRST_ARG templateParams), interfaceName, TAbstracted, TAbstracted, ))

#define __ABSTRACTION_TEMPLATE(templateParams, baseType, templateArgs, name, interfaceName, ...) SINGLE_ARG templateParams using SURROUND(FIRST_ARG FIRST_ARG name, SECOND_ARG FIRST_ARG name, Abstractor) = Abstractor<SECOND_ARG name<TAbstracted, T>, interfaceName>; SINGLE_ARG templateParams CLASS SECOND_ARG name : public baseType<SINGLE_ARG templateArgs>, BASE_INTERFACE interfaceName
#define _ABSTRACTION_TEMPLATE(templateParams, name, interfaceName, ...) CALL_VA_MACRO(__ABSTRACTION_TEMPLATE, (ALL_BUT_FIRST_ARG templateParams), EXPAND(IF_VA_ARGS((CONCATENATE(__VA_ARGS__, SECOND_ARG name), (interfaceName, T)), (Abstractor, (_GET_ABSTRACTION_TEMPLATE_ARG(templateParams, SECOND_ARG name, interfaceName))), __VA_ARGS__)), name, interfaceName, __VA_ARGS__)

#define ABSTRACTION_TEMPLATE_PARAM TEMPLATE
#define __ABSTRACTION_TEMPLATE_PARAMS(interfaceName) TEMPLATE_EC_IF_TRUE(((ENABLE_IF_BASE_OF(interfaceName, TAbstracted))), TAbstracted, T)

#define _ABSTRACTION_TEMPLATE_PARAM(interfaceName) 0, ABSTRACTION_TEMPLATE_PARAM
#define _ABSTRACTION_TEMPLATE_PARAMS(interfaceName) 1, __ABSTRACTION_TEMPLATE_PARAMS(interfaceName)

#define ABSTRACTION_TEMPLATE_PARAMS(prefix, interfaceName, suffix) __ABSTRACTION_TEMPLATE_PARAMS(ABSTRACTION_TEMPLATE_INTERFACE(prefix, interfaceName, suffix))

#define _AABSTRACTION_TEMPLATE(prefix, name, interfaceName, abstractorSuffix, ...) _ABSTRACTION_TEMPLATE((CALL_VA_MACRO(CONCATENATE, _ABSTRACTION_TEMPLATE_PARAM, IF_VA_ARGS(S, , prefix))(interfaceName)), ((prefix, name), _ABSTRACTION_TEMPLATE_CLASS(prefix, name, abstractorSuffix)), interfaceName, __VA_ARGS__)

#define AABSTRACTION_TEMPLATE(prefix, name, abstractedSuffix, abstractorSuffix, ...) _AABSTRACTION_TEMPLATE(prefix, name, ABSTRACTION_TEMPLATE_INTERFACE(prefix, name, abstractedSuffix), abstractorSuffix, __VA_ARGS__)
#define ABSTRACTION_TEMPLATE(name, abstractedSuffix, abstractorSuffix, ...) AABSTRACTION_TEMPLATE(, name, abstractedSuffix, abstractorSuffix, __VA_ARGS__)

#define ABSTRACTION_TEMPLATE_HEADER(prefix, name, abstractedSuffix, abstractorSuffix) ABSTRACTION_TEMPLATE_PARAMS(prefix, name, abstractedSuffix) ABSTRACTION_TEMPLATE_CLASS(prefix, name, abstractorSuffix)

#define COLLECTION_ABSTRACTION_TEMPLATE_PARAMS(prefix, name) ABSTRACTION_TEMPLATE_PARAMS(prefix, name, List)
#define COLLECTION_ABSTRACTION_TEMPLATE_CLASS(prefix, name) ABSTRACTION_TEMPLATE_CLASS(prefix, name, Collection)

#define COLLECTION_ABSTRACTION_TEMPLATE_HEADER(prefix, name) ABSTRACTION_TEMPLATE_HEADER(prefix, name, List, Collection)

#define CCOLLECTION_ABSTRACTION_TEMPLATE(prefix, name, ...) AABSTRACTION_TEMPLATE(prefix, name, List, Collection, __VA_ARGS__)
#define COLLECTION_ABSTRACTION_TEMPLATE(name, ...) CCOLLECTION_ABSTRACTION_TEMPLATE(, name, __VA_ARGS__)
#endif WINCOPIES_TYPES_ABSTRACTOR_H