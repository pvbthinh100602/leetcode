set(PROBLEM_ID "" CACHE STRING "LeetCode problem id")

if(PROBLEM_ID)
    add_subdirectory(${PROBLEM_ID})
endif()