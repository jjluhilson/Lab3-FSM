#include "Vf1_fsm.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp"

int main (int argc, char **argv, char **env) {
    int i; //counts the number of clock cycles to simulate (used in for loop)
    int clk; //clock signal

    Verilated::commandArgs(argc, argv);
    //init top verilog instance
    Vf1_fsm* top = new Vf1_fsm; //instantiate the counter module as Vlsfr - name of all generated files. This is the DUT
    //init trace dump
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC; //vcdC is the data type we use for the trace file pointer
    top->trace (tfp, 99);
    tfp->open ("f1_fsm.vcd"); //dump the waveform data to lfsr.vcd
    
    //init vbuddy - port path is in vbuddy.cfg
    if (vbdOpen() != 1) return(-1); //open vbd port, if not found then exit with error code
    vbdHeader("Lab 3: F1");

    //initalize simulation inputs
    top->clk = 1; //top is the name of the top level entity. Only top level signals are visible
    top->rst = 1;
    top->en = 0;

    vbdSetMode(1); //one-shot mode

    //run simulation for many clock cycles
    for (i = 0; i < 100000; i++) {

        //dump variables into VCD file and toggle clock
        for (clk = 0; clk < 2; clk++) { //for loop that toggles the clock, also outputs trace for each half of the clock cycle. Forces model to evaluate on both edges of the clock
            tfp->dump (2*i + clk); //unit is in picoseconds!
            top->clk = !top->clk;
            top->eval (); //simulates clock cycle in verilator
        }
        
        // show data on Vbuddy
        vbdHex(1, top->data_out & 0xF); // four bit output of random sequence
        vbdHex(2, top->data_out >> 4 & 0xF); // next 3 bits
        vbdBar(top->data_out & 0xFF); // show 7 bit result on the neopixel strip
        vbdCycle(i+1);

        //we change the rst and en signals throughout the simulation
        top->rst = 0;
        top->en = vbdFlag(); // enabled each time encoder pressed

         // either simulation finished, or 'q' is pressed
        if ((Verilated::gotFinish())) 
            exit(0); // ... exit if finished
        }

    vbdClose();
    tfp->close();
    exit(0);
}