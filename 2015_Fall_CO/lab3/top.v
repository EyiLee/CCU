`timescale 1ns / 1ps
`include "CPU.v"

module top(
    input clk,
    input rst,
    input i0,
    input i1,
    input i2,
    input i3,
    input i4,
    input i5,
    input i6,
    input i7,
    
    input j0,
    input j1,
    input j2,
    input j3,
    input j4,
    input j5,
    input j6,
    input j7,

    output a,
    output b,
    output c,
    output d,
    output e,
    output f,
    output g,
    
    output an0,
    output an1,
    output an2,
    output an3,
    output an4,
    output an5,
    output an6,
    output an7,
    
    output bbsy
);

reg [2:0] count_div8;
reg [31:0] count;
reg [6:0] answer;
reg [7:0] an;
reg [6:0] seg [0:9];
wire [31:0] dout;
wire [31:0] data;

wire [31:0] datain;
assign bbsy = bsy;
assign datain = (count == 32'd0) ? {{24'd0} ,i7 ,i6 ,i5 ,i4 ,i3 ,i2 ,i1 ,i0} : {{24'd0} ,j7 ,j6 ,j5 ,j4 ,j3 ,j2 ,j1 ,j0};
assign CLK_1M = count_div8[2];
assign start_run = (count == 32'd3 && !rst) ? 1'b1 : 1'b0;   
assign {g,f,e,d,c,b,a} = answer[6:0];
assign wen = (count == 32'd0 || count == 32'd1);
assign {an7,an6,an5,an4,an3,an2,an1,an0} = an;

CPU cpu (
  .clk(CLK_1M),
  .rst(rst),
  .wen(wen),
  .start(start_run),
  .haddr(count),
  .hdin(datain),
  .bsy(bsy),
  .dout(dout)
);

initial begin
    seg[0] = 7'b1000000;//h40;//8'hc0;
    seg[1] = 7'b1111001;//h79;//8'hf9;
    seg[2] = 7'b0100100;//h24;//8'ha4;
    seg[3] = 7'b0110000;//h30;//8'hb0;
    seg[4] = 7'b0011001;//h19;//8'h99;
    seg[5] = 7'b0010010;//h12;//8'h92;
    seg[6] = 7'b0000010;//h02;//8'h82;
    seg[7] = 7'b1111000;//h78;//8'hf8;
    seg[8] = 7'b0000000;//h00;//8'h80;
    seg[9] = 7'b0010000;//h10;//8'h90;  
end

always@(posedge clk) begin
    if(rst) begin
        count_div8 <= 3'b000;
    end
    else if (count_div8 == 3'b111) begin
        count_div8 <= 3'b000;
    end
    else begin
        count_div8 <= count_div8 + 3'b001;
    end
end

always@(posedge CLK_1M) begin
    if(rst) begin
        count <= 32'd0;
    end
    else begin
        if(count < 32'd33554432 && !bsy) begin
            count <= count + 32'd1;
        end
        else if ( count < 32'd33554432 && bsy) begin
            count <= count;
        end
        else begin
            count <= 32'd0;
        end
    end
end

always@(posedge clk) begin
    if(!bsy) begin
        case(count[15:14])
            2'b00: begin
                answer <= seg[dout%10];
                an <= 8'b11111110;
            end
            2'b01: begin
                answer <= seg[(dout%100)/10];
                an <= 8'b11111101;
            end
            2'b10: begin
                answer <= seg[(dout%1000)/100];
                an <= 8'b11111011;
            end
            2'b11: begin
                answer <= seg[(dout%10000)/1000];
                an <= 8'b11110111;
            end
        endcase
    end
end

endmodule