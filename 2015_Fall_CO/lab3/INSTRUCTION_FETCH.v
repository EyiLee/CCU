`timescale 1ns/1ps
`define IDLE (2'b00)
`define RUN (2'b01)
`include "INSTRUCTION_MEMORY.v"

module INSTRUCTION_FETCH(
    clk,
    rst,
    jump,
    branch,
    jump_addr,
    branch_addr,

    curr_state,

//  haddr,
    ir_write,
    hdin,
    im_out,

    PC,
    IR
);

input clk, rst, jump, branch, ir_write;
input [31:0] jump_addr, branch_addr/*, haddr*/, hdin;
input [1:0] curr_state;

output reg  [31:0] PC, IR;
output [31:0] im_out;
wire [31:0] instruction;

/*================================ MEMORY_INOUTPUT ===============================*/
wire [7:0] address;

assign address = PC[9:2];

assign im_out = instruction;

INSTRUCTION_MEMORY IM(
    .clk(clk),
    .wea(1'b0),
    .addr(address),
    .din(32'b0),
    .dout(instruction)
);

// instructions
always@(posedge clk) begin
    if(rst) begin
        PC <= 32'd0;
        IR <= 32'd0;
    end
    else begin
        PC <= (curr_state == `RUN) ? ((jump) ? jump_addr : ((branch) ? branch_addr : (PC + 4))) : 32'h0;
        IR <= instruction; 
    end
end

endmodule

