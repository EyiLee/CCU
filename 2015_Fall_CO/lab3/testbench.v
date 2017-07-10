`define CYCLE_TIME 20
`define INSTRUCTION_NUMBERS 75 
`timescale 1ns/1ps
`include "CPU.v"

module testbench;
  reg clk, rst, wen;
  reg [31:0] cycles, i, haddr, hdin;
  assign start = (haddr == 32'd3 && !rst) ? 1'b1 : 1'b0;
  wire bsy;
  wire [31:0] dout;

  // clock cycle time is 20ns, inverse Clk value per 10ns
  initial clk = 1'b1;
  always #(`CYCLE_TIME/2) clk = ~clk;

  // rst signal
  initial begin
    cycles = 32'b0;
    rst = 1'b1;
    wen = 1'b0;
    haddr = 32'b0;
    hdin = 32'b0;
    for (i = 0; i < 32; i = i + 1) begin
      cpu.ID.REG[i] = 32'b0;
    end
    for (i = 0; i < 128; i = i + 1) begin
      cpu.MEM.DM.data[i] = 32'b0;
    end
  end
  
  CPU cpu (
    .clk(clk),
    .rst(rst),
    .wen(wen),
    .start(start),
    .haddr(haddr),
    .hdin(hdin),
    .bsy(bsy),
    .dout(dout)
  );

  // display all Register value and Data memory content
  always @(posedge clk) begin
    cycles <= cycles + 1;
    if(cycles == 1) begin
      wen <= 1'b1;
      haddr <= 32'd0;
      hdin <= 32'd49;
      $display("CPU rst: %b", start);
    end
    else if(cycles == 2) begin
      wen <= 1'b1;
      haddr <= 32'd1;
      hdin <= 32'd14;
      $display("CPU rst: %b", start);
    end
    else if(!bsy && cycles == 3) begin
      rst <= 1'b0;
      wen <= 1'b0;
      haddr <= 32'd2;
      $display("CPU start: %b", start);
    end
    else begin
        haddr <= haddr + 1;
    end
    if(cycles >= `INSTRUCTION_NUMBERS && !bsy) begin
      $finish;
    end
    
    if(cycles > 2) begin
      $display("dout: %32b",dout);
      $display("PC: %d cycles: %d busy: %d", (cpu.IF.PC >> 2), cpu.cycles, bsy);
      $display("Instruction: %8h (%32b)", cpu.IF.IR, cpu.IF.IR);
      $display("R00-R07: %08x %08x %08x %08x %08x %08x %08x %08x",
        cpu.ID.REG[0],
        cpu.ID.REG[1],
        cpu.ID.REG[2],
        cpu.ID.REG[3],
        cpu.ID.REG[4],
        cpu.ID.REG[5],
        cpu.ID.REG[6],
        cpu.ID.REG[7]);
      // $display("R08-R15: %08x %08x %08x %08x %08x %08x %08x %08x",
        // cpu.ID.REG[8],
        // cpu.ID.REG[9],
        // cpu.ID.REG[10],
        // cpu.ID.REG[11],
        // cpu.ID.REG[12],
        // cpu.ID.REG[13],
        // cpu.ID.REG[14],
        // cpu.ID.REG[15]);
      // $display("R16-R23: %08x %08x %08x %08x %08x %08x %08x %08x",
        // cpu.ID.REG[16],
        // cpu.ID.REG[17],
        // cpu.ID.REG[18],
        // cpu.ID.REG[19],
        // cpu.ID.REG[20],
        // cpu.ID.REG[21],
        // cpu.ID.REG[22],
        // cpu.ID.REG[23]);
      $display("R24-R31: %08x %08x %08x %08x %08x %08x %08x %08x",
        cpu.ID.REG[24],
        cpu.ID.REG[25],
        cpu.ID.REG[26],
        cpu.ID.REG[27],
        cpu.ID.REG[28],
        cpu.ID.REG[29],
        cpu.ID.REG[30],
        cpu.ID.REG[31]);
      $display("0x00   : %08x %08x %08x %08x %08x %08x %08x %08x",
        cpu.MEM.DM.data[0],
        cpu.MEM.DM.data[1],
        cpu.MEM.DM.data[2],
        cpu.MEM.DM.data[3],
        cpu.MEM.DM.data[4],
        cpu.MEM.DM.data[5],
        cpu.MEM.DM.data[6],
        cpu.MEM.DM.data[7]);
      $display("0x08   : %08x %08x %08x %08x %08x %08x %08x %08x",
        cpu.MEM.DM.data[8],
        cpu.MEM.DM.data[9],
        cpu.MEM.DM.data[10],
        cpu.MEM.DM.data[11],
        cpu.MEM.DM.data[12],
        cpu.MEM.DM.data[13],
        cpu.MEM.DM.data[14],
        cpu.MEM.DM.data[15]);
      $display("Stack:");
      $display("0x66   : %08x %08x %08x %08x %08x %08x %08x %08x",
        cpu.MEM.DM.data[104],
        cpu.MEM.DM.data[105],
        cpu.MEM.DM.data[106],
        cpu.MEM.DM.data[107],
        cpu.MEM.DM.data[108],
        cpu.MEM.DM.data[109],
        cpu.MEM.DM.data[110],
        cpu.MEM.DM.data[111]);
      $display("0x70   : %08x %08x %08x %08x %08x %08x %08x %08x",
        cpu.MEM.DM.data[112],
        cpu.MEM.DM.data[113],
        cpu.MEM.DM.data[114],
        cpu.MEM.DM.data[115],
        cpu.MEM.DM.data[116],
        cpu.MEM.DM.data[117],
        cpu.MEM.DM.data[118],
        cpu.MEM.DM.data[119]);
      $display("0x78   : %08x %08x %08x %08x %08x %08x %08x %08x",
        cpu.MEM.DM.data[120],
        cpu.MEM.DM.data[121],
        cpu.MEM.DM.data[122],
        cpu.MEM.DM.data[123],
        cpu.MEM.DM.data[124],
        cpu.MEM.DM.data[125],
        cpu.MEM.DM.data[126],
        cpu.MEM.DM.data[127]);
    end
  end
endmodule

