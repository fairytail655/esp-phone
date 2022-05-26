# CMakeLists.txt
#
# Copyright 2021 Espressif Systems (Shanghai) Co. Ltd.
#
#   Licensed under the Apache License, Version 2.0 (the "License");
#   you may not use this file except in compliance with the License.
#   You may obtain a copy of the License at
#
#              http://www.apache.org/licenses/LICENSE-2.0
#
#   Unless required by applicable law or agreed to in writing, software
#   distributed under the License is distributed on an "AS IS" BASIS,
#   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#   See the License for the specific language governing permissions and
#   limitations under the License.
#

# Search for src files
file(GLOB_RECURSE GUI_SOURCES
	gui/*.cpp
	gui/*.c)
file(GLOB_RECURSE APP_SOURCES
	app/*.cpp
	app/*.c)
file(GLOB_RECURSE COMMON_SOURCES
	common/*.cpp
	common/*.c)
file(GLOB_RECURSE HAL_SOURCES
	hal/*.cpp
	hal/*.c)
file(GLOB_RECURSE MANAGER_SOURCES
	manager/*.cpp
	manager/*.c)

# Resister components
idf_component_register(
	SRCS
		${GUI_SOURCES}
		${APP_SOURCES}
		${COMMON_SOURCES}
		${HAL_SOURCES}
		${MANAGER_SOURCES}
	INCLUDE_DIRS
		"."
	REQUIRES
		lvgl)

# Remove some warnning
set_source_files_properties(./gui/menubar/Menubar.cpp
    PROPERTIES COMPILE_FLAGS
    -Wno-cast-function-type
)
set_source_files_properties(./app/App.cpp
    PROPERTIES COMPILE_FLAGS
    -Wno-pmf-conversions
)
