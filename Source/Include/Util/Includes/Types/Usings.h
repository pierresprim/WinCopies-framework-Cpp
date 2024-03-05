#pragma once

#ifndef WINCOPIES_UTIL_USINGS_H
#define WINCOPIES_UTIL_USINGS_H

using namespace std;

namespace WinCopies
{
	TEMPLATE using FreeableUniquePtr = unique_ptr<T, void (*)(void*)>;

	template<bool T> using EnableIf = enable_if_t<T, bool>;

#define ENABLE_IF(value) EnableIf<value<T>>

	TEMPLATE using EnableIfSigned = ENABLE_IF(is_signed_v);
	TEMPLATE using EnableIfUnsigned = ENABLE_IF(is_unsigned_v);

	TEMPLATE using EnableIfIntegral = ENABLE_IF(is_integral_v);
	TEMPLATE using EnableIfSignedIntegral = ENABLE_IF(is_integral_v<T>&& is_signed_v);
	TEMPLATE using EnableIfUnsignedIntegral = ENABLE_IF(is_integral_v<T>&& is_unsigned_v);

	TEMPLATE using EnableIfFloat = ENABLE_IF(is_floating_point_v);
	TEMPLATE using EnableIfEnum = ENABLE_IF(is_enum_v);
}

#endif