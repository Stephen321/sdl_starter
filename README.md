Need to set SDL2_PATH(and SDL2_IMAGE_PATH) for windows and linux if not default location.

1. Change in CMakeLists.txt
2. Pass -DSDL2_PATH="path/here" to command line
3. cmake-gui "add entry"
4. Possible to be enviroment vars?

Put dlls into lib folder 

Cmake folder contains a custom cmake find script to find sdl2 (cmake default finds sdl1)

set build directory project_root/build and "cmake .." followed by make for unix or open vs solution.
