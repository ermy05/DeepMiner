# CMakeList.txt : CMake project for DeepMiner, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("DeepMiner")

# Add source to this project's executable.
add_executable (DeepMiner "DeepMiner.cpp" 
	"src/Interface/AsciiTexture.cpp"
	"src/Interface/ColorData.cpp"
	"src/Interface/ScreenRenderer.cpp"
	"src/Utils/Randomizers/FixedRandomizer.cpp" 
	"src/Utils/Randomizers/MersenneTwister.cpp" 
	"src/Core/Column.cpp" 
	"src/Core/World.cpp" 
	"src/Interface/UIManager.cpp" 
	"src/Core/LogicManager.cpp" 
	"src/Robots/IRobot.cpp" 
	"src/Robots/SortingRobot.cpp" 
	"src/Robots/PlayerControllers/RandomController.cpp" 
	"src/Robots/DoubleMineRobot.cpp" 
	"src/Robots/MiddleMineRobot.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET DeepMiner PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

target_include_directories(DeepMiner PUBLIC "${PROJECT_SOURCE_DIR}/")
