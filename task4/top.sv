module top #(
	parameter WIDTH = 16,
    parameter PRBS_WIDTH = 7
)(
    input logic             clk,       // clock
    input logic             rst,       // reset
    input logic             trigger,
    input logic [WIDTH-1:0] n,         // value of N for clktick
    output logic [7:0]      data_out,   // data assigned to the LEDs
    output logic reset
);

    wire cmd_seq;   // high when increasing LEDs
    wire cmd_delay; // triggers delay
    wire tick; // 1 second pulse
    wire [PRBS_WIDTH-1:0] delayCycles;
    logic fsmEn;
    wire delayPulse;
    wire clockTick;

always_ff @ (posedge clk)
    case (cmd_seq) // multiplexer
        0: fsmEn = delayPulse;
        1: fsmEn = clockTick;
    endcase

f1_fsm f1 (
    .clk (clk),
    .rst (rst),
    .en (fsmEn),
    .trigger (trigger),
    .cmd_seq (cmd_seq),
    .cmd_delay (cmd_delay),
    .data_out (data_out),
    .reset (reset)
);

clktick clock_tick (
    .clk (clk),
    .rst (rst),
    .en (cmd_seq),
    .N (n),     // calibrated to provide 1s ticks
    .tick (clockTick) // 1 tick every second
);

lfsr myLfsr (
    .clk (clk),
    .rst (rst),
    .en (1'b1),   // generates next random delay on each en pulse - must be running constantly otherwise we have the same delay from each call
    .data_out (delayCycles) // number of cycles delay
);

delay myDelay (
    .clk (clk),
    .rst (rst),
    .trigger (cmd_delay),
    .n (delayCycles),
    .time_out(delayPulse) // 1 after appropriate delay
);

endmodule
