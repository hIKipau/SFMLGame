cmake_minimum_required(VERSION 3.28)
project(SFMLGame)

set(CMAKE_CXX_STANDARD 20)

add_executable(SFMLGame main.cpp)

if(WIN32)

	if(CMAKE_BUILD_TYPE STREQUAL "Release")
		set_target_properties(SFMLGame PROPERTIES
        	LINK_FLAGS "/ENTRY:mainCRTStartup /SUBSYSTEM:WINDOWS")
	endif()

	set(CMAKE_PREFIX_PATH "C:/Program Files (x86)/libraries/SFML-3.0.0")
   	set(SFML_DIR "C:/Program Files (x86)/libraries/SFML-3.0.0")
    	add_custom_command(TARGET SFMLGame POST_BUILD
			COMMAND ${CMAKE_COMMAND} -E copy_directory
			${SFML_DIR}/bin $<TARGET_FILE_DIR:SFMLGame>)
endif()

find_package(SFML 3.0.0 REQUIRED COMPONENTS Graphics System Window)
target_link_libraries(SFMLGame SFML::Graphics SFML::System SFML::Window)
