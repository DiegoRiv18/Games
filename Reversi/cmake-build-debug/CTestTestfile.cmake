# CMake generated Testfile for 
# Source directory: C:/Users/retro/OneDrive/Desktop/CS/cs211/hw05/Reversi
# Build directory: C:/Users/retro/OneDrive/Desktop/CS/cs211/hw05/Reversi/cmake-build-debug
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(Test_model_test "model_test")
set_tests_properties(Test_model_test PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/retro/OneDrive/Desktop/CS/cs211/hw05/Reversi/.cs211/cmake/211commands.cmake;90;add_test;C:/Users/retro/OneDrive/Desktop/CS/cs211/hw05/Reversi/CMakeLists.txt;25;add_test_program;C:/Users/retro/OneDrive/Desktop/CS/cs211/hw05/Reversi/CMakeLists.txt;0;")
add_test(Test_helper_test "helper_test")
set_tests_properties(Test_helper_test PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/retro/OneDrive/Desktop/CS/cs211/hw05/Reversi/.cs211/cmake/211commands.cmake;90;add_test;C:/Users/retro/OneDrive/Desktop/CS/cs211/hw05/Reversi/CMakeLists.txt;32;add_test_program;C:/Users/retro/OneDrive/Desktop/CS/cs211/hw05/Reversi/CMakeLists.txt;0;")
subdirs(".cs211/lib/catch")
subdirs(".cs211/lib/ge211")
