cmake_minimum_required(VERSION 3.12)
project(osf-product-type VERSION 0.0.1)

set(detail_header_files
)
set(header_files
    ${CMAKE_CURRENT_SOURCE_DIR}/include/osf/product_type.hpp
)

include("cmake/osf-cmake-helpers.cmake")
osf_generate_header_only_cmake(osf-product-type osf 1 0 osf-tmp)