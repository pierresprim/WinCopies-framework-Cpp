#ifndef WINCOPIES_UTIL_BASE_GLOBAL_H
#define WINCOPIES_UTIL_BASE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(WINCOPIES_UTIL_BASE_LIBRARY)
#  define WINCOPIES_UTIL_BASESHARED_EXPORT Q_DECL_EXPORT
#else
#  define WINCOPIES_UTIL_BASESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // WINCOPIES_UTIL_BASE_GLOBAL_H
