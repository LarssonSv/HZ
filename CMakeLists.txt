cmake_minimum_required (VERSION 3.8)

project (hz)

add_executable (hz "source/hz.cpp" "source/hz.h" "source/core/Log.cpp" "source/core/Log.h" "source/core/Base.h"  "source/core/BaseSystem.h"   "source/core/BaseSystem.cpp" "source/core/Assert.h" "source/core/Profiler.h" )

include_directories("source/libs/spdlog/include/")
include_directories("source/libs/optick/src/")
include_directories("source/")