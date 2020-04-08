add_executable(osf-product_type_test test.cpp)

target_compile_features(osf-product_type_test PRIVATE cxx_std_17)
        
target_link_libraries(osf-product_type_test osf-product_type)
target_compile_options(osf-product_type_test PUBLIC -ftemplate-depth=2048 -Wall)