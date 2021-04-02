cmake_minimum_required(VERSION 3.17)
project(CS372Spring2021ExampleCode)

Include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.x)
FetchContent_MakeAvailable(Catch2)

set(CMAKE_CXX_STANDARD 20)

set(Warnings,
        $<$<OR:
            $<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
                -Wall -Wextra -Wpedantic -Weverything>
                -Wno-c++98-compat -Wno-padded -Wno-weak-vtables -Wno-missing-prototypes
            $<$<CXX_COMPILER_ID:MSVC>:
                /W4>)

add_executable(CS372Spring2021ExampleCode main.cpp modernCPPexamples.cpp
        Expression.cpp Expression.hpp
        StoreByReference.hpp StoreByPointer.hpp
        Observer.cpp Observer.hpp Subject.cpp Subject.hpp
        Armor.cpp Armor.hpp
        )
target_compile_options(CS372Spring2021ExampleCode PRIVATE ${Warnings})

add_executable(tests catchMain.cpp tests.cpp Expression.cpp Expression.hpp
        )
target_compile_options(tests PRIVATE ${Warnings})
target_link_libraries(tests PRIVATE Catch2::Catch2)
