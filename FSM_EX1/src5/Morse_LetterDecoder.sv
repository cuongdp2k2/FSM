 module Morse_LetterDecoder #(
    parameter _A = 3'b000 ,
    parameter _B = 3'b001 ,
    parameter _C = 3'b010 ,
    parameter _D = 3'b011 ,
    parameter _E = 3'b100 ,
    parameter _F = 3'b101 ,
    parameter _G = 3'b110 ,
    parameter _H = 3'b111
 ) (
    // input
    input logic [2:0] SW_i  ,
    input logic       _KEY_i ,
    //input logic       _
    //input logic       clk_i ,
    // output
    //output logic _LEDR , _LEDG  , 
    output reg [3:0] _CODE_o    ,
    output reg [2:0] _L_o       
);       
    // typedef enum [2:0] {
    //     _A = 3'b000 ,
    //     _B = 3'b001 ,
    //     _C = 3'b010 ,
    //     _D = 3'b011 ,
    //     _E = 3'b100 ,
    //     _F = 3'b101 ,
    //     _G = 3'b110 ,
    //     _H = 3'b111 
    // } sysCode ;

    // sysCode currentCode ;

    always @( negedge _KEY_i ) begin : Letter_Selection_logic
        case(SW_i)
            _A : begin
                _CODE_o <=  4'b0010 ;
                _L_o    <=  3'b010  ;
            end
            _B : begin
                _CODE_o <=  4'b0001 ;
                _L_o    <=  3'b100  ;
            end
            _C : begin
                _CODE_o <=  4'b0101 ;
                _L_o    <=  3'b100  ;
            end
            _D : begin
                _CODE_o <=  4'b0001 ;
                _L_o    <=  3'b011  ;
            end
            _E : begin
                _CODE_o <=  4'b0000 ;
                _L_o    <=  3'b001  ;
            end
            _F : begin
                _CODE_o <=  4'b0100 ;
                _L_o    <=  3'b100  ;
            end
            _G : begin
                _CODE_o <=  4'b0011 ;
                _L_o    <=  3'b011  ;
            end
            _H : begin
                _CODE_o <=  4'b0000 ;
                _L_o    <=  3'b100  ;
            end
            default: begin
                _CODE_o <= 4'b0000  ;
                _L_o    <= 3'b000   ;
            end
        endcase
    end

endmodule : Morse_LetterDecoder
