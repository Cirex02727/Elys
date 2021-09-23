#pragma once

#include "Elys/Core/PlatformDetection.h"

#ifdef ELYS_PLATFORM_WINDOWS
	#ifndef NOMINMAX
		// See github.com/skypjack/entt/wiki/Frequently-Asked-Questions#warning-c4003-the-min-the-max-and-the-macro
		#define NOMINMAX
	#endif
#endif

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <cmath>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "Elys/Core/Core.h"

#include "Elys/Core/Log.h"
#include "Elys/Utils/Random.h"

#include "Elys/Profiler/Instrumentor.h"

#ifdef ELYS_PLATFORM_WINDOWS
	#include <Windows.h>
#endif
