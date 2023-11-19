module Morse_FSM (
    // input
    input logic [3:0] MorseCharacter_i ,
    input logic [2:0] MorseLength_i    ,
    input logic       timeCounter_i    ,
    input logic       pushButton_i     ,

    // output
    output reg        dotLed_o         ,
    output reg        dashLed_o        ,
    output reg        processLed_o     ,
    output reg        doneLed_o        
) ;
    logic [3:0] MorseCharacter_wire ;
    logic [2:0] MorseLength_wire    ;

    reg [3:0] MorseCharacter_reg ;
    reg [2:0] MorseLength_reg    ;
    reg       sysProcessing_Flag ;
    reg [3:0] codeShift_reg      ;
    reg [2:0] lengthCounter_reg  ;

    assign MorseCharacter_wire = (sysProcessing_Flag) ? codeShift_reg : MorseCharacter_reg  ;
    assign MorseLength_wire    = (sysProcessing_Flag) ? lengthCounter_reg : MorseLength_reg ;
    assign processLed_o        = sysProcessing_Flag  ;
    assign sysProcessing_Flag  = (lengthCounter_reg != 0) ;
    assign doneLed_o           = ~sysProcessing_Flag      ;

    always @( negedge pushButton_i ) begin : Store_New_Data
        MorseCharacter_reg <= MorseCharacter_i ;
        MorseLength_reg    <= MorseLength_i    ;
    end
    
    always @( posedge timeCounter_i ) begin : Process_output
        dotLed_o           <= ~MorseCharacter_wire[0]  ;
        dashLed_o          <= MorseCharacter_wire[0]   ;
        
        codeShift_reg      <= MorseCharacter_wire >> 1 ;
        lengthCounter_reg  <= MorseLength_wire - 1     ; 
    end


endmodule : Morse_FSM
