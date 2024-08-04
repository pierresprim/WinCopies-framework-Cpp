#pragma once

#ifndef WINCOPIES_TYPING_ENABLE_IF_H
#define WINCOPIES_TYPING_ENABLE_IF_H

#include "Consts.hxx"
#include "Defines/EnableIf.hxx"

namespace WinCopies
{
	namespace Typing
	{
		/**
		 * Type trait class for enabling bitwise operations on enums. By default
		 * bitwise operations on enums are disabled.
		 *
		 * @tparam T The enum type on which the type trait is being queried.
		 */
		TEMPLATE STRUCT IsBitwiseEnumType
		{
			/**
			 * Whether or not bitwise operators should be enabled for the enum type.
			 * To enable make a template specialization of this class for your type and
			 * set value to true.
			 */
			static constexpr bool value = false;
		};

		template<bool T1, class T2 = void> using EnableIf = enable_if_t<T1, T2>;
		_TEMPLATE(bool) using EnableBoolIf = EnableIf<T, bool>;

		MAKE_ENABLE_IF(Signed)
		MAKE_ENABLE_IF(Unsigned)

		MAKE_ENABLE_IF(Integral)
		MAKE_ENABLE_IF(SignedIntegral)
		MAKE_ENABLE_IF(UnsignedIntegral)

		MAKE_ENABLE_IF(Float)
		MAKE_ENABLE_IF(Enum)
		MAKE_ENABLE_IF(BitwiseEnum)

		MAKE_ENABLE_IF_TYPES(BaseOf, (TBase, TDerived))
	}
}

#endif WINCOPIES_TYPING_ENABLE_IF_H