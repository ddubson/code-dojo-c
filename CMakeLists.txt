cmake_minimum_required(VERSION 3.6)
project(code_dojo_c)

set(CMAKE_CXX_STANDARD 11)

set(HELLO_WORLD_SRC hello-world/hello.c)
set(FAHRENHEIT_SRC fahrenheit-celsius-table/fc_table.c)
set(LL_TRAVERSAL linked_lists/ll_operations.c)
set(NEEDLE_HAYSTACK needle_haystack.c)

set(WIN32_01_SIMPLE windows/01_simple_win32.c)

set(STEP1 fundamentals/01_structure_of_a_program.c)
set(STEP2 fundamentals/02_data_types.c)
set(STEP3 fundamentals/03_if_statements.c)
set(STEP4 fundamentals/04_case_statements.c)
set(STEP5 fundamentals/05_while_statements.c)
set(STEP6 fundamentals/06_functions.c)
set(STEP7 fundamentals/07_storage_class.c)
set(STEP8 fundamentals/08_preprocessor_dir.c)
set(STEP9 fundamentals/09_common_io.c)
set(STEP10 fundamentals/10_file_io.c)
set(STEP11 fundamentals/11_bitwise_ops.c)
set(STEP12 fundamentals/12_structs.c)
set(STEP13 fundamentals/13_pointers_and_memory.c)
set(STEP14 fundamentals/14_pointers_funcs.c)
set(STEP15 fundamentals/15_ptr_to_ptr.c)
set(STEP16 fundamentals/16_unions.c)
set(STEP17 fundamentals/17_ptr_structs.c)

add_executable(linked_list_traversal ${LL_TRAVERSAL})
add_executable(hello_world ${HELLO_WORLD_SRC})
add_executable(fahrenheit-celsius-table ${FAHRENHEIT_SRC})
add_executable(needle_haystack ${NEEDLE_HAYSTACK})

add_executable(win32_simple ${WIN32_01_SIMPLE})

add_executable(01_structure_of_a_program ${STEP1})
add_executable(02_data_types ${STEP2})
add_executable(03_if_statements ${STEP3})
add_executable(04_case_statements ${STEP4})
add_executable(05_while_statements ${STEP5})
add_executable(06_functions ${STEP6})
add_executable(07_storage_classes ${STEP7})
add_executable(08_preprocessor_dir ${STEP8})
add_executable(09_common_io ${STEP9})
add_executable(10_file_io ${STEP10})
add_executable(11_bitwise_ops ${STEP11})
add_executable(12_structs ${STEP12})
add_executable(13_pointers_and_memory ${STEP13})
add_executable(14_pointer_funcs ${STEP14})
add_executable(14_otr_to_ptr ${STEP15})
add_executable(16_unions ${STEP16})
add_executable(17_ptr_structs ${STEP17})