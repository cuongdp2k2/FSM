/* verilator lint_off UNUSED */
module Morse_Machine(
    // input 
    input logic       CLOCK_50 ,
    input logic [2:0] SW       ,
    input logic [3:0] KEY      ,

    // output
    output logic [2:0] LEDR    ,
    output logic [3:0] LEDG    
);

    assign LEDG[3] = KEY[0] ;

    // Wire Declearation
    logic [3:0] MorseCharacter_wire ;
    logic [2:0] MorseLength_wire    ;
    logic       timeCounter_wire    ;

    Morse_LetterDecoder CODE_GENERATER (
        // input
        .SW_i (SW) ,
        ._KEY_i(KEY[0]) ,

        // output
        ._CODE_o(MorseCharacter_wire) ,
        ._L_o(MorseLength_wire)
    ) ;

    Morse_FSM FSM (
        // input
        .MorseCharacter_i (MorseCharacter_wire) ,
        .MorseLength_i    (MorseLength_wire) ,
        .timeCounter_i    (timeCounter_wire) ,
        .pushButton_i     (KEY[0]) ,
        
        // output
        .dotLed_o         (LEDG[2]) ,
        .dashLed_o        (LEDG[1]) ,
        .doneLed_o        (LEDG[0]) 
    ) ;

    HalfSec_Counter timeCounter(
        // input
        .CLOCK50_i (CLOCK_50) ,
    // ouput
        .timeCounter_o (timeCounter_wire)
    );

    assign LEDR = SW ; 

endmodule : Morse_Machine
