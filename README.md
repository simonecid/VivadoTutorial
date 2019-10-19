# Vivado tutorial
Base code for the HLS tutorial for Bristol.

The code adds two vectors and multiplies them. 
Vector size is set by changing the ```ARRAY_SIZE``` variable in ```HLS_Vectors.h```.

## Setting up Vivado HLS

Run 
```bash
vivado_hls -f VectorSum_setup.tcl
```
to open a Vivado HLS TCL shell of the set up project.

## Doing things with the code

Within the TCL shell run:
 * ```csim``` (shortener of ```csim_design```) to run the C simulation test bench
 * ```csyn``` (shortener of ```csynth_design```) to synthesise the code
 * ```cosim``` (shortener of ```csynth_design```), after having run ```csyn``` successfully, to run the co-simulation test bench 

## Available tags

Three tags are available:
 * ```base```, which is the base code to add and multiply two vector without any optimisation
 * ```cpp_version```, which has optimisation to maximise code throughput
 * ```optimised```, which is a rewriting of the code using a template class for vectors with overloaded operator. It shows that C++ constructs, while simplifying writing code, do not increase latency and resource usage of your design.
## Accessing the synthesis report

Synthesis report are located in ```VivadoTutorial/KU115/syn/report/``` with .rpt extension in human-readable format and with .xml in XML format, useful for automated analysis.
