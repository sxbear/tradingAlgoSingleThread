# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake.exe

# The command to remove a file.
RM = /usr/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/out_cygwin

# Include any dependencies generated for this target.
include CMakeFiles/TASTSXB.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TASTSXB.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TASTSXB.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TASTSXB.dir/flags.make

CMakeFiles/TASTSXB.dir/src/config.cpp.o: CMakeFiles/TASTSXB.dir/flags.make
CMakeFiles/TASTSXB.dir/src/config.cpp.o: ../src/config.cpp
CMakeFiles/TASTSXB.dir/src/config.cpp.o: CMakeFiles/TASTSXB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/out_cygwin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TASTSXB.dir/src/config.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TASTSXB.dir/src/config.cpp.o -MF CMakeFiles/TASTSXB.dir/src/config.cpp.o.d -o CMakeFiles/TASTSXB.dir/src/config.cpp.o -c /cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/src/config.cpp

CMakeFiles/TASTSXB.dir/src/config.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TASTSXB.dir/src/config.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/src/config.cpp > CMakeFiles/TASTSXB.dir/src/config.cpp.i

CMakeFiles/TASTSXB.dir/src/config.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TASTSXB.dir/src/config.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/src/config.cpp -o CMakeFiles/TASTSXB.dir/src/config.cpp.s

CMakeFiles/TASTSXB.dir/src/dataParser.cpp.o: CMakeFiles/TASTSXB.dir/flags.make
CMakeFiles/TASTSXB.dir/src/dataParser.cpp.o: ../src/dataParser.cpp
CMakeFiles/TASTSXB.dir/src/dataParser.cpp.o: CMakeFiles/TASTSXB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/out_cygwin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TASTSXB.dir/src/dataParser.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TASTSXB.dir/src/dataParser.cpp.o -MF CMakeFiles/TASTSXB.dir/src/dataParser.cpp.o.d -o CMakeFiles/TASTSXB.dir/src/dataParser.cpp.o -c /cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/src/dataParser.cpp

CMakeFiles/TASTSXB.dir/src/dataParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TASTSXB.dir/src/dataParser.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/src/dataParser.cpp > CMakeFiles/TASTSXB.dir/src/dataParser.cpp.i

CMakeFiles/TASTSXB.dir/src/dataParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TASTSXB.dir/src/dataParser.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/src/dataParser.cpp -o CMakeFiles/TASTSXB.dir/src/dataParser.cpp.s

CMakeFiles/TASTSXB.dir/src/databaseManager.cpp.o: CMakeFiles/TASTSXB.dir/flags.make
CMakeFiles/TASTSXB.dir/src/databaseManager.cpp.o: ../src/databaseManager.cpp
CMakeFiles/TASTSXB.dir/src/databaseManager.cpp.o: CMakeFiles/TASTSXB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/out_cygwin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/TASTSXB.dir/src/databaseManager.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TASTSXB.dir/src/databaseManager.cpp.o -MF CMakeFiles/TASTSXB.dir/src/databaseManager.cpp.o.d -o CMakeFiles/TASTSXB.dir/src/databaseManager.cpp.o -c /cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/src/databaseManager.cpp

CMakeFiles/TASTSXB.dir/src/databaseManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TASTSXB.dir/src/databaseManager.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/src/databaseManager.cpp > CMakeFiles/TASTSXB.dir/src/databaseManager.cpp.i

CMakeFiles/TASTSXB.dir/src/databaseManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TASTSXB.dir/src/databaseManager.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/src/databaseManager.cpp -o CMakeFiles/TASTSXB.dir/src/databaseManager.cpp.s

