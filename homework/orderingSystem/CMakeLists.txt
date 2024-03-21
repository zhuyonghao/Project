cmake_minimum_required(VERSION 3.20.4)

project(OrderSystem)

set(PROJECT_DIR ${CMAKE_SOURCE_DIR})

set(PROJECT_INCLUDE_DIR ${PROJECT_DIR}/include)

set(PROJECT_SOURCE_DIR ${PROJECT_DIR}/src)

set(PROJECT_ASSET_DIR ${PROJECT_DIR}/asset)

set(PROJECT_SOURCES
        ${PROJECT_SOURCE_DIR}/main.cpp
    )

set(PROJECT_HEADERS
		${PROJECT_INCLUDE_DIR}/administrator.hpp
		${PROJECT_INCLUDE_DIR}/customer.hpp
        ${PROJECT_INCLUDE_DIR}/menu.hpp
		${PROJECT_INCLUDE_DIR}/order.hpp
        ${PROJECT_INCLUDE_DIR}/userInterface.hpp
	)

include_directories(${PROJECT_INCLUDE_DIR})

file(COPY ${PROJECT_ASSET_DIR}/menu.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

file(COPY ${PROJECT_ASSET_DIR}/order.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS})