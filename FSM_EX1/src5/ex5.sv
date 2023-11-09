module ex5 (
    // input
    input logic [2:0] SW_i  ,
    input logic       _KEY1 ,
    input logic       clk_i ,
    // output
    //output logic _LEDR , _LEDG  , 
    output reg [3:0] _CODE    ,
    output reg [2:0] _L       
);
    always @( posedge clk_i ) begin 
        if(_KEY1) begin
            _CODE[3] <= 0                                                                                                    ;
            _CODE[2] <= (~SW_i[2] & SW_i[1] & ~SW_i[0]) | (SW_i[2] & ~SW_i[1] & SW_i[0])                                     ;
            _CODE[1] <= (~SW_i[2] & ~SW_i[1] & ~SW_i[0]) | (SW_i[2] & SW_i[1] & ~SW_i[0])                                    ;
            _CODE[0] <= (~SW_i[2] & SW_i[0]) | (SW_i[1] & ~SW_i[0])                                                          ;
            _L[2]    <= (~SW_i[1] & SW_i[0]) | (~SW_i[2] & SW_i[1] & ~SW_i[0]) | (SW_i[2] & SW_i[0])                         ;
            _L[1]    <= (~SW_i[2] & ~SW_i[1] & ~SW_i[0]) | (~SW_i[2] & SW_i[1] & SW_i[0]) | (SW_i[2] & SW_i[1] & ~SW_i[0])   ;
            _L[0]    <= (~SW_i[2] & SW_i[1] & SW_i[0]) | (SW_i[2] & ~SW_i[0])                                                ;
        end
    end

endmodule : ex5