CMakeFiles/TASTSXB.dir/src/globalQuote.cpp.o: CMakeFiles/TASTSXB.dir/flags.make
CMakeFiles/TASTSXB.dir/src/globalQuote.cpp.o: ../src/globalQuote.cpp
CMakeFiles/TASTSXB.dir/src/globalQuote.cpp.o: CMakeFiles/TASTSXB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/out_cygwin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/TASTSXB.dir/src/globalQuote.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TASTSXB.dir/src/globalQuote.cpp.o -MF CMakeFiles/TASTSXB.dir/src/globalQuote.cpp.o.d -o CMakeFiles/TASTSXB.dir/src/globalQuote.cpp.o -c /cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/src/globalQuote.cpp

CMakeFiles/TASTSXB.dir/src/globalQuote.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TASTSXB.dir/src/globalQuote.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/src/globalQuote.cpp > CMakeFiles/TASTSXB.dir/src/globalQuote.cpp.i

CMakeFiles/TASTSXB.dir/src/globalQuote.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TASTSXB.dir/src/globalQuote.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/src/globalQuote.cpp -o CMakeFiles/TASTSXB.dir/src/globalQuote.cpp.s

CMakeFiles/TASTSXB.dir/src/indicators.cpp.o: CMakeFiles/TASTSXB.dir/flags.make
CMakeFiles/TASTSXB.dir/src/indicators.cpp.o: ../src/indicators.cpp
CMakeFiles/TASTSXB.dir/src/indicators.cpp.o: CMakeFiles/TASTSXB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/out_cygwin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/TASTSXB.dir/src/indicators.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TASTSXB.dir/src/indicators.cpp.o -MF CMakeFiles/TASTSXB.dir/src/indicators.cpp.o.d -o CMakeFiles/TASTSXB.dir/src/indicators.cpp.o -c /cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/src/indicators.cpp

CMakeFiles/TASTSXB.dir/src/indicators.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TASTSXB.dir/src/indicators.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/src/indicators.cpp > CMakeFiles/TASTSXB.dir/src/indicators.cpp.i

CMakeFiles/TASTSXB.dir/src/indicators.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TASTSXB.dir/src/indicators.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/src/indicators.cpp -o CMakeFiles/TASTSXB.dir/src/indicators.cpp.s

CMakeFiles/TASTSXB.dir/src/macd.cpp.o: CMakeFiles/TASTSXB.dir/flags.make
CMakeFiles/TASTSXB.dir/src/macd.cpp.o: ../src/macd.cpp
CMakeFiles/TASTSXB.dir/src/macd.cpp.o: CMakeFiles/TASTSXB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/out_cygwin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/TASTSXB.dir/src/macd.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TASTSXB.dir/src/macd.cpp.o -MF CMakeFiles/TASTSXB.dir/src/macd.cpp.o.d -o CMakeFiles/TASTSXB.dir/src/macd.cpp.o -c /cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/src/macd.cpp

CMakeFiles/TASTSXB.dir/src/macd.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TASTSXB.dir/src/macd.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/src/macd.cpp > CMakeFiles/TASTSXB.dir/src/macd.cpp.i

CMakeFiles/TASTSXB.dir/src/macd.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TASTSXB.dir/src/macd.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/src/macd.cpp -o CMakeFiles/TASTSXB.dir/src/macd.cpp.s

CMakeFiles/TASTSXB.dir/src/main.cpp.o: CMakeFiles/TASTSXB.dir/flags.make
CMakeFiles/TASTSXB.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/TASTSXB.dir/src/main.cpp.o: CMakeFiles/TASTSXB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/out_cygwin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/TASTSXB.dir/src/main.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TASTSXB.dir/src/main.cpp.o -MF CMakeFiles/TASTSXB.dir/src/main.cpp.o.d -o CMakeFiles/TASTSXB.dir/src/main.cpp.o -c /cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/src/main.cpp

CMakeFiles/TASTSXB.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TASTSXB.dir/src/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/src/main.cpp > CMakeFiles/TASTSXB.dir/src/main.cpp.i

