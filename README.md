# Signal Generator on FPGA

The project is a signal generator based on Xilinx's Nexy4 FPGA development board, using vivado as the development tool. Hardware platform is built by creating block design using IP cores in vivado. Software modules are implemented in C.

Nexy4 FPGA-based signal generators can generate sawtooth, triangle, sine and square waves. The type, frequency and amplitude of the signal can be real-time displayed on a seven-band digital tube. The signal type and the frequency and amplitude of the signal can be controlled by 16-bit switches. 

## Hardware design

<p align="center">
<img src="https://github.com/UniqueMR/Signal-Generator-on-FPGA/blob/main/images/hardware.png" width=75% height=75%>
</p>
The hardware platform includes a microblaze microprocessor, local registers, interrupt controller, timer, 3 GPIO cores, 2 UART bus modules, and 2 SPI bus modules. Those individual modules are connected to the microprocessor via the AXI bus. Interrputs can be generated by timers, GPIO cores, UART bus modules, and SPI bus modules. The 16-bit switch control logic is input through the GPIO core.  The state of the switch, and the segment code and bit code of the 7-segment digital tube are also output by the GPIO core. The generated waveform digital signal is output via the SPI bus and then converted to analog signal by the DA conversion module. 

## Software design

The main function of the program completes the initialization and interrput enablement of the GPIO, timer and SPI bus module. It also sets the interrupt mode to hardware interrput, allowing the microprocessor to accept the interrput request and start the SPI transmission. The main interrput service program is supposed to read the interrput state and the switch state in order to select the interrput service program and obtain the corresponding control signal. Wave generation modules are designed as interrput service routines to generate different forms of wave according to the waveform selection signal and adjust the frequency, amplitude and duty cycle corresponded to the control signal. 

## Note

- Since the C version of the vivado SDK does not support calling functions by reference, for the convenience of writing programs, the C++ compiler is used to compile the project. The program is still written in the C style.
- This project is based on the experimental course of Analog Circuits and Digital Systems (III) of Huazhong University of Science and Technology. For more resources, please refer to the textbooks and MOOCs.
