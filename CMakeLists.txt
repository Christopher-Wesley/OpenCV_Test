# SPECIFY THE MINIMUM VERSION OF CMAKE REQUIRED
cmake_minimum_required(VERSION 2.8.12)


# SPECIFY YOUR PROJECT NAME
PROJECT(masking)

SET(OpenCV_DIR /Users/chriswesley/opencv/build/CMakeFiles/Export/lib/cmake/opencv4)
SET(depthai_DIR /Users/chriswesley/depthai-core/build)

# Enable C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)




### Uncomment the line below and specify the path to OpenCV directory i.e. the path to the OpenCVConfig.cmake file. Check the examples given below.
###SET PATH TO OPENCV CMAKE CONFIG FILES

#SET(OpenCV_DIR Enter-the-path-of-OpenCV-installation-on-your-system)

################### OpenCV_DIR Examples  #####################
#
### MACOS : /Users/<Username>/installation/OpenCV/lib/cmake/opencv4
### UBUNTU : /usr/local/share/OpenCV/
#
##############################################################




# MAKE SURE OPENCV IS INSTALLED CORRECTLY
find_package(OpenCV REQUIRED)
find_package(depthai CONFIG REQUIRED )
# INCLUDE OPENCV DIRECTORIES
include_directories( ${OpenCV_INCLUDE_DIRS})

# MACRO TO COMPILE CPP FILES
# Do Not Edit
MACRO(add_example name)
    ADD_EXECUTABLE(${name} ${name}.cpp)
    TARGET_LINK_LIBRARIES(${name} PRIVATE depthai::opencv ${OpenCV_LIBS})
ENDMACRO()

# COMPILE CPP FILES USING THIS LINE
######## EDIT THE FILE NAMES ########
add_example(masking)
#add_example(sampleCode2) and so on