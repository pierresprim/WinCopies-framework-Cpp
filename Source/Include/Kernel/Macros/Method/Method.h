#pragma once

#ifndef WINCOPIES_MACROS_METHOD_H
#define WINCOPIES_MACROS_METHOD_H

#include "Templates.h"
#include "Abstract.hxx"
#include "Inline.hxx"

#include "MethodBase.hxx"

#define ABSTRACTION_METHOD_RETURN(isConst, returnType, name, suffix, abstractorPtr, ...) \
	protected: INLINE_ABSTRACTION_RETURN(isConst, returnType, name, suffix, abstractorPtr, __VA_ARGS__) \
	public: INLINE_METHOD_RETURN(isConst, VIRTUALITY_OVERRIDE, returnType, FIRST_ARG name, SURROUND(FIRST_ARG name, suffix, SECOND_ARG name)(GET_ARG_PAIRS_VALUE(__VA_ARGS__)), TRANSCRIBE_ARG_PAIRS(__VA_ARGS__))
#define COLLECTION_ABSTRACTION_METHOD(isConst, returnType, name, abstractorPtr, ...) ABSTRACTION_METHOD_RETURN(isConst, returnType, name, Item, abstractorPtr, __VA_ARGS__)

#define ABSTRACTION_METHODS_RETURN(isConst, returnType, suffix, abstractorPtr, ...) PPARSE_ITEMS(ARGS_TRANSCRIPTION, (isConst, returnType), ABSTRACTION_METHOD_RETURN, (suffix, abstractorPtr), __VA_ARGS__)
#define ABSTRACTION_COLLECTION_METHODS(isConst, returnType, abstractorPtr, ...) ABSTRACTION_METHODS_RETURN(isConst, returnType, Item, abstractorPtr, __VA_ARGS__)

#endif WINCOPIES_MACROS_METHOD_H