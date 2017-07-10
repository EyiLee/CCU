`define IM_MAX 256
`define IMSIZE 8
`timescale 1ns/1ps

module INSTRUCTION_MEMORY(
    clk,
    wea,
    addr,
    din,
    dout
);

input clk, wea;
input [`IMSIZE-1:0] addr;
input [31:0] din;

output [31:0] dout;

// IM_MAX = how many memory space can use
reg [31:0] instruction [0:`IM_MAX-1];

initial begin
    instruction[0  ] = 32'b001000_00000_00101_00000_00000_000100; //      addi $r5 ,$zero ,4
    instruction[1  ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[2  ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[3  ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[4  ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[5  ] = 32'b001000_00000_11101_00000_00111_110100; //      addi $sp ,$zero ,500
    instruction[6  ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[7  ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[8  ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[9  ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[10 ] = 32'b001000_00000_11111_00000_01000_101000; //      addi $ra ,$zero ,552
    instruction[11 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[12 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[13 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[14 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[15 ] = 32'b101011_11101_11111_00000_00000_000000; //      sw $ra ,0($sp)
    instruction[16 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[17 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[18 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[19 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[20 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[21 ] = 32'b000000_11101_00101_11101_00000_100010; //      sub $sp ,$sp ,$r5
    instruction[22 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[23 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[24 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[25 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[26 ] = 32'b100011_00000_00010_00000_00000_000000; //      lw $r2 ,0($zero)
    instruction[27 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[28 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[29 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[30 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[31 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[32 ] = 32'b100011_00000_00011_00000_00000_000100; //      lw $r3 ,4($zero)
    instruction[33 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[34 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[35 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[36 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[37 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[38 ] = 32'b000100_00000_00011_00000_00001_010110; //  GCD:beq $zero ,$r3 ,L1
    instruction[39 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[40 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[41 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[42 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[43 ] = 32'b000000_00010_00011_00100_00000_101010; //      slt $r4 ,$r2 ,$r3
    instruction[44 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[45 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[46 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[47 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[48 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[49 ] = 32'b000100_00000_00100_00000_00000_100111; //      beq $zero ,$r4 ,D1
    instruction[50 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[51 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[52 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[53 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[54 ] = 32'b000000_00011_00010_00011_00000_100010; //      sub $r3 ,$r3 ,$r2
    instruction[55 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[56 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[57 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[58 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[59 ] = 32'b101011_11101_11111_00000_00000_000000; //      sw $ra ,0($sp)
    instruction[60 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[61 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[62 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[63 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[64 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[65 ] = 32'b000000_11101_00101_11101_00000_100010; //      sub $sp ,$sp ,$r5    // $sp = $r29     // $r5 = 4
    instruction[66 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[67 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[68 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[69 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[70 ] = 32'b000011_00000_00000_00000_00000_100110; //      jal GCD
    instruction[71 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[72 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[73 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[74 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[75 ] = 32'b000000_11101_00101_11101_00000_100000; //      add $sp ,$sp ,$r5
    instruction[76 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[77 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[78 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[79 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[80 ] = 32'b100011_11101_11111_00000_00000_000000; //      lw $ra ,0($sp)
    instruction[81 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[82 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[83 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[84 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[85 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[86 ] = 32'b000000_11111_00000_00000_00000_001000; //      jr $ra
    instruction[87 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[88 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[89 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[90 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[91 ] = 32'b000000_00010_00011_00010_00000_100010; //   D1:sub $r2 ,$r2 ,$r3
    instruction[92 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[93 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[94 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[95 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[96 ] = 32'b101011_11101_11111_00000_00000_000000; //      sw $ra ,0($sp)
    instruction[97 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[98 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[99 ] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[100] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[101] = 32'b000000_11101_00101_11101_00000_100010; //      sub $sp ,$sp ,$r5
    instruction[102] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[103] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[104] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[105] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[106] = 32'b000011_00000_00000_00000_00000_100110; //      jal GCD
    instruction[107] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[108] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[109] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[110] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[111] = 32'b000000_11101_00101_11101_00000_100000; //      add $sp ,$sp ,$r5
    instruction[112] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[113] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[114] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[115] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[116] = 32'b100011_11101_11111_00000_00000_000000; //      lw $ra ,0($sp)
    instruction[117] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[118] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[119] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[120] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[121] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[122] = 32'b000000_11111_00000_00000_00000_001000; //      jr $ra
    instruction[123] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[124] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[125] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[126] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[127] = 32'b101011_00000_00010_00000_00000_001000; //   L1:sw $r2 ,8($zero)
    instruction[128] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[129] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[130] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[131] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[132] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[133] = 32'b000000_11111_00000_00000_00000_001000; //      jr $ra
    instruction[134] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[135] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[136] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[137] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[138] = 32'h00000030; //
    instruction[139] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[140] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[141] = 32'b000000_00000_00000_00000_00000_100000; //
    instruction[142] = 32'b000000_00000_00000_00000_00000_100000; //
end

reg [`IMSIZE-1:0] addr_reg;

// if memory can use, then direct output
assign dout = instruction[addr_reg];

// for outside write instruction
always@(posedge clk) begin
    addr_reg <= addr[`IMSIZE-1:0];
    if(wea) begin
        instruction[addr[`IMSIZE-1:0]] <= din;
    end
end

endmodule
