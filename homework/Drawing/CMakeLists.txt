cmake_minimum_required(VERSION 3.20.4)

project(Program)

set(PROJECT_DIR ${CMAKE_SOURCE_DIR})

set(PROJECT_INCLUDE_DIR ${PROJECT_DIR}/include)

set(PROJECT_SOURCE_DIR ${PROJECT_DIR}/src)

set(PROJECT_SOURCES
        ${PROJECT_SOURCE_DIR}/main.cpp
    )

set(PROJECT_HEADERS
        ${PROJECT_INCLUDE_DIR}/Color.h
        ${PROJECT_INCLUDE_DIR}/Shape.h
        ${PROJECT_INCLUDE_DIR}/Point.h
        ${PROJECT_INCLUDE_DIR}/Line.h
        ${PROJECT_INCLUDE_DIR}/Ellipse.h
        ${PROJECT_INCLUDE_DIR}/Triangle.h
		${PROJECT_INCLUDE_DIR}/Rectangle.h
        ${PROJECT_INCLUDE_DIR}/Text.h
        ${PROJECT_INCLUDE_DIR}/Canvas.h
        ${PROJECT_INCLUDE_DIR}/FillPattern.h
        ${PROJECT_INCLUDE_DIR}/LineStyle.h
	)

include_directories(${PROJECT_INCLUDE_DIR})

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS})