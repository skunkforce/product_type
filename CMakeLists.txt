cmake_minimum_required(VERSION 3.12)
project(osf-product_type VERSION 0.0.0)

set(detail_header_files
)
set(header_files
    ${CMAKE_CURRENT_SOURCE_DIR}/include/osf/product_type.hpp
)

# create the osf_product_type library target
add_library(osf-product_type INTERFACE)
target_sources(osf-product_type INTERFACE "$<BUILD_INTERFACE:${detail_header_files};${header_files}>")
target_compile_features(osf-product_type INTERFACE cxx_std_17)

find_package(osf-tmp REQUIRED)
target_link_libraries(osf-product_type INTERFACE osf::osf-tmp)
target_include_directories(osf-product_type SYSTEM INTERFACE 
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/> 
$<INSTALL_INTERFACE:include/>)

# installation
include(CMakePackageConfigHelpers)
write_basic_package_version_file(osf-product_type-config-version.cmake COMPATIBILITY ExactVersion)
install(TARGETS osf-product_type EXPORT osf-product_type_targets
            INCLUDES DESTINATION include)
install(EXPORT osf-product_type_targets
            DESTINATION lib/osf-product_type/cmake
            FILE osf-product_type-targets.cmake
            NAMESPACE osf::)
install(DIRECTORY include/ DESTINATION include)
install(FILES LICENSE DESTINATION include/osf/product_type/)

install(FILES ${PROJECT_NAME}-config.cmake ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake
            DESTINATION lib/osf-product_type/cmake)

# subdirectories
option(OSF_PRODUCT_TYPE_BUILD_TEST "build tests of osf.tmp" OFF)
if(${OSF_PRODUCT_TYPE_BUILD_TEST} OR (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR))
	add_subdirectory(test)
endif()



