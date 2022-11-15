module f1_fsm (
    input logic        clk,       // clock
    input logic        rst,       // reset
    input logic        en,        // enable
    input logic        trigger,   // trigger - starts sequence
    output logic       cmd_seq,   // high when we want to increment LEDs
    output logic       cmd_delay, // high when we want to trigger the delay module
    output logic [7:0] data_out,   // LEDs
    output logic reset = 0
);

// state definitions
typedef enum {S0, S1, S2, S3, S4, S5, S6, S7, S8} my_state;
my_state current_state, next_state;

logic triggerSet = 0;

// state transition
always_ff @ (posedge clk, posedge rst)
    if (rst) current_state <= S0;
    else     current_state <= next_state;

// next state logic
always_comb begin
    if (trigger)
        triggerSet = 1;

    case (current_state)
        S0: if (en && triggerSet) begin
            next_state = S1;
            triggerSet = 0;
        end
            else if (next_state != S1)   next_state = current_state;
        S1: if (en) next_state = S2;
            else    next_state = current_state;
        S2: if (en) next_state = S3;
            else    next_state = current_state;
        S3: if (en) next_state = S4;
            else    next_state = current_state;
        S4: if (en) next_state = S5;
            else    next_state = current_state;
        S5: if (en) next_state = S6;
            else    next_state = current_state;
        S6: if (en) next_state = S7;
            else    next_state = current_state;
        S7: if (en) next_state = S8;
            else    next_state = current_state;
        S8: if (en) begin
            next_state = S0;
            reset = 1;
        end
            else    next_state = current_state;
        default: next_state = S0;
    endcase
end

// output logic
always_comb
    case (current_state)
        S0: begin data_out = 8'b0;
            cmd_seq = 1;
            cmd_delay = 0;
            reset = 0;
        end
        S1: begin data_out = 8'b1;
            cmd_seq = 1;
            cmd_delay = 0;
        end
        S2: begin data_out = 8'b11;
            cmd_seq = 1;
            cmd_delay = 0;
        end
        S3: begin data_out = 8'b111;
            cmd_seq = 1;
            cmd_delay = 0;
        end
        S4: begin data_out = 8'b1111;
            cmd_seq = 1;
            cmd_delay = 0;
        end
        S5: begin data_out = 8'b11111;
            cmd_seq = 1;
            cmd_delay = 0;
        end
        S6: begin data_out = 8'b111111;
            cmd_seq = 1;
            cmd_delay = 0;
        end
        S7: begin data_out = 8'b1111111;
            cmd_seq = 1;
            cmd_delay = 0;
        end
        S8: begin data_out = 8'b11111111;
            cmd_seq = 0;
            cmd_delay = 1;
        end
        default: begin
            data_out = 8'b0;
            cmd_seq = 1;
            cmd_delay = 0;
        end
    endcase

endmodule
