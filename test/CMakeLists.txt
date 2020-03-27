cmake_minimum_required( VERSION 3.5 )

project(eosio_test)

set(EOSIO_WASM_OLD_BEHAVIOR "Off")
find_package(eosio.cdt)

add_contract(test test
   ${CMAKE_CURRENT_SOURCE_DIR}/src/test.cpp
)

target_include_directories(test
   PUBLIC
   ${CMAKE_CURRENT_SOURCE_DIR}/external
   ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_options(test PUBLIC -stack-size 32000 -use-freeing-malloc  )

set_target_properties(test
   PROPERTIES
   RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
)