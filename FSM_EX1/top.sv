module top (
    // input
    input logic [2:0] SW_i  ,
    input logic       _KEY1 ,
    input logic       clk_i ,
    // output
    //output logic _LEDR , _LEDG  , 
    output logic [3:0] _CODE_o    ,
    output logic [2:0] _L_o       
);
	ex5 dut(
		.*
	);
	 
endmodule : top
