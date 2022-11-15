#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vtop.h"

#include "vbuddy.cpp"     // include vbuddy code
#define MAX_SIM_CYC 100000

int main(int argc, char **argv, char **env) {
  int simcyc;     // simulation clock count
  int tick;       // each clk cycle has two ticks for two edges
  int lights = 0; // state to toggle LED lights

  Verilated::commandArgs(argc, argv);
  // init top verilog instance
  Vtop* top = new Vtop;
  // init trace dump
  Verilated::traceEverOn(true);
  VerilatedVcdC* tfp = new VerilatedVcdC;
  top->trace (tfp, 99);
  tfp->open ("top.vcd");
 
  // init Vbuddy
  if (vbdOpen()!=1) return(-1);
  vbdHeader("Lab 3: F1");
  vbdSetMode(1);        // Flag mode set to one-shot

  // initialize simulation inputs
  top->clk = 1;
  top->rst = 0;
  top->n = 42;
  top->trigger = 0;
  
  bool timing = false; // to show we are waiting for user to react
  
  // run simulation for MAX_SIM_CYC clock cycles
  for (simcyc=0; simcyc<MAX_SIM_CYC; simcyc++) {
    // dump variables into VCD file and toggle clock
    for (tick=0; tick<2; tick++) {
      tfp->dump (2*simcyc+tick);
      top->clk = !top->clk;
      top->eval ();
    }

    if (top->reset && !timing) { // happens the instant we reset
      vbdInitWatch();
      timing = true;
    }
    
    if (!timing) {
      // receive button press
      top->trigger = vbdFlag();
    } else if (vbdFlag()) {
      int time = vbdElapsed();
      vbdHex(4, (int(time) >> 16) & 0xF);
      vbdHex(3, (int(time) >> 8) & 0xF);
      vbdHex(2, (int(time) >> 4) & 0xF);
      vbdHex(1, int(time) & 0xF);
      timing = false;
    }

    // display LEDs
    vbdBar(top->data_out & 0xFF); // show 7 bit result on the neopixel strip

    // set up input signals of testbench
    top->rst = (simcyc < 2);    // assert reset for 1st cycle
    vbdCycle(simcyc);

    if (Verilated::gotFinish())  exit(0);
  }

  vbdClose();     // ++++
  tfp->close(); 
  exit(0);
}
