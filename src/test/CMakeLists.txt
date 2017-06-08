enable_testing()

add_executable(Calc_test Calc_test.cpp ../Calc.cpp) 
add_test(NAME Calc_test COMMAND Calc_test)

