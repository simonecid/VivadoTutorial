################### PROJECT SETUP ###################

# Creates a project or, if already existing, opens it
open_project "VivadoTutorial"
# if by any chance your file list changes use
# open_project -reset "VivadoTutorial"
# to make sure you delete the existing project and create a new one with the updated file list

# Adding an HLS file
add_files -cflags "-std=c++11" "HLS_Vectors.cpp"

# Adding a TB file
add_files -tb "TB_Vectors.cpp"

# Setting the top-level function
set_top "hls_vectorOperations"

################### SOLUTION SETUP ###################
# creates or, if already existing, opens a new solution
# if by any chance your clock or target device changes use
# open_solution -reset "KU15P"
# to make sure you delete the existing project and create a new one with the updated file list
open_solution "KU115"

# Sets the target device
set_part xcku115-flvd1517-2-i
# Sets the clock
create_clock -period 300MHz
# create clock -period 10 is also valid and will create a clock with a period of 10 ns, i.e. 100 MHz  