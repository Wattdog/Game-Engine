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
		${CMAKE_SOURCE_DIR}/sdk/glew/lib/Release/Win32
	)
else()
	# Linux, Emscripten, macOS equivalents
endif()

# Avoid the weird SDL2main hack
if (MSVC)
	add_definitions(-DSDL_MAIN_HANDLED)
endif()

add_library(renderer
   src/renderer/renderer.cpp
   src/renderer/ShaderProgram.cpp
   src/renderer/VertexArray.cpp
   src/renderer/VertexBuffer.cpp
   src/renderer/renderer.h
   src/renderer/ShaderProgram.h
   src/renderer/VertexArray.h
   src/renderer/VertexBuffer.h
)

target_link_libraries(renderer glew32 OpenGL32)

add_library(myengine
   src/myengine/Core.cpp
   src/myengine/myengine.cpp
   src/myengine/Entity.cpp
   src/myengine/Component.cpp
   src/myengine/Keyboard.cpp
   src/myengine/Environment.cpp
   src/myengine/Screen.cpp
   src/myengine/TriangleRenderer.cpp
   src/myengine/Transform.cpp
   src/myengine/Core.h
   src/myengine/myengine.h
   src/myengine/Entity.h
   src/myengine/Component.h
   src/myengine/Keyboard.h
   src/myengine/Environment.h
   src/myengine/Screen.h
   src/myengine/TriangleRenderer.h
   src/myengine/Transform.h
)

target_link_libraries(myengine renderer SDL2)

add_executable(game
   src/game/main.cpp
   src/game/test.cpp
)

target_link_libraries(game myengine)