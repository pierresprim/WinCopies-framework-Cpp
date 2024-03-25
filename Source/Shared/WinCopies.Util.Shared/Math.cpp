#include "pch.h"
#include "../../Include/Util/Math.h"

using namespace WinCopies;

bool Math::IsAdditionResultInRange(const auto x, const auto y, const auto maxValue)
{
	return y <= maxValue - x;
}
bool Math::IsAdditionResultInRange(const auto value, const auto maxValue)
{
	return IsAdditionResultInRange(value, value, maxValue);
}

bool Math::Between(const auto x, const auto value, const auto y, const ByteSelector b)
{
	return (HAS_FLAG(b, ByteSelector::First) ? (value >= x) : (value > x)) && (HAS_FLAG(b, ByteSelector::Second) ? (value <= y) : (value < y));
}
bool Math::Outside(const auto x, const auto value, const auto y, const ByteSelector b)
{
	return (HAS_FLAG(b, ByteSelector::First) ? (value <= x) : (value < x)) && (HAS_FLAG(b, ByteSelector::Second) ? (value >= y) : (value > y));
}

bool Math::IsEven(auto value)
{
	return value % 2 == 0;
}
bool Math::IsOdd(auto value)
{
	return !IsEven(value);
}