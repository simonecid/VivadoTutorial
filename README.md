# Vivado tutorial
Base code for the HLS tutorial for Bristol

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

## Accessing the synthesis report

Synthesis report are located in ```VivadoTutorial/KU115/syn/report/``` with .rpt extension in human-readable format and with .xml in XML format, useful for automated analysis.