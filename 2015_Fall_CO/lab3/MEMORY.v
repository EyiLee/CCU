`timescale 1ns/1ps
`include "DATA_MEMORY.v"

module MEMORY(
    clk,
    rst,
    XM_MemtoReg,
    XM_RegWrite,
    XM_MemRead,
    XM_MemWrite,
    ALUout,
    XM_RD,
    XM_MD,


    bsy,
    haddr,
    dm_write,
    hdin,
    dm_out,

    MW_MemtoReg,
    MW_RegWrite,
    MW_ALUout,
    MDR,
    MW_RD
);

input clk, rst, XM_MemtoReg, XM_RegWrite, XM_MemRead, XM_MemWrite, dm_write;
input bsy;

input [31:0] ALUout ,XM_MD ,hdin ,haddr;
input [4:0] XM_RD;

output reg MW_MemtoReg, MW_RegWrite;
output reg [31:0] MW_ALUout;
output reg [4:0] MW_RD;
output [31:0] MDR, dm_out;
wire write_en;

/*================================ MEMORY_INOUTPUT ===============================*/
wire [7:0] address;
wire [31:0] din;

assign address = (haddr == 32'd0) ? 8'd0 : (haddr == 32'd1) ? 8'd1 : (bsy) ? ALUout[9:2] : (haddr[24:23] <= 2'b01) ? {{6'd0} ,haddr[24:23]} : {8'd2};
assign din     = (haddr <= 32'd1) ? hdin : XM_MD;

assign dm_out = MDR;

assign write_en = (!XM_MemRead && XM_MemWrite) || dm_write;

DATA_MEMORY DM(
    .clk(clk),
    .wea(write_en),
    .addr(address),
    .din(din),
    .dout(MDR)
);

always@(posedge clk) begin
    if (rst) begin
        MW_MemtoReg <= 1'b0;
        MW_RegWrite <= 1'b0;
    end
    else begin
        MW_MemtoReg <= XM_MemtoReg;
        MW_RegWrite <= XM_RegWrite;
        MW_ALUout   <= ALUout;
        MW_RD       <= XM_RD;
    end
end

endmodule