module top #(
	parameter WIDTH = 16
)(
    input logic             clk, // clock
    input logic             rst, // reset
    input logic             en,  // enable
    input logic [WIDTH-1:0] N,   // value of N for clktick
    output logic [7:0]      data_out // pseudo-random output
);

    wire tick; // 1 second pulse

f1_fsm f1 (
    .clk (tick),
    .rst (rst),
    .en (en),
    .data_out (data_out)
);

clktick clock_tick (
    .clk (clk),
    .rst (rst),
    .en (en),
    .N (N),
    .tick (tick)
);

endmodule
