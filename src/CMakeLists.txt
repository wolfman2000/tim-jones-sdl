list(APPEND TJ_INCLUDE_DIRS
  "${SDL2_INCLUDE_DIR}"
)

list(APPEND TJ_SRC
  "cApp.cpp"
  "cAppOnInit.cpp"
  "cAppOnEvent.cpp"
  "cAppOnLoop.cpp"
  "cAppOnRender.cpp"
  "cAppOnCleanup.cpp"
  "cSurface.cpp"
)

list(APPEND TJ_HPP
  "cApp.hpp"
  "cSurface.hpp"
  "resource_path.hpp"
)

add_executable(TimJones ${TJ_SRC} ${TJ_HPP})
source_group("" FILES ${TJ_SRC} ${TJ_HPP})

set_target_properties(TimJones PROPERTIES
  CXX_STANDARD 11
  CXX_STANDARD_REQUIRED ON
  RUNTIME_OUTPUT_DIRECTORY "${TJ_BIN_DIR}"
)

target_include_directories(TimJones PUBLIC ${TJ_INCLUDE_DIRS})

if (MSVC)
  set_target_properties(TimJones PROPERTIES LINK_FLAGS "/LIBPATH:\${SDL2_LIB_DIR}\"")
  list(APPEND TJ_LINK_LIBS
    "SDL2.lib"
    "SDL2main.lib"
  )
  add_custom_command(TARGET TimJones
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy "${SDL2_LIB_DIR}/SDL2.dll" ${TJ_BIN_DIR}
  )
else()
  list(APPEND TJ_LINK_LIBS
    ${SDL2_LIBRARY}
  )
endif()

target_link_libraries(TimJones ${TJ_LINK_LIBS})

