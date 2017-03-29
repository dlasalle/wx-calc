include_directories(.)
file(GLOB sources *.cpp)

add_executable(wxcalc ${sources}) 

install(TARGETS wxcalc RUNTIME DESTINATION bin)

