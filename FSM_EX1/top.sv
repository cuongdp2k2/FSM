module top (
    // input 
    input logic      clk_i ,
    input logic [2:0] SW       ,
    input logic [3:0] KEY      ,

    // output
    output logic [2:0] LEDR    ,
    output logic [3:0] LEDG     
);
	Morse_Machine dut(
    .CLOCK_50 (clk_i) ,
    .SW  (SW)     ,
    .KEY (KEY)     ,
    .LEDR (LEDR)   ,
    .LEDG (LEDG)    
);
	 
endmodule : top
