module lfsr (
    input logic        clk,     // clock
    input logic        rst,     // reset
    input logic        en,      // enable
    output logic [6:0] data_out // pseudo-random output
);

logic [6:0] sreg; //shift register

always_ff @ (posedge clk, posedge rst)
    if (rst)
        sreg <= 7'b1;
    else if (en) begin
        sreg <= {sreg[5:0], sreg[2] ^ sreg[6]}; // bits 3 and 7 XORd for LSB
    end

    assign data_out = sreg;

endmodule
