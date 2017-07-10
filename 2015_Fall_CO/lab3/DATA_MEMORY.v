`define DM_MAX 128
`define DMSIZE 8
`timescale 1ns/1ps

module DATA_MEMORY(
    clk,
    wea,
    addr,
    din,
    dout
);

input clk, wea;

input [`DMSIZE-1:0] addr;
input [31:0] din;

output [31:0] dout;

reg [`DMSIZE-1:0] addr_reg;

// DM_MAX = how many memory space can use
reg [31:0] data [0:`DM_MAX-1];

assign dout = data[addr_reg];

always@(posedge clk) begin
    addr_reg <= addr[`DMSIZE-1:0];
    if(wea) begin
        data[addr[`DMSIZE-1:0]] <= din;
    end
end

endmodule