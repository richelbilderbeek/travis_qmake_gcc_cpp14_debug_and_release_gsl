# Project files
SOURCES += main.cpp

# Compile at high warning levels, a warning is an error
QMAKE_CXXFLAGS += -Wall -Wextra -Weffc++ -Werror

# C++14
CONFIG += c++14
QMAKE_CXXFLAGS += -std=c++14

# Debug and release mode
CONFIG += console debug_and_release
CONFIG(release, debug|release) {

  # asserts are removed
  DEFINES += NDEBUG

  # Expects and Ensures are removed
  DEFINES += GSL_UNENFORCED_ON_CONTRACT_VIOLATION
}

# GSL
include(gsl.pri)

# Detect my computer
message(Host name: $$QMAKE_HOST.name)
contains(QMAKE_HOST.name,fwn-biol-132-102) {
  message("Host is university computer in my office")
  QMAKE_CXX = g++-5
  QMAKE_LINK = g++-5
  QMAKE_CC = gcc-5
}
