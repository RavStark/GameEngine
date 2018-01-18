CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(GameEngine)


FILE(
	GLOB_RECURSE
	ENGINE_LIB
	
	Source/*.cpp
	Include/*.hpp
)

FILE(
	GLOB_RECURSE
	ENGINE_SHADERS
	Shaders/*
)

macro(GroupSources curdir)

   file(GLOB children RELATIVE ${PROJECT_SOURCE_DIR}/${curdir} ${PROJECT_SOURCE_DIR}/${curdir}/*)

   foreach(child ${children})

          if(IS_DIRECTORY ${PROJECT_SOURCE_DIR}/${curdir}/${child})

                  GroupSources(${curdir}/${child})

          else()

                  string(REPLACE "/" "\\" groupname ${curdir})

          # I would like to call the src root folder in a different name, only in visual studio (not mandatory requirement)

                  # string(REPLACE "src" "Common" groupname ${groupname})

            source_group(${groupname} FILES ${PROJECT_SOURCE_DIR}/${curdir}/${child})

          endif()

   endforeach()

endmacro()

GroupSources(Include)
GroupSources(Source)
GroupSources(Shaders)

INCLUDE_DIRECTORIES(
	Include

	${CMAKE_SOURCE_DIR}/dependencies/glew-2.0.0/include
	${CMAKE_SOURCE_DIR}/dependencies/glfw-3.2.1/include
	${CMAKE_SOURCE_DIR}/dependencies/SimpleOpenGLImageLibrary/src
	${CMAKE_SOURCE_DIR}/dependencies/glm
	${CMAKE_SOURCE_DIR}/dependencies/assimp-3.3.1/include
)

LINK_DIRECTORIES(

	${CMAKE_SOURCE_DIR}/dependencies/glew-2.0.0/lib/Release/Win32
	${CMAKE_SOURCE_DIR}/dependencies/glfw-3.2.1/lib-vc2015/${CMAKE_BUILD_TYPE}
	${CMAKE_SOURCE_DIR}/dependencies/SimpleOpenGLImageLibrary/projects/VC9/${CMAKE_BUILD_TYPE}
	${CMAKE_SOURCE_DIR}/dependencies/assimp-3.3.1/lib/${CMAKE_BUILD_TYPE}
)



IF(WIN32)

    SET(CMAKE_CXX_FLAGS "/EHsc /W4 /GR")

    # Use unicode character set

    ADD_DEFINITIONS(-DUNICODE -D_UNICODE)

    # Activate linker flags /SAFESEH:NO, otherwise something goes wrong with libeay32 from SSL

    SET (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SAFESEH:NO")

    # Removing warnings about constant conditions

    ADD_DEFINITIONS(/wd4127)

	ADD_DEFINITIONS(/wd4512)

ELSE(WIN32)

    SET(CMAKE_CXX_FLAGS "-Wall -ansi -O3 -std=c++11")

ENDIF(WIN32)

SET(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib/${CMAKE_BUILD_TYPE})

ADD_LIBRARY (
  GlEngine
  STATIC
  ${ENGINE_SHADERS}
  ${ENGINE_LIB}
)

ADD_EXECUTABLE(

  GlEngineMain

  main.cpp
  Game.hpp
	Game.cpp
)

ADD_DEPENDENCIES(
  GlEngineMain

  GlEngine
)
set_property(SOURCE ${ENGINE_SHADERS} PROPERTY VS_DEPLOYMENT_CONTENT 1)
set_property(SOURCE ${ENGINE_SHADERS} PROPERTY VS_DEPLOYMENT_LOCATION "Shaders")
SET_TARGET_PROPERTIES(GlEngine PROPERTIES DEBUG_POSTFIX "_d")
SET_TARGET_PROPERTIES(GlEngineMain PROPERTIES DEBUG_POSTFIX "_d")
TARGET_LINK_LIBRARIES(
	GlEngineMain
	glfw3.lib
	OpenGL32.lib
	glew32s.lib
	SOIL.lib
	assimp-vc140-mt.lib
    optimized GlEngine
    debug GlEngine
)

