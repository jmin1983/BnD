#if defined(_WIN32)
#if defined(_DLL)
#include "configuration_win64_dll.h"
#else
#include "configuration_win64.h"
#endif
#else
#include "configuration_linux64.h"
#endif
