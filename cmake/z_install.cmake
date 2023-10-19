
########################################################################################################################
# Install module                                                                                                       #
########################################################################################################################

# local debug
set(CMAKE_INSTALL_PREFIX "./")
# Release Code
# set(CMAKE_INSTALL_PREFIX "/")

message(STATUS "The default installation path is ${CMAKE_INSTALL_PREFIX}")
message(STATUS "Please use \"make install DESTDIR=./PATH\" to set install path")

# test and exec install
install(TARGETS
    ${test_name} ${exec_name}
    DESTINATION ${PROJECT_NAME}/bin
    )
# example file install
install(FILES
        ${CMAKE_SOURCE_DIR}/resource/DFA_model.dfa # source head
        DESTINATION # to
        ${PROJECT_NAME}/DFA_config_file # target dir
        )

if (generate_lib STREQUAL "ON")
    # include install
    install(FILES
        ${CMAKE_SOURCE_DIR}/src/data_tree.h
        ${CMAKE_SOURCE_DIR}/src/error_message.h
        ${CMAKE_SOURCE_DIR}/src/scanning.h
        DESTINATION # to
        ${PROJECT_NAME}/include # target dir
        )
    # lib install
    install(TARGETS
        ${library_static_name} ${library_dynamic_name}
        DESTINATION ${PROJECT_NAME}/lib
        )
    # cmake install
    install(FILES
            ${CMAKE_SOURCE_DIR}/cmake/${project_name}-config.cmake
            DESTINATION ${PROJECT_NAME}/cmake
            )
endif ()