CMakeFiles/TASTSXB.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TASTSXB.dir/src/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/src/main.cpp -o CMakeFiles/TASTSXB.dir/src/main.cpp.s

CMakeFiles/TASTSXB.dir/src/marketDataAPI.cpp.o: CMakeFiles/TASTSXB.dir/flags.make
CMakeFiles/TASTSXB.dir/src/marketDataAPI.cpp.o: ../src/marketDataAPI.cpp
CMakeFiles/TASTSXB.dir/src/marketDataAPI.cpp.o: CMakeFiles/TASTSXB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/out_cygwin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/TASTSXB.dir/src/marketDataAPI.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TASTSXB.dir/src/marketDataAPI.cpp.o -MF CMakeFiles/TASTSXB.dir/src/marketDataAPI.cpp.o.d -o CMakeFiles/TASTSXB.dir/src/marketDataAPI.cpp.o -c /cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/src/marketDataAPI.cpp

CMakeFiles/TASTSXB.dir/src/marketDataAPI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TASTSXB.dir/src/marketDataAPI.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/src/marketDataAPI.cpp > CMakeFiles/TASTSXB.dir/src/marketDataAPI.cpp.i

CMakeFiles/TASTSXB.dir/src/marketDataAPI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TASTSXB.dir/src/marketDataAPI.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/src/marketDataAPI.cpp -o CMakeFiles/TASTSXB.dir/src/marketDataAPI.cpp.s

CMakeFiles/TASTSXB.dir/src/strategy.cpp.o: CMakeFiles/TASTSXB.dir/flags.make
CMakeFiles/TASTSXB.dir/src/strategy.cpp.o: ../src/strategy.cpp
CMakeFiles/TASTSXB.dir/src/strategy.cpp.o: CMakeFiles/TASTSXB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/out_cygwin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/TASTSXB.dir/src/strategy.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TASTSXB.dir/src/strategy.cpp.o -MF CMakeFiles/TASTSXB.dir/src/strategy.cpp.o.d -o CMakeFiles/TASTSXB.dir/src/strategy.cpp.o -c /cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/src/strategy.cpp

CMakeFiles/TASTSXB.dir/src/strategy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TASTSXB.dir/src/strategy.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/src/strategy.cpp > CMakeFiles/TASTSXB.dir/src/strategy.cpp.i

CMakeFiles/TASTSXB.dir/src/strategy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TASTSXB.dir/src/strategy.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/src/strategy.cpp -o CMakeFiles/TASTSXB.dir/src/strategy.cpp.s

CMakeFiles/TASTSXB.dir/src/tradingAPI.cpp.o: CMakeFiles/TASTSXB.dir/flags.make
CMakeFiles/TASTSXB.dir/src/tradingAPI.cpp.o: ../src/tradingAPI.cpp
CMakeFiles/TASTSXB.dir/src/tradingAPI.cpp.o: CMakeFiles/TASTSXB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/out_cygwin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/TASTSXB.dir/src/tradingAPI.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TASTSXB.dir/src/tradingAPI.cpp.o -MF CMakeFiles/TASTSXB.dir/src/tradingAPI.cpp.o.d -o CMakeFiles/TASTSXB.dir/src/tradingAPI.cpp.o -c /cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/src/tradingAPI.cpp

CMakeFiles/TASTSXB.dir/src/tradingAPI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TASTSXB.dir/src/tradingAPI.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/src/tradingAPI.cpp > CMakeFiles/TASTSXB.dir/src/tradingAPI.cpp.i

CMakeFiles/TASTSXB.dir/src/tradingAPI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TASTSXB.dir/src/tradingAPI.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/src/tradingAPI.cpp -o CMakeFiles/TASTSXB.dir/src/tradingAPI.cpp.s

