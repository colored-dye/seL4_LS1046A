cmake_minimum_required(VERSION 3.7.2)

include(settings.cmake)

find_package(sel4-tutorials REQUIRED)

project(comm C ASM)

# Export generic timer to user
set(KernelArmExportPCNTUser True CACHE BOOL "" FORCE)
set(KernelArmExportPTMRUser True CACHE BOOL "" FORCE)

find_package(camkes-tool REQUIRED)
camkes_tool_setup_camkes_build_environment()

find_file(GLOBAL_COMPONENTS_PATH global-components.cmake PATHS ${project_dir}/projects/global-components/ CMAKE_FIND_ROOT_PATH_BOTH)
mark_as_advanced(FORCE GLOBAL_COMPONENTS_PATH)
if("${GLOBAL_COMPONENTS_PATH}" STREQUAL "GLOBAL_COMPONENTS_PATH-NOTFOUND")
    message(FATAL_ERROR "Failed to find global-components.cmake. Consider cmake -DGLOBAL_COMPONENTS_PATH=/path/to/global-components.cmake")
endif()
include(${GLOBAL_COMPONENTS_PATH})

DeclareCAmkESComponent(Encrypt INCLUDES include SOURCES components/Encrypt/src/Encrypt.c)
DeclareCAmkESComponent(dispatch_periodic INCLUDES include SOURCES components/dispatch_periodic/src/dispatch_periodic.c)

DeclareCAmkESRootserver(comm.camkes)

GenerateCAmkESRootserver()
