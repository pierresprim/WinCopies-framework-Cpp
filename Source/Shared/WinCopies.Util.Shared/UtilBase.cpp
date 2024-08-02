#include "pch.h"
#include "../../Include/Util/Includes/Macros/Method/Inline.h"
#include "UtilBase.h"

using namespace WinCopies;

#define CREATE_CHECK_FUNCTIONS(name, _operator) INLINE_METHOD_RETURN(0, bool, WinCopies::Check##name, value _operator ErrorCode::Success, ErrorCode value)

CREATE_CHECK_FUNCTIONS(Success, >=)
CREATE_CHECK_FUNCTIONS(Fail, <)

#undef CREATE_CHECK_FUNCTIONS