CMakeFiles/TASTSXB.dir/src/utility.cpp.o: CMakeFiles/TASTSXB.dir/flags.make
CMakeFiles/TASTSXB.dir/src/utility.cpp.o: ../src/utility.cpp
CMakeFiles/TASTSXB.dir/src/utility.cpp.o: CMakeFiles/TASTSXB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/out_cygwin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/TASTSXB.dir/src/utility.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TASTSXB.dir/src/utility.cpp.o -MF CMakeFiles/TASTSXB.dir/src/utility.cpp.o.d -o CMakeFiles/TASTSXB.dir/src/utility.cpp.o -c /cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/src/utility.cpp

CMakeFiles/TASTSXB.dir/src/utility.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TASTSXB.dir/src/utility.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/src/utility.cpp > CMakeFiles/TASTSXB.dir/src/utility.cpp.i

CMakeFiles/TASTSXB.dir/src/utility.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TASTSXB.dir/src/utility.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/src/utility.cpp -o CMakeFiles/TASTSXB.dir/src/utility.cpp.s

# Object files for target TASTSXB
TASTSXB_OBJECTS = \
"CMakeFiles/TASTSXB.dir/src/config.cpp.o" \
"CMakeFiles/TASTSXB.dir/src/dataParser.cpp.o" \
"CMakeFiles/TASTSXB.dir/src/databaseManager.cpp.o" \
"CMakeFiles/TASTSXB.dir/src/globalQuote.cpp.o" \
"CMakeFiles/TASTSXB.dir/src/indicators.cpp.o" \
"CMakeFiles/TASTSXB.dir/src/macd.cpp.o" \
"CMakeFiles/TASTSXB.dir/src/main.cpp.o" \
"CMakeFiles/TASTSXB.dir/src/marketDataAPI.cpp.o" \
"CMakeFiles/TASTSXB.dir/src/strategy.cpp.o" \
"CMakeFiles/TASTSXB.dir/src/tradingAPI.cpp.o" \
"CMakeFiles/TASTSXB.dir/src/utility.cpp.o"

# External object files for target TASTSXB
TASTSXB_EXTERNAL_OBJECTS =

TASTSXB.exe: CMakeFiles/TASTSXB.dir/src/config.cpp.o
TASTSXB.exe: CMakeFiles/TASTSXB.dir/src/dataParser.cpp.o
TASTSXB.exe: CMakeFiles/TASTSXB.dir/src/databaseManager.cpp.o
TASTSXB.exe: CMakeFiles/TASTSXB.dir/src/globalQuote.cpp.o
TASTSXB.exe: CMakeFiles/TASTSXB.dir/src/indicators.cpp.o
TASTSXB.exe: CMakeFiles/TASTSXB.dir/src/macd.cpp.o
TASTSXB.exe: CMakeFiles/TASTSXB.dir/src/main.cpp.o
TASTSXB.exe: CMakeFiles/TASTSXB.dir/src/marketDataAPI.cpp.o
TASTSXB.exe: CMakeFiles/TASTSXB.dir/src/strategy.cpp.o
TASTSXB.exe: CMakeFiles/TASTSXB.dir/src/tradingAPI.cpp.o
TASTSXB.exe: CMakeFiles/TASTSXB.dir/src/utility.cpp.o
TASTSXB.exe: CMakeFiles/TASTSXB.dir/build.make
TASTSXB.exe: /usr/lib/libcurl.dll.a
TASTSXB.exe: CMakeFiles/TASTSXB.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/out_cygwin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable TASTSXB.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TASTSXB.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TASTSXB.dir/build: TASTSXB.exe
.PHONY : CMakeFiles/TASTSXB.dir/build

CMakeFiles/TASTSXB.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TASTSXB.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TASTSXB.dir/clean

CMakeFiles/TASTSXB.dir/depend:
	cd /cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/out_cygwin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread /cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread /cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/out_cygwin /cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/out_cygwin /cygdrive/C/Users/solom/Documents/Github/TradingAlgoSingleThread/out_cygwin/CMakeFiles/TASTSXB.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TASTSXB.dir/depend
