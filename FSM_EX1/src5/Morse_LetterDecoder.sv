module Morse_LetterDecoder (
    // input
    input logic [2:0] SW_i  ,
    input logic       _KEY_i ,
    //input logic       _
    //input logic       clk_i ,
    // output
    //output logic _LEDR , _LEDG  , 
    output logic [3:0] _CODE_o    ,
    output logic [2:0] _L_o       
);
    reg [3:0] _CODE ;
    reg [2:0] _L    ;

    assign _CODE_o = _CODE ;
    assign _L_o    = _L    ;         

    always @( posedge _KEY_i ) begin : Letter_Selection_logic
            _CODE[3] <= 0                                                                                                    ;
            _CODE[2] <= (~SW_i[2] & SW_i[1] & ~SW_i[0]) | (SW_i[2] & ~SW_i[1] & SW_i[0])                                     ;
            _CODE[1] <= (~SW_i[2] & ~SW_i[1] & ~SW_i[0]) | (SW_i[2] & SW_i[1] & ~SW_i[0])                                    ;
            _CODE[0] <= (~SW_i[2] & SW_i[0]) | (SW_i[1] & ~SW_i[0])                                                          ;
            _L[2]    <= (~SW_i[1] & SW_i[0]) | (~SW_i[2] & SW_i[1] & ~SW_i[0]) | (SW_i[2] & SW_i[0])                         ;
            _L[1]    <= (~SW_i[2] & ~SW_i[1] & ~SW_i[0]) | (~SW_i[2] & SW_i[1] & SW_i[0]) | (SW_i[2] & SW_i[1] & ~SW_i[0])   ;
            _L[0]    <= (~SW_i[2] & SW_i[1] & SW_i[0]) | (SW_i[2] & ~SW_i[0])                                                ;
    end

endmodule : Morse_LetterDecoder
