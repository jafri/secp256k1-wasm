cmake_minimum_required( VERSION 3.5 )

project(eosio_test)

set(EOSIO_WASM_OLD_BEHAVIOR "Off")
find_package(eosio.cdt)

add_contract(test test
   ${CMAKE_CURRENT_SOURCE_DIR}/external/secp256k1/src/secp256k1.c
   ${CMAKE_CURRENT_SOURCE_DIR}/src/test.cpp
)

target_include_directories(test
   PUBLIC
   ${CMAKE_CURRENT_SOURCE_DIR}/external
   ${CMAKE_CURRENT_SOURCE_DIR}/include
   ${CMAKE_CURRENT_SOURCE_DIR}/external/secp256k1
)

set(FLAGS NDEBUG USE_FIELD_5X52 USE_SCALAR_4X64 HAVE_BUILTIN_EXPECT HAVE___INT128 ENABLE_MODULE_RECOVERY USE_FIELD_INV_BUILTIN USE_NUM_NONE USE_SCALAR_INV_BUILTIN)
target_compile_definitions(test PRIVATE -DECMULT_GEN_PREC_BITS=8 -DECMULT_WINDOW_SIZE=15 ${FLAGS})

target_link_options(test PUBLIC -stack-size 32000 -use-freeing-malloc  )

set_target_properties(test
   PROPERTIES
   RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
)