cmake_minimum_required(VERSION 3.0)
project(MYENGINE)

include_directories(
	src # For myengine.h
	sdk # For glm.hpp
)

if(MSVC)
	include_directories(
		sdk/SDL2/include # For SDL.h
		sdk/glew/include # For glew.h
	)

	link_directories(
		${CMAKE_SOURCE_DIR}/sdk/SDL2/lib/x86
	)
else()
	# Linux, Emscripten, macOS equivalents
endif()

# Avoid the weird SDL2main hack
if (MSVC)
	add_definitions(-DSDL_MAIN_HANDLED)
endif()

add_library(myengine
   src/myengine/Core.cpp
   src/myengine/myengine.cpp
   src/myengine/Entity.cpp
   src/myengine/Component.cpp
   src/myengine/Keyboard.cpp
   src/myengine/Environment.cpp
   src/myengine/Core.h
   src/myengine/myengine.h
   src/myengine/Entity.h
   src/myengine/Component.h
   src/myengine/Keyboard.h
   src/myengine/Environment.h
)

add_executable(game
   src/game/main.cpp
   src/game/test.cpp
)

target_link_libraries(game myengine SDL2)