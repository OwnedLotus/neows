if(EXISTS "/home/jonahr/Documents/Code/CCPP/neows_visualization/test-b12d07c_tests.cmake")
  include("/home/jonahr/Documents/Code/CCPP/neows_visualization/test-b12d07c_tests.cmake")
else()
  add_test(test_NOT_BUILT-b12d07c test_NOT_BUILT-b12d07c)
endif()
