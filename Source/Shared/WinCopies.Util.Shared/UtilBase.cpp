#include "pch.h"

#include "../../Include/Kernel/Macros/Method/Inline.hxx"
#include "../../Include/Util/UtilBase.h"

using namespace WinCopies;

#define CREATE_CHECK_FUNCTIONS(name, _operator) INLINE_METHOD_RETURN(0, VIRTUALITY_NONE, bool, WinCopies::Check##name, value _operator ErrorCode::Success, ErrorCode value)

CREATE_CHECK_FUNCTIONS(Success, >=)
CREATE_CHECK_FUNCTIONS(Fail, <)

#undef CREATE_CHECK_FUNCTIONS