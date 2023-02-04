cmake_minimum_required(VERSION 3.17)

# define project version with CI build
if(DEFINED ENV{PROJECT_VERSION})
    project(
            RType
            VERSION $ENV{PROJECT_VERSION}
            DESCRIPTION "Epitech Project"
    )
else()
    project(
            RType
            VERSION 0.1.0
            DESCRIPTION "Epitech Project"
    )
endif()

# Call CMakes List.txt in the subdirectories
add_subdirectory(rtype)